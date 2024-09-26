#ifndef PRODUCT_CATEGORY_SERVICE_H
#define PRODUCT_CATEGORY_SERVICE_H

#include <vector>
#include "Product.h"

using namespace std;

// 商品分类服务（ProductCategoryService）
class ProductCategoryService {
public:
    // 根据ID查找商品分类
    static ProductCategory* load(long categoryId);
    // 根据ID检查商品分类是否存在
    static bool exists(long categoryId);
    // 查找所有商品分类
    static vector<ProductCategory*> loadAll();
};

#endif // PRODUCT_CATEGORY_SERVICE_H