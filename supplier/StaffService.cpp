#include "StaffService.h"
#include "SupplierService.h"
#include "../support/Repository.hpp"
#include "../support/ValidException.h"
#include "../support/DateUtils.h"

using namespace std;

void valid(Staff* staff) {
    if( staff->name.empty() ) throw new ValidException("员工姓名不能为空");
    if( staff->supplierId == 0 ) throw new ValidException("供应商ID不能为空");
    if( !SupplierService::exists(staff->supplierId) ) throw new ValidException("供应商ID不存在");
}

// 登记新员工
long StaffService::create(Staff* staff) {
    valid(staff);
    if(staff->getId() ==0 ) staff->setId(Repository<Staff, long>::nextId());
    staff->createTime = DateUtils::getNow();
    return Repository<Staff, long>::insert(staff);
}

// 更新员工资料
void StaffService::modify(Staff* staff) {
    valid(staff);
    staff->modifyTime = DateUtils::getNow();
    Repository<Staff, long>::update(staff);
}

// 删除员工资料
void StaffService::remove(long staffId) {
    Repository<Staff, long>::remove(staffId);
}

// 根据ID查找员工及其资料
Staff* StaffService::load(long staffId) {
    return Repository<Staff, long>::load(staffId);
}

// 根据供应商ID查找相应的员工及其资料
vector<Staff*> StaffService::loadBySupplier(long supplierId) {
    Staff* staff = new Staff();
    staff->supplierId = supplierId;
    return Repository<Staff, long>::loadAll(staff);
}

// 根据供应商ID查找其是否还有相应的员工
bool StaffService::existsBySupplier(long supplierId) {
    vector<Staff*> staffs = loadBySupplier(supplierId);
    return !loadBySupplier(supplierId).empty();
}