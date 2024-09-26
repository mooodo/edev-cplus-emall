#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <cassert>
#include "../customer/CustomerService.h"
#include "../support/GenericCache.hpp"
using namespace std;

time_t makeTime(int year, int month, int day) {
    struct tm t = {0};
    t.tm_year = year - 1900;
    t.tm_mon = month - 1;
    t.tm_mday = day;
    return mktime(&t);
}

// 初始化测试数据的函数
void initTestData() {
    Customer* customer0 = new Customer();
    customer0->setId(10001);
    customer0->name = "Bruce Lee";
    customer0->gender = "male";
    customer0->identification = "110114198102101110";
    customer0->phoneNumber = "12345678901";
    customer0->email = "brucelee@example.com";

    Customer* customer1 = new Customer();
    customer1->setId(10002);
    customer1->name = "John Doe";
    customer1->gender = "male";
    customer1->identification = "110114197912201111";
    customer1->phoneNumber = "12345678902";
    customer1->email = "johndoe@example.com";

    map<long, Customer*> customerMap = {
        {customer0->getId(), customer0}, {customer1->getId(), customer1}
    };
    GenericCache<Customer*, long>* cache = GenericCache<Customer*, long>::getInstance();
    cache->setAll(customerMap);

    Address *address = new Address();
    address->setId(1000101);
    address->customerId = 1;
    address->countryId = 1;
    address->provinceId = 37;
    address->cityId = 3701;
    address->districtId = 370102;
    address->detail = "幸福大街12号";
    map<long, Address*> addressMap = {
        {address->getId(), address}
    };
    GenericCache<Address*, long> *addressCache = GenericCache<Address*, long>::getInstance();
    addressCache->setAll(addressMap);
}

// 测试创建新用户
void testCreateCustomer() {
    Customer* customer = new Customer();
    customer->setId(1);
    customer->name = "Mary Anna";
    customer->gender = "female";
    customer->identification = "510210201001047788";
    customer->phoneNumber = "12345678903";
    customer->email = "maryanna@example.com";
    CustomerService::create(customer);

    assert(CustomerService::exists(1) == true); // 断言客户存在
    Customer* createdCustomer = CustomerService::load(1);
    cout << "create a customer:" << endl;
    createdCustomer->print();
    assert(difftime(CustomerService::load(1)->birthdate,makeTime(2010,1,4))==0); // 断言客户出生日期是否正确
}

// 测试用户更新信息
void testModifyCustomer() {
    Customer* customer = CustomerService::load(1);
    customer->email = "newemail@example.com"; // 更新邮箱

    Address *address = new Address();
    address->setId(10);
    address->customerId = 1;
    address->countryId = 1;
    address->provinceId = 37;
    address->cityId = 3701;
    address->districtId = 370102;
    address->detail = "幸福大街12号";
    customer->addresses.push_back(address);

    CustomerService::modify(customer);

    Customer* updatedCustomer = CustomerService::load(1);
    cout << "modify a customer:" << endl;
    updatedCustomer->print();
    assert(updatedCustomer->email == customer->email); // 断言邮箱已更新
}

// 测试管理员删除用户
void testRemoveCustomer() {
    CustomerService::remove(1); // 假设1是存在的客户ID

    assert(CustomerService::exists(1) == false); // 断言客户不存在
}

// 测试查找用户
void testLoadCustomer() {
    Customer* customer = CustomerService::load(10001); // 假设10001是存在的客户ID
    assert(customer != NULL); // 断言返回的客户对象不是NULL
    cout << "load a customer:" << endl;
    customer->print();
}

// 测试检查客户是否存在
void testCustomerExists() {
    assert(CustomerService::exists(10001) == true); // 假设10001是存在的客户ID
    assert(CustomerService::exists(99999) == false); // 假设99999不存在
}

// 根据多个ID查找客户及其资料
void testLoadCustomerForList() {
    vector<long> ids = {10001, 10002};
    vector<Customer*> customers = CustomerService::loadForList(ids);
    assert(customers.size() == 2); // 断言返回的客户数量是2
    cout << "load some customers:" << endl;
    for (Customer *customer : customers)
        if (customer!=nullptr) customer->print();
}

// 测试查找用户地址
void testLoadAddress() {
    Address* address = CustomerService::loadAddress(1000101);
    assert(address != NULL); // 断言返回的客户对象不是NULL
    cout << "load an address:" << endl;
    address->print();
}

// 测试检查客户地址是否存在
void testAddressExists() {
    assert(CustomerService::existsAddress(1000101) == true);
    assert(CustomerService::existsAddress(99999) == false); // 假设99999不存在
}

// 主测试函数
void testCustomerService() {
    cout << ">>>CustomerService: begin test" << endl;
    initTestData();
    testCreateCustomer();
    testModifyCustomer();
    testRemoveCustomer();
    testLoadCustomer();
    testCustomerExists();
    testLoadCustomerForList();
    testLoadAddress();
    testAddressExists();
    cout << ">>>CustomerService: All tests passed!" << endl;
}