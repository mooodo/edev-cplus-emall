#include "SupplierService.h"
#include "StaffService.h"
#include "../support/Repository.hpp"
#include "../support/ValidException.h"
#include "../support/DateUtils.h"
using namespace std;

void Valid(Supplier* supplier) {
    if(supplier->name.empty()) throw new ValidException("供应商名称不能为空");
}

// 系统管理员添加新的供应商
long SupplierService::create(Supplier* supplier) {
    Valid(supplier);
    if(supplier->getId() == 0) supplier->setId(Repository<Supplier, long>::nextId());
    supplier->createTime = DateUtils::getNow();
    return Repository<Supplier, long>::insert(supplier);
}

// 系统管理员更新供应商信息
void SupplierService::modify(Supplier* supplier) {
    Valid(supplier);
    supplier->modifyTime = DateUtils::getNow();
    Repository<Supplier, long>::update(supplier);
}

// 系统管理员删除供应商
void SupplierService::remove(long supplierId) {
    if(StaffService::existsBySupplier(supplierId)) throw ValidException("该供应商下存在员工，无法删除");
    Repository<Supplier, long>::remove(supplierId);
}

// 查找供应商信息
Supplier* SupplierService::load(long supplierId) {
    return Repository<Supplier, long>::load(supplierId);
}

// 检查供应商是否存在
bool SupplierService::exists(long supplierId) {
    return load(supplierId) != NULL;
}