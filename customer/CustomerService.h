#ifndef CUSTOMER_SERVICE_H
#define CUSTOMER_SERVICE_H

#include <string>
#include <ctime>
#include <vector>
#include "Customer.h"

using namespace std;

// 客户服务（CustomerService）
class CustomerService {
public:
    // 注册新客户
    static void create(Customer* customer);
    // 客户更新信息
    static void modify(Customer* customer);
    // 管理员删除客户
    static void remove(long customerId);
    // 查找客户
    static Customer* load(long customerId);
    // 检查该客户是否存在
    static bool exists(long customerId);
    // 根据多个ID查找客户及其资料
    static vector<Customer*> loadForList(const vector<long>& customerIds);
    // 根据地址ID查找客户的地址信息
    static Address* loadAddress(long addressId);
    // 根据地址ID查找客户的地址是否存在
    static bool existsAddress(long addressId);
    // 根据多个地址ID查找客户地址
    static vector<Address*> loadAddressForList(const vector<long>& addressIds);
};

#endif // CUSTOMER_SERVICE_H