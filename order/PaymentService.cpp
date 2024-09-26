#include "PaymentService.h"
#include "../support/Repository.hpp"
using namespace std;

// 支付订单的金额
void PaymentService::payoff(Payment* payment) {
    payment->status = "payoff";
    Repository<Payment, long>::insert(payment);
}

// 退货时进行退款
void PaymentService::refund(Payment* payment) {
    payment->status = "refund";
    Repository<Payment, long>::update(payment);
}

// 检查订单的支付情况
Payment* PaymentService::check(long paymentId) {
    return Repository<Payment, long>::load(paymentId);
}