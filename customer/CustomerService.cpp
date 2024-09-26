#include <cstdio>
#include "CustomerService.h"
#include "../support/ValidException.h"
#include "../support/DateUtils.h"
#include "../support/Repository.hpp"

// 将字符串转换为tm结构体
tm stringToTm(const string& str) {
    tm tm = {};
    int year, month, day;
    sscanf(str.c_str(), "%d-%d-%d", &year, &month, &day);
    tm.tm_year = year - 1900; // tm_year是从1900年开始计数的
    tm.tm_mon = month - 1;    // tm_mon是从0开始计数的，即0代表1月
    tm.tm_mday = day;
    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_sec = 0;
    return tm;
}

// 根据身份证号码获取出生日期
time_t getBirthDateFromIdentification(const string& identification) {
    if (identification.length() < 14) {
        return 0; // 身份证号码长度不足
    }

    string birthdateStr = identification.substr(6, 4) + "-" + identification.substr(10, 2) + "-" + identification.substr(12, 2); // YYYY-MM-DD格式
    tm tm = stringToTm(birthdateStr);

    if (tm.tm_year < 0) {
        return 0; // 出生日期无效
    }
    return mktime(&tm); // 将tm转换为time_t
}

void validCustomer(Customer* customer) {
    if (customer->name.size() == 0) throw ValidException("客户姓名不能为空");
    if(customer->identification.size()!=0) 
        customer->birthdate = getBirthDateFromIdentification(customer->identification);
}


// 注册新客户
void CustomerService::create(Customer* customer) {
    validCustomer(customer);
    customer->id = Repository<Customer,long>::nextId();
    customer->createTime = DateUtils::getNow();
    Repository<Customer,long>::insert(customer);
}

// 客户更新信息
void CustomerService::modify(Customer* customer) {
    validCustomer(customer);
    customer->modifyTime = DateUtils::getNow();
    Repository<Customer,long>::update(customer);
}

// 管理员删除客户
void CustomerService::remove(long customerId) {
    Repository<Customer,long>::remove(customerId);
}

// 查找客户
Customer* CustomerService::load(long customerId) {
    return Repository<Customer,long>::load(customerId);
}

// 检查该客户是否存在
bool CustomerService::exists(long customerId) {
    return load(customerId) != NULL; // 如果load返回NULL，表示客户不存在
}

// 根据多个ID查找客户及其资料
vector<Customer*> CustomerService::loadForList(const vector<long>& customerIds) {
    return Repository<Customer,long>::load(customerIds);
}

// 根据地址ID查找客户的地址信息
Address* CustomerService::loadAddress(long addressId) {
    return Repository<Address,long>::load(addressId);
}

// 根据地址ID查找客户的地址是否存在
bool CustomerService::existsAddress(long addressId) {
    return loadAddress(addressId) != NULL; // 如果load返回NULL，表示地址不存在
}

// 根据多个地址ID查找客户地址
vector<Address*> CustomerService::loadAddressForList(const vector<long>& addressIds) {
    return Repository<Address,long>::load(addressIds);
}