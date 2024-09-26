#include "ProductCategoryService.h"
#include "../support/Repository.hpp"

using namespace std;

// 根据ID查找商品分类
ProductCategory* ProductCategoryService::load(long categoryId) {
    return Repository<ProductCategory, long>::load(categoryId);
}

// 根据ID检查商品分类是否存在
bool ProductCategoryService::exists(long categoryId) {
    return load(categoryId) != NULL;
}

// 查找所有商品分类
vector<ProductCategory*> ProductCategoryService::loadAll() {
    return Repository<ProductCategory, long>::loadAll(NULL);
}