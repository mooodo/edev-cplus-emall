#ifndef INVENTORY_SERVICE_H
#define INVENTORY_SERVICE_H

#include "Inventory.h"

using namespace std;

// 库存服务（InventoryService）
class InventoryService {
public:
    // 入库，如果还没有库存就建立库存
    static void stockIn(long productId, int quantity);
    // 出库，包括库存扣减、库存调拨等
    static void stockOut(long productId, int quantity);
    // 删除库存
    static void remove(long productId);
    // 检查库存
    static Inventory* check(long productId);
};

#endif // INVENTORY_SERVICE_H