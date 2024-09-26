#pragma once

#include <iostream>
#include <cassert>
#include "../inventory/InventoryService.h"
#include "../inventory/InventoryRecordService.h"
#include "../support/GenericCache.hpp"
using namespace std;

// 初始化测试数据的函数
void initInventoryTestData() {
    Inventory *inventory0 = new Inventory();
    inventory0->setId(20001);
    inventory0->quantity = 1000;

    Inventory *inventory1 = new Inventory();
    inventory1->setId(20002);
    inventory1->quantity = 1000;

    map<long, Inventory*> inventoryMap = {
        {inventory0->getId(), inventory0}, {inventory1->getId(), inventory1}
    };
    GenericCache<Inventory*, long>::getInstance()->setAll(inventoryMap);
}

// 测试第一次入库操作
void testFirstStockIn() {
    InventoryService::stockIn(1, 100);
    Inventory* inventory = InventoryService::check(1);
    assert(inventory != nullptr);
    assert(inventory->quantity == 100);
    cout << "stock in first:" << endl;
    inventory->print();
}

// 测试入库操作
void testStockIn() {
    InventoryService::stockIn(1, 100);
    Inventory* inventory = InventoryService::check(1);
    assert(inventory != nullptr);
    assert(inventory->quantity == 200);
    cout << "stock in again:" << endl;
    inventory->print();
}

// 测试出库操作
void testStockOut() {
    InventoryService::stockOut(1, 50);
    Inventory* inventory = InventoryService::check(1);
    assert(inventory != nullptr);
    assert(inventory->quantity == 150); // 取决于之前库存数量
    cout << "stock out:" << endl;
    inventory->print();
}

// 测试删除库存
void testRemoveInventory() {
    InventoryService::remove(1); // 假设1是存在的产品ID
    Inventory* inventory = InventoryService::check(1);
    assert(inventory == nullptr);
}

// 测试检查库存
void testCheckInventory() {
    Inventory* inventory = InventoryService::check(20001);
    assert(inventory != nullptr);
    cout << "check inventory for the product:" << endl;
    inventory->print();
}

// 主测试函数
void testInventoryService() {
    cout << ">>>InventoryService: begin test" << endl;
    initInventoryTestData();
    testFirstStockIn();
    testStockIn();
    testStockOut();
    testRemoveInventory();
    testCheckInventory();
    cout << ">>>InventoryService: All tests passed!" << endl;
}