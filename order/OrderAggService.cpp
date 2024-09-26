#include "OrderAggService.h"
#include "OrderService.h"
#include "PaymentService.h"
#include "../inventory/InventoryService.h"
#include "../support/ValidException.h"
#include "../support/DateUtils.h"
using namespace std;

// 提交订单
void OrderAggService::placeOrder(Order* order) {
    OrderService::create(order);
}

// 支付订单金额
void OrderAggService::payoff(long orderId) {
    Order *order = OrderService::load(orderId);
    if(order==NULL) throw new ValidException("该订单不存在");
    if(order->status!="create") throw new ValidException("该订单已经支付过了");

    Payment *payment = new Payment();
    payment->setId(orderId);
    payment->amount = order->amount;
    payment->method = "alipay";
    payment->status = "payoff";
    payment->paymentTime = DateUtils::getNow();
    PaymentService::payoff(payment);

    for(OrderItem *item : order->items) 
        InventoryService::stockOut(item->productId, item->quantity);
    
    order->status = "payoff";
    order->payment = payment;
    OrderService::modify(order);
}

// 取消订单
void OrderAggService::cancelOrder(long orderId) {
    Order *order = OrderService::load(orderId);
    if(order==NULL) throw new ValidException("该订单不存在");
    if(order->status!="create") throw new ValidException("该订单已经支付了就不能被取消");
    OrderService::remove(orderId);
}

// 退货
void OrderAggService::returnGoods(long orderId) {
    Order *order = OrderService::load(orderId);
    if(order==NULL) throw new ValidException("该订单不存在");
    if(order->status!="payoff") throw new ValidException("该订单的状态不能退货");
    PaymentService::refund(order->payment);
    for(OrderItem *item : order->items)
        InventoryService::stockIn(item->productId, item->quantity);
    
    order->status = "return goods";
    OrderService::modify(order);
}