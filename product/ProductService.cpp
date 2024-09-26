#include "ProductService.h"
#include "ProductCategoryService.h"
#include "BrandService.h"
#include "../supplier/SupplierService.h"
#include "../support/Repository.hpp"
#include "../support/ValidException.h"
#include "../support/DateUtils.h"

using namespace std;

void valid(Product* product) {
    if(product->name.empty()) throw new ValidException("产品名称不能为空");
    if(product->categoryId == 0) throw new ValidException("产品分类不能为空");
    if(product->brandId == 0) throw new ValidException("产品品牌不能为空");
    if(product->supplierId == 0) throw new ValidException("产品供应商不能为空");
    if(product->price < 0) throw new ValidException("产品价格必须设置");
    if(!ProductCategoryService::exists(product->categoryId)) throw new ValidException("产品分类不存在");
    if(!BrandService::exists(product->brandId)) throw new ValidException("产品品牌不存在");
    if(!SupplierService::exists(product->supplierId)) throw new ValidException("产品供应商不存在");
}

// 由供应商的员工创建新的产品
long ProductService::create(Product* product) {
    valid(product);
    if(product->getId() == 0) product->setId(Repository<Product, long>::nextId());
    product->createTime = DateUtils::getNow();
    return Repository<Product, long>::insert(product);
}

// 由该供应商的员工维护该产品信息
void ProductService::modify(Product* product) {
    valid(product);
    product->modifyTime = DateUtils::getNow();
    Repository<Product, long>::update(product);
}

// 由该供应商的员工删除产品
void ProductService::remove(long productId) {
    Repository<Product, long>::remove(productId);
}

// 查找产品信息
Product* ProductService::load(long productId) {
    return Repository<Product, long>::load(productId);
}

// 检查相应产品是否存在
bool ProductService::exists(long productId) {
    return load(productId) != NULL;
}