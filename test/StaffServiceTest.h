#pragma once

#include <iostream>
#include <vector>
#include <cassert>
#include "../supplier/StaffService.h"
#include "../support/GenericCache.hpp"
using namespace std;

// 初始化测试数据的函数
void initStaffTestData() {
    Staff* staff0 = new Staff();
    staff0->setId(40001);
    staff0->name = "John Smith";
    staff0->gender = "male";
    staff0->identification = "110102201007103456";
    staff0->email = "john@example.com";
    staff0->phoneNumber = "123456789";
    staff0->supplierId = 30001;

    Staff* staff1 = new Staff();
    staff1->setId(40002);
    staff1->name = "Jane Smith";
    staff1->gender = "female";
    staff1->identification = "110102201007103456";
    staff1->email = "jane@example.com";
    staff1->phoneNumber = "123456789";
    staff1->supplierId = 30001;

    map<long, Staff*> staffMap = { {staff0->getId(), staff0}, {staff1->getId(), staff1} };
    GenericCache<Staff*, long>::getInstance()->setAll(staffMap);
}

// 测试登记新员工
void testCreateStaff() {
    Staff* newStaff = new Staff();
    newStaff->setId(1);
    newStaff->name = "Mike Nile";
    newStaff->gender = "male";
    newStaff->identification = "110102201007103456";
    newStaff->email = "mike@example.com";
    newStaff->phoneNumber = "123456789";
    newStaff->supplierId = 30001;

    long newStaffId = StaffService::create(newStaff);
    assert(newStaffId == 1);
    Staff *createdStaff = StaffService::load(newStaffId);
    assert( createdStaff!= NULL);
    cout << "create a staff:" << endl;
    createdStaff->print();
}

// 测试更新员工资料
void testModifyStaff() {
    Staff* existingStaff = StaffService::load(1);
    existingStaff->email = "newemail@example.com"; // 更新电子邮箱
    StaffService::modify(existingStaff);

    Staff *modifiedStaff = StaffService::load(1);
    assert(modifiedStaff->email == "newemail@example.com");
    cout << "modify a staff:" << endl;
    modifiedStaff->print();
}

// 测试删除员工资料
void testRemoveStaff() {
    StaffService::remove(1);
    assert(StaffService::load(1) == NULL);
}

// 测试根据ID查找员工及其资料
void testLoadStaff() {
    Staff* staff = StaffService::load(40001);
    assert(staff != NULL);
    cout << "load a staff:" << endl;
    staff->print();
}

// 测试根据供应商ID查找相应的员工及其资料
void testLoadBySupplier() {
    vector<Staff*> staffs = StaffService::loadBySupplier(30001);
    assert(!staffs.empty());
    cout << "load all of the staffs by their supplier:" << endl;
    for (Staff *staff : staffs)
        if(staff!=nullptr) staff->print();
}

// 测试根据供应商ID查找其是否还有相应的员工
void testExistsBySupplier() {
    assert(StaffService::existsBySupplier(30001));
}

// 主测试函数
void testStaffService() {
    cout << ">>>StaffService: begin test" << endl;
    initStaffTestData();
    testCreateStaff();
    testModifyStaff();
    testRemoveStaff();
    testLoadStaff();
    // testLoadBySupplier();
    // testExistsBySupplier();
    cout << ">>>StaffService: All tests passed!" << endl;
}