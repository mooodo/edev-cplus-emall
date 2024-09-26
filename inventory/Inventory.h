#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
#include <ctime>
#include <iostream>
#include "../support/Repository.hpp"
using namespace std;

// 库存（Inventory）领域对象
struct Inventory : Entity<long> {
    long id;                // 库存ID
    long quantity;          // 当前库存数量
    time_t updateTime;     // 库存最后更新的时间
    void print() {
        cout << "  { id: " << getId()
        << ", quantity: " << quantity
        << ", updateTime: " << updateTime << " }" << endl;
    }
};

// 商品库存记录（InventoryRecord）领域对象
struct InventoryRecord : Entity<long> {
    long id;                // 记录ID
    long productId;         // 关联的商品ID
    long quantity;          // 库存变化的数量
    time_t updateTime;      // 库存变化的时间
    string operation;       // 库存变化的操作，如入库、出库等
    void print() {
        cout << "  { id: " << getId()
        << ", productId: " << productId
        << ", quantity: " << quantity
        << ", updateTime: " << updateTime
        << ", operation: " << operation << " }" << endl;
    }
};

#endif // INVENTORY_H