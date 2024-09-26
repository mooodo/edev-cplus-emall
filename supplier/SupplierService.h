#ifndef SUPPLIER_SERVICE_H
#define SUPPLIER_SERVICE_H

#include "Supplier.h" // 假设Supplier.h是包含Supplier定义的头文件

using namespace std;

// 供应商服务（SupplierService）
class SupplierService {
public:
    // 系统管理员添加新的供应商
    static long create(Supplier* supplier);
    // 系统管理员更新供应商信息
    static void modify(Supplier* supplier);
    // 系统管理员删除供应商
    static void remove(long supplierId);
    // 查找供应商信息
    static Supplier* load(long supplierId);
    // 检查供应商是否存在
    static bool exists(long supplierId);
};

#endif // SUPPLIER_SERVICE_H