#include "OrderService.h"
#include "../customer/CustomerService.h"
#include "../product/ProductService.h"
#include "../support/Repository.hpp"
#include "../support/ValidException.h"
#include "../support/DateUtils.h"

using namespace std;

void valid(Order* order) {
    if(order->customerId == 0) throw new ValidException("客户编号不能为空");
    if(order->addressId == 0) throw new ValidException("收货地址不能为空");
    if(!CustomerService::exists(order->customerId)) throw new ValidException("客户不存在");
    if(!CustomerService::existsAddress(order->addressId)) throw new ValidException("收货地址不存在");
}

void sumOfAmount(Order* order) {
    double amount = 0;
    for(OrderItem *item : order->items) {
        Product *product = ProductService::load(item->productId);
        if(product==NULL) throw new ValidException("该商品不存在");
        item->orderId = order->id;
        item->price = product->price;
        item->amount = item->price * item->quantity;
        amount += item->amount;
    }
    order->amount = amount;
}

// 创建新的订单
long OrderService::create(Order* order) {
    valid(order);
    sumOfAmount(order);
    order->id = Repository<Order, long>::nextId();
    order->status = "create";
    order->orderTime = DateUtils::getNow();
    return Repository<Order, long>::insert(order);
}

// 客户修改自己的订单
void OrderService::modify(Order* order) {
    valid(order);
    sumOfAmount(order);
    order->modifyTime = DateUtils::getNow();
    Repository<Order, long>::update(order);
}

// 客户删除自己的订单
void OrderService::remove(long orderId) {
    Repository<Order, long>::remove(orderId);
}

// 查找订单
Order* OrderService::load(long orderId) {
    return Repository<Order, long>::load(orderId);
}