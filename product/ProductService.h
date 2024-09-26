#ifndef PRODUCT_SERVICE_H
#define PRODUCT_SERVICE_H

#include "Product.h"

using namespace std;

// 商品服务（ProductService）
class ProductService {
public:
    // 由供应商的员工创建新的产品
    static long create(Product* product);
    // 由该供应商的员工维护该产品信息
    static void modify(Product* product);
    // 由该供应商的员工删除产品
    static void remove(long productId);
    // 查找产品信息
    static Product* load(long productId);
    // 检查相应产品是否存在
    static bool exists(long productId);
};

#endif // PRODUCT_SERVICE_H