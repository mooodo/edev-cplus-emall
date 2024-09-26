#ifndef INVENTORY_RECORD_SERVICE_H
#define INVENTORY_RECORD_SERVICE_H

#include "Inventory.h"

using namespace std;

// 库存记录服务（InventoryRecordService）
class InventoryRecordService {
public:
    // 记录每次库存的变动
    static void insert(InventoryRecord* record);
    // 删除某条库存变动记录
    static void remove(long id);
};

#endif // INVENTORY_RECORD_SERVICE_H