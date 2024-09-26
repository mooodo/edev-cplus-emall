#pragma once

#include <iostream>
#include <vector>
#include <cassert>
#include "../customer/DistrictService.h"
#include "../support/GenericCache.hpp"
using namespace std;

// 初始化区县数据的函数
void initDistrict() {
    District* district1 = new District();
    district1->setId(330106);
    district1->name = "西湖区";
    district1->cityId = 3301;
    district1->districtCode = "330106";

    District* district2 = new District();
    district2->setId(370102);
    district2->name = "历下区";
    district2->cityId = 3701;
    district2->districtCode = "370102";

    District* district3 = new District();
    district3->setId(500106);
    district3->name = "沙坪坝区";
    district3->cityId = 5001;
    district3->districtCode = "500106";

    // 使用GenericCache来缓存区县数据
    map<long, District*> districts = {
        {district1->getId(), district1},
        {district2->getId(), district2},
        {district3->getId(), district3}
    };
    GenericCache<District*, long>* cache = GenericCache<District*, long>::getInstance();
    cache->setAll(districts);
}

// 测试区县加载功能
void testDistrictLoad() {
    long validId = 330106; // 假设330106是一个有效的区县ID
    District* district = DistrictService::load(validId);
    assert(district != NULL); // 断言区县对象不是NULL
    assert(district->getId() == validId); // 断言区县对象的ID匹配
    cout << "load a district:" << endl;
    district->print();
}

// 测试区县存在性检查
void testDistrictExists() {
    long validId = 330106; // 假设330106是一个有效的区县ID
    long invalidId = 999; // 假设999是一个无效的区县ID
    assert(DistrictService::exists(validId) == true); // 断言有效ID存在
    assert(DistrictService::exists(invalidId) == false); // 断言无效ID不存在
}

// 测试加载所有区县
void testDistrictLoadAll() {
    std::vector<District*> districts = DistrictService::loadAll();
    assert(!districts.empty()); // 断言返回的向量不为空
    cout << "load all of the districts:" << endl;
    for(District *district : districts)
        if(district!=nullptr) district->print();
}

// 测试区县边界条件
void testDistrictBoundaryConditions() {
    long minId = 330106; // 假设330106是最小的有效ID
    long maxId = 500106; // 假设500106是最大的有效ID
    assert(DistrictService::exists(minId) == true); // 检查最小ID存在
    assert(DistrictService::exists(maxId) == true); // 检查最大ID存在
    assert(DistrictService::exists(-1) == false); // 检查负数ID不存在
}

// 主测试函数
void testDistrictService() {
    cout << ">>>DistrictService: begin test" << endl;
    initDistrict();
    testDistrictLoad();
    testDistrictExists();
    testDistrictLoadAll();
    testDistrictBoundaryConditions();
    cout << ">>>DistrictService: All tests passed!" << endl;
}