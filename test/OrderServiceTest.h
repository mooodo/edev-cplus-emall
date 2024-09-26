#pragma once

#include <iostream>
#include <cassert>
#include "../order/OrderService.h"
using namespace std;

// 测试创建新订单
void testCreateOrder() {
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
    
    long newOrderId = OrderService::create(order);
    assert(newOrderId == 1);
    Order *createdOrder = OrderService::load(newOrderId);
    assert(createdOrder != nullptr);
    cout << "create an order:" << endl;
    createdOrder->print();
}

// 测试客户修改自己的订单
void testModifyOrder() {
    Order *order = OrderService::load(1);
    order->status = "ready";
    OrderService::modify(order);

    Order *modifiedOrder = OrderService::load(1);
    cout << "modify an order:" << endl;
    modifiedOrder->print();
    assert(modifiedOrder->status == "ready");
}

// 测试客户删除自己的订单
void testRemoveOrder() {
    OrderService::remove(1);
    assert(OrderService::load(1) == nullptr);
}

// 主测试函数
void testOrderService() {
    cout << ">>>OrderService: begin test" << endl;
    testCreateOrder();
    testModifyOrder();
    testRemoveOrder();
    cout << ">>>OrderService: All tests passed!" << endl;
}