#pragma once

#include <iostream>
#include <vector>
#include <cassert>
#include "../vip/VipService.h"
#include "../customer/CustomerService.h"
#include "../support/GenericCache.hpp"
using namespace std;


// 初始化测试数据的函数
void initVipTestData() {
    Vip* vip0 = new Vip();
    vip0->setId(10002);
    vip0->name = "John Doe";
    vip0->points = 1000;
    vip0->accumulatedPoints = 5000;
    vip0->vipLevel = 1;

    map<long, Vip*> vipMap = { { vip0->getId(), vip0 } };
    GenericCache<Vip*, long>::getInstance()->setAll(vipMap);
}

// 测试客户注册成为会员
void testCreateVip() {
    long id = 10001;
    Customer* customer = CustomerService::load(id);
    Vip* vip = new Vip();
    vip->setId(customer->getId());
    vip->name = customer->name;
    long vipId = VipService::create(vip);

    assert(VipService::exists(vipId) == true); // 断言新会员存在
    Vip *createdVip = VipService::load(id);
    cout << "create a vip:" << endl;
    createdVip->print();
    assert(VipService::loadByCustomer(customer) != NULL); // 断言新会员存在
}

// 测试会员对自己的信息进行更新
void testModifyVip() {
    Vip* vip = VipService::load(10001);
    vip->name = "Jackson"; // 假设会员修改了名称
    VipService::modify(vip);

    Vip* modifiedVip = VipService::load(vip->getId());
    cout << "modify a vip:" << endl;
    modifiedVip->print();
    assert(modifiedVip->name == vip->name); // 断言名称已更新
}

// 测试系统管理员删除会员信息
void testRemoveVip() {
    VipService::remove(10001);
    assert(VipService::exists(10001) == false); // 断言会员不存在
}

// 测试根据ID查找会员信息
void testLoadVip() {
    Vip* vip = VipService::load(10002);
    assert(vip != NULL); // 断言返回的会员对象不是NULL
    cout << "load a vip:" << endl;
    vip->print();
}

// 测试根据ID检查会员是否存在
void testVipExists() {
    assert(VipService::exists(10002) == true); // 假设10002是存在的会员ID
    assert(VipService::exists(999) == false); // 假设999不存在
}

// 测试购买商品后累积积分
void testAccumulatePoints() {
    Vip* vip = VipService::load(10002);
    int originalPoints = vip->points;
    int originalAccumulatedPoints = vip->accumulatedPoints;
    VipService::accumulatePoints(10002, 50);
    vip = VipService::load(10002);
    cout << "accumulate 50 points for a vip:" << endl;
    vip->print();
    assert(vip->points == originalPoints + 50); // 断言积分已累积
    assert(vip->accumulatedPoints == originalAccumulatedPoints + 50); // 断言累积积分已更新
}

// 测试使用积分进行兑换
void testRedeemPoints() {
    Vip* vip = VipService::load(10002);
    int originalPoints = vip->points;
    int originalAccumulatedPoints = vip->accumulatedPoints;
    VipService::redeemPoints(10002, 30); // 假设1是存在的会员ID
    vip = VipService::load(10002);
    cout << "redeem 30 points for a vip:" << endl;
    vip->print();
    assert(vip->points == originalPoints - 30); // 断言积分已兑换
    assert(vip->accumulatedPoints == originalAccumulatedPoints); // 断言累积积分未变化
}

// 主测试函数
void testVipService() {
    cout << ">>>VipService: begin test" << endl;
    initVipTestData();
    testCreateVip();
    testModifyVip();
    testRemoveVip();
    testLoadVip();
    testVipExists();
    testAccumulatePoints();
    testRedeemPoints();
    cout << ">>>VipService: All tests passed!" << endl;
}