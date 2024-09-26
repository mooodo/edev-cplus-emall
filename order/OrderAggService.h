#ifndef ORDER_AGG_SERVICE_H
#define ORDER_AGG_SERVICE_H

#include "Order.h"

using namespace std;
// 订单聚合服务（OrderAggService）
class OrderAggService {
public:
    // 提交订单，提交以后就开始进入支付流程
    static void placeOrder(Order* order);
    // 在没有提交订单前取消订单
    static void cancelOrder(long orderId);
    // 支付订单金额，完成支付以后将库存扣减，并进入物流流程
    static void payoff(long orderId);
    // 在支付订单以后退货
    static void returnGoods(long orderId);
};

#endif // ORDER_AGG_SERVICE_H