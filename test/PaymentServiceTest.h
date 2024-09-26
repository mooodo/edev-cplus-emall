#pragma once

#include <iostream>
#include <cassert>
#include "../order/PaymentService.h"
#include "../support/DateUtils.h"
using namespace std;

// 测试支付订单的金额
void testPayoff() {
    Payment *payment = new Payment();
    payment->setId(1);
    payment->amount = 1000;
    payment->method = "alipay";
    payment->status = "payoff";
    payment->paymentTime = DateUtils::getNow();
    PaymentService::payoff(payment);

    Payment* checkedPayment = PaymentService::check(1);
    assert(checkedPayment != nullptr);
    assert(checkedPayment->status == "payoff");
    cout << "pay for an order:" << endl;
    checkedPayment->print();
}

// 测试退货时进行退款
void testRefund() {
    Payment* payment = PaymentService::check(1);
    PaymentService::refund(payment);

    Payment* checkedPayment = PaymentService::check(1);
    assert(checkedPayment != nullptr);
    assert(checkedPayment->status == "refund");
    cout << "refund for the order:" << endl;
    checkedPayment->print();
}

// 主测试函数
void testPaymentService() {
    cout << ">>>PaymentService: begin test" << endl;
    testPayoff();
    testRefund();
    cout << ">>>PaymentService: All tests passed!" << endl;
}