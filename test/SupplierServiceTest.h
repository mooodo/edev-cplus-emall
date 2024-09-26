#pragma once

#include <iostream>
#include <cassert>
#include "../supplier/SupplierService.h"
#include "../support/GenericCache.hpp"

// 初始化测试数据的函数
void initSupplierTestData() {
    Supplier* supplier0 = new Supplier();
    supplier0->setId(30001);
    supplier0->name = "Huawei";
    supplier0->phoneNumber = "1234567890";
    supplier0->email = "supplier0@example.com";
    supplier0->address = "123 Supplier Street";

    Supplier* supplier1 = new Supplier();
    supplier1->setId(30002);
    supplier1->name = "Apple";
    supplier1->phoneNumber = "1234567890";
    supplier1->email = "supplier1@example.com";
    supplier1->address = "123 Supplier Street";

    map<long, Supplier*> supplierMap = {
        {supplier0->getId(), supplier0}, {supplier1->getId(), supplier1}
    };
    GenericCache<Supplier*, long>::getInstance()->setAll(supplierMap);
}

// 测试系统管理员添加新的供应商
void testCreateSupplier() {
    long id = 1;
    Supplier* supplier = new Supplier();
    supplier->setId(id);
    supplier->name = "New Supplier";
    supplier->phoneNumber = "1234567890";
    supplier->email = "supplier@example.com";
    supplier->address = "123 Supplier Street";

    long newSupplierId = SupplierService::create(supplier);
    assert(newSupplierId == 1); // 断言生成了新的供应商ID
    assert(SupplierService::exists(newSupplierId) == true); // 断言新创建的供应商存在
    cout << "create a supplier:" << endl;
    Supplier *newSupplier = SupplierService::load(id);
    newSupplier->print();
}

// 测试系统管理员更新供应商信息
void testModifySupplier() {
    Supplier* supplier = SupplierService::load(1);
    supplier->email = "newemail@example.com"; // 更新电子邮箱
    SupplierService::modify(supplier);

    Supplier* modifiedSupplier = SupplierService::load(supplier->getId());
    assert(modifiedSupplier->email == supplier->email); // 断言电子邮箱已更新
    cout << "modify a supplier:" << endl;
    modifiedSupplier->print();
}

// 测试系统管理员删除供应商
void testRemoveSupplier() {
    SupplierService::remove(1);

    assert(SupplierService::exists(1) == false); // 断言供应商不存在
}

// 测试查找供应商信息
void testLoadSupplier() {
    Supplier* supplier = SupplierService::load(30001);

    assert(supplier != NULL); // 断言返回的供应商对象不是NULL
    cout << "load a supplier:" << endl;
    supplier->print();
}

// 测试检查供应商是否存在
void testSupplierExists() {
    assert(SupplierService::exists(30001) == true); // 假设30001是存在的供应商ID
    assert(SupplierService::exists(999) == false); // 假设999不存在
}

// 主测试函数
void testSupplierService() {
    cout << ">>>SupplierService: begin test" << endl;
    initSupplierTestData();
    testCreateSupplier();
    testModifySupplier();
    testRemoveSupplier();
    testLoadSupplier();
    testSupplierExists();
    cout << "SupplierService: All tests passed!" << endl;
}