#ifndef PAYMENT_SERVICE_H
#define PAYMENT_SERVICE_H

#include "Order.h"

using namespace std;

// 支付服务（PaymentService）
class PaymentService {
public:
    // 支付订单的金额
    static void payoff(Payment* payment);
    // 退货时进行退款
    static void refund(Payment* payment);
    // 检查订单的支付情况
    static Payment* check(long paymentId);
};

#endif // PAYMENT_SERVICE_H