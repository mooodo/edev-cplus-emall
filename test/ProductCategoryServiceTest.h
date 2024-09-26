#pragma once

#include <iostream>
#include <cassert>
#include "../product/ProductCategoryService.h"
#include "../support/GenericCache.hpp"
using namespace std;

// 初始化商品分类数据的函数
void initProductCategory() {
    ProductCategory* category1 = new ProductCategory();
    category1->setId(1);
    category1->name = "Electronics";

    ProductCategory* category2 = new ProductCategory();
    category2->setId(2);
    category2->name = "Clothing";

    ProductCategory* category3 = new ProductCategory();
    category3->setId(3);
    category3->name = "Food";

    map<long, ProductCategory*> categories = {
        {category1->getId(), category1},
        {category2->getId(), category2},
        {category3->getId(), category3}
    };
    GenericCache<ProductCategory*, long>* cache = GenericCache<ProductCategory*, long>::getInstance();
    cache->setAll(categories);
}

// 测试商品分类加载功能
void testProductCategoryLoad() {
    long validCategoryId = 1; // 假设1是一个有效的商品分类ID
    ProductCategory* category = ProductCategoryService::load(validCategoryId);
    assert(category != NULL); // 断言商品分类对象不是NULL
    assert(category->getId() == validCategoryId); // 断言商品分类对象的ID匹配
    cout << "load a product category:" << endl;
    category->print();
}

// 测试商品分类存在性检查
void testProductCategoryExists() {
    long validCategoryId = 1; // 1是一个有效的商品分类ID
    long invalidCategoryId = 999; // 假设999是一个无效的商品分类ID
    assert(ProductCategoryService::exists(validCategoryId) == true); // 断言有效ID存在
    assert(ProductCategoryService::exists(invalidCategoryId) == false); // 断言无效ID不存在
}

// 测试加载所有商品分类
void testProductCategoryLoadAll() {
    std::vector<ProductCategory*> categories = ProductCategoryService::loadAll();
    assert(!categories.empty()); // 断言返回的向量不为空
    cout << "load all of the product categories:" << endl;
    for (ProductCategory *category : categories)
        if(category!=nullptr) category->print();
}

// 测试商品分类边界条件
void testProductCategoryBoundaryConditions() {
    long minId = 1; // 假设1是最小的有效ID
    long maxId = 3; // 假设3是最大的有效ID
    assert(ProductCategoryService::exists(minId) == true); // 检查最小ID存在
    assert(ProductCategoryService::exists(maxId) == true); // 检查最大ID存在
    assert(ProductCategoryService::exists(-1) == false); // 检查负数ID不存在
}

// 主测试函数
void testProductCategoryService() {
    cout << ">>>ProductCategoryService: begin test" << endl;
    initProductCategory();
    testProductCategoryLoad();
    testProductCategoryExists();
    testProductCategoryLoadAll();
    testProductCategoryBoundaryConditions();
    cout << ">>>ProductCategoryService: All tests passed!" << endl;
}