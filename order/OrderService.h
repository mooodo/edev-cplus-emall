#ifndef ORDER_SERVICE_H
#define ORDER_SERVICE_H

#include "Order.h"

using namespace std;

// 订单服务（OrderService）
class OrderService {
public:
    // 创建新的订单
    static long create(Order* order);
    // 客户修改自己的订单
    static void modify(Order* order);
    // 客户删除自己的订单
    static void remove(long orderId);
    // 查找订单
    static Order* load(long orderId);
};

#endif // ORDER_SERVICE_H