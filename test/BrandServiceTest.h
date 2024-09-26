#pragma once

#include <iostream>
#include <vector>
#include <cassert>
#include "../product/BrandService.h"
#include "../support/GenericCache.hpp"
using namespace std;

// 初始化品牌数据的函数
void initBrand() {
    Brand* brand1 = new Brand();
    brand1->setId(1);
    brand1->name = "ThinkPad";

    Brand* brand2 = new Brand();
    brand2->setId(2);
    brand2->name = "HUAWEI";

    Brand* brand3 = new Brand();
    brand3->setId(3);
    brand3->name = "Apple";

    map<long, Brand*> brands = {
        {1, brand1}, {2, brand2}, {3, brand3}
    };
    GenericCache<Brand*, long>* cache = GenericCache<Brand*, long>::getInstance();
    cache->setAll(brands);
}

// 测试品牌加载功能
void testBrandLoad() {
    long validBrandId = 1; // 假设1是一个有效的品牌ID
    Brand* brand = BrandService::load(validBrandId);
    assert(brand != NULL); // 断言品牌对象不是NULL
    assert(brand->getId() == validBrandId); // 断言品牌对象的ID匹配
    cout << "load a brand:" << endl;
    brand->print();
}

// 测试品牌存在性检查
void testBrandExists() {
    long validBrandId = 1; // 假设1是一个有效的品牌ID
    long invalidBrandId = 999; // 假设999是一个无效的品牌ID
    assert(BrandService::exists(validBrandId) == true); // 断言有效ID存在
    assert(BrandService::exists(invalidBrandId) == false); // 断言无效ID不存在
}

// 测试加载所有品牌
void testBrandLoadAll() {
    std::vector<Brand*> brands = BrandService::loadAll();
    assert(!brands.empty()); // 断言返回的向量不为空
    cout << "load all of the brands:" << endl;
    for (Brand *brand : brands)
        if (brand!=nullptr) brand->print();
}

// 测试品牌边界条件
void testBrandBoundaryConditions() {
    long minId = 1; // 假设1是最小的有效ID
    long maxId = 3; // 假设3是最大的有效ID
    assert(BrandService::exists(minId) == true); // 检查最小ID存在
    assert(BrandService::exists(maxId) == true); // 检查最大ID存在
    assert(BrandService::exists(-1) == false); // 检查负数ID不存在
}

// 主测试函数
void testBrandService() {
    cout << ">>>BrandService: begin test" << endl;
    initBrand();
    testBrandLoad();
    testBrandExists();
    testBrandLoadAll();
    testBrandBoundaryConditions();
    cout << ">>>BrandService: All tests passed!" << endl;
}