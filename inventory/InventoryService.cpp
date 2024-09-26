#include "InventoryService.h"
#include "../support/Repository.hpp"
#include "../support/ValidException.h"
#include "../support/DateUtils.h"
using namespace std;

// 入库，如果还没有库存就建立库存
void InventoryService::stockIn(long productId, int quantity) {
    Inventory* inventory = Repository<Inventory, long>::load(productId);
    if (inventory == nullptr) {
        // 如果不存在库存，创建新的库存记录
        inventory = new Inventory();
        inventory->setId(productId);
        inventory->quantity = quantity;
        inventory->updateTime = DateUtils::getNow();
        Repository<Inventory, long>::insert(inventory);
    } else {
        // 如果库存存在，增加数量
        inventory->quantity += quantity;
        inventory->updateTime = DateUtils::getNow();
        Repository<Inventory, long>::update(inventory);
    }
}

// 出库，包括库存扣减、库存调拨等
void InventoryService::stockOut(long productId, int quantity) {
    Inventory* inventory = Repository<Inventory, long>::load(productId);
    if (inventory != NULL) {
        inventory->quantity -= quantity;
        if( inventory->quantity < 0 ) throw new ValidException("库存不足");
        Repository<Inventory, long>::update(inventory);
    } else {
        throw new ValidException("库存不存在");
    }
}

// 删除库存
void InventoryService::remove(long productId) {
    Repository<Inventory, long>::remove(productId);
}

// 检查库存
Inventory* InventoryService::check(long productId) {
    return Repository<Inventory, long>::load(productId);
}