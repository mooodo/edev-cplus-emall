#ifndef STAFF_SERVICE_H
#define STAFF_SERVICE_H

#include <vector>
#include "Supplier.h"

using namespace std;

// 员工服务（StaffService）
class StaffService {
public:
    // 登记新员工
    static long create(Staff* staff);
    // 更新员工资料
    static void modify(Staff* staff);
    // 删除员工资料
    static void remove(long staffId);
    // 根据ID查找员工及其资料
    static Staff* load(long staffId);
    // 根据供应商ID查找相应的员工及其资料
    static vector<Staff*> loadBySupplier(long supplierId);
    // 根据供应商ID查找其是否还有相应的员工
    static bool existsBySupplier(long supplierId);
};

#endif // STAFF_SERVICE_H