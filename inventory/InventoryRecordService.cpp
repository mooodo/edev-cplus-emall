#include "InventoryRecordService.h"
#include "../product/ProductService.h"
#include "../support/Repository.hpp"
#include "../support/ValidException.h"
#include "../support/DateUtils.h"
using namespace std;

void valid(InventoryRecord* record) {
    if(record->productId == 0) throw ValidException("产品ID不能为空");
    if(record->quantity == 0) throw ValidException("变动数量不能为0");
    if(record->operation.empty()) throw ValidException("操作类型不能为空");
    if(!ProductService::exists(record->productId)) throw ValidException("产品不存在");
}

// 记录每次库存的变动
void InventoryRecordService::insert(InventoryRecord* record) {
    valid(record);
    record->id = Repository<InventoryRecord, long>::nextId();
    record->updateTime = DateUtils::getNow();
    Repository<InventoryRecord, long>::insert(record);
}

// 删除某条库存变动记录
void InventoryRecordService::remove(long id) {
    Repository<InventoryRecord, long>::remove(id);
}