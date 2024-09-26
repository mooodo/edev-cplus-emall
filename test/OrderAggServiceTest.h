#pragma once

#include <iostream>
#include <cassert>
#include "../order/OrderAggService.h"
#include "../order/OrderService.h"
#include "../order/PaymentService.h"
using namespace std;

// 测试提交订单
void testPlaceOrder() {
    
    Order *order = new Order();
    long id = 1;
    order->setId(id);
    order->customerId = 10001;
    order->addressId = 1000101;

    OrderItem *item0 = new OrderItem();
    item0->setId(10);
    item0->productId = 20001;
    item0->quantity = 2;
    order->items.push_back(item0);

    OrderItem *item1 = new OrderItem();
    item1->setId(20);
    item1->productId = 20002;
    item1->quantity = 1;
    order->items.push_back(item1);

    OrderAggService::placeOrder(order);

    Order *placedOrder = OrderService::load(1);
    assert(placedOrder!=nullptr);
    cout << "place an order:" << endl;
    placedOrder->print();
}

// 测试取消订单
void testCancelOrder() {
    OrderAggService::cancelOrder(1);
    assert(OrderService::load(1)==nullptr);
}

// 测试支付订单
void testPayoffForTheOrder() {
    OrderAggService::payoff(1);

    cout << "payoff for the order:" << endl;
    Order * order = OrderService::load(1);
    assert(order!=nullptr && order->status=="payoff");
    order->print();

    Payment * payment = PaymentService::check(1);
    assert(payment!=nullptr && payment->status=="payoff");
    payment->print();
}

// 测试退货
void testReturnGoods() {
    OrderAggService::returnGoods(1);

    cout << "return goods for the order:" << endl;
    Order * order = OrderService::load(1);
    assert(order!=nullptr && order->status=="return goods");
    order->print();

    Payment * payment = PaymentService::check(1);
    assert(payment!=nullptr && payment->status=="refund");
    payment->print();
}

// 主测试函数
void testOrderAggService() {
    cout << ">>>OrderAggService: begin test" << endl;
    testPlaceOrder();
    testCancelOrder();
    testPlaceOrder();
    testPayoffForTheOrder();
    testReturnGoods();
    cout << ">>>OrderAggService: All tests passed!" << endl;
}