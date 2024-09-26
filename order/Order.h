#ifndef ORDER_H
#define ORDER_H
#include <string>
#include <vector>
#include <ctime>
#include "../customer/Customer.h"
#include "../product/Product.h"
#include "../support/Repository.hpp"
using namespace std;

// 订单明细（OrderItem）领域对象
struct OrderItem : Entity<long> {
    long id;                // 订单明细ID
    long orderId;           // 所属订单的ID
    long productId;         // 关联的商品ID
    long quantity;          // 商品的数量
    double price;           // 商品的单价
    double amount;          // 该商品项的金额
    Product *product;        // 商品信息
    void print() {
        cout << "  {" << endl;
        cout << "  id: " << getId()
        << ", orderId: " << orderId
        << ", productId: " << productId
        << ", quantity: " << quantity
        << ", price: " << price
        << ", amount: " << amount << endl;
        if (product!=nullptr) {
            cout << "  , product:" << endl;
            product->print();
        }
        cout << "  }" << endl;
    }
};

// 支付（Payment）领域对象
struct Payment : Entity<long> {
    long id;                // 支付ID
    double amount;          // 应付金额
    string method;          // 支付方式，如信用卡、PayPal、银行转账等
    string status;          // 支付状态，如待支付、支付成功、支付失败
    time_t paymentTime;     // 支付完成的时间
    void print() {
        cout << "  { id: " << getId()
        << ", amount: " << amount
        << ", method: " << method
        << ", status: " << status
        << ", paymentTime: " << paymentTime << " }" << endl;
    }
};

// 订单（Order）领域对象
struct Order : Entity<long> {
    long id;                // 订单ID
    long customerId;        // 订单所属客户的ID
    long addressId;         // 订单送货地址的ID
    string status;          // 订单状态
    double amount;     // 订单总金额
    time_t orderTime;       // 下单时间
    time_t modifyTime;      // 订单最后修改时间
    Customer *customer;      // 订单所属客户
    Address *address;        // 订单送货地址
    Payment *payment;        // 订单的支付
    vector<OrderItem*> items; // 订单包含的商品明细列表
    void print() {
        cout << "  {" << endl;
        cout << "  id: " << getId()
        << ", customerId: " << customerId
        << ", addressId: " << addressId
        << ", status: " << status
        << ", amount: " << amount
        << ",\n  orderTime: " << orderTime
        << ", modifyTime: " << modifyTime << endl;
        if (customer!=nullptr) {
            cout << "  , customer:" << endl;
            customer->print();
        }
        if (address!=nullptr) {
            cout << "  , address:" << endl;
            address->print();
        }
        if (payment!=nullptr) {
            cout << "  , payment:" << endl;
            payment->print();
        }
        if (!items.empty()) {
            cout << "  , items: [" << endl;
            for (OrderItem* item : items) 
                if (item != nullptr) item->print();
            cout << "  ]" << endl;
        }
        cout << " }" << endl;
    }
};

#endif // ORDER_H