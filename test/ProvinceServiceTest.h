#pragma once

#include <cassert>
#include <iostream>
#include "../customer/ProvinceService.h"
#include "../support/GenericCache.hpp"
using namespace std;

// 初始化省份数据的函数
void initProvince() {
    Province* province1 = new Province();
    province1->setId(37);
    province1->countryId = 1;
    province1->name = "山东";
    province1->provinceCode = "370000";

    Province* province2 = new Province();
    province2->setId(33);
    province2->countryId = 1;
    province2->name = "浙江";
    province2->provinceCode = "330000";

    Province* province3 = new Province();
    province3->setId(50);
    province3->countryId = 1;
    province3->name = "重庆";
    province3->provinceCode = "500000";

    map<long, Province*> provinces = {
        { province1->getId(), province1 },
        { province2->getId(), province2 },
        { province3->getId(), province3 }
    };
    GenericCache<Province*, long>* cache = GenericCache<Province*, long>::getInstance();
    cache->setAll(provinces);
}

// 测试省份加载功能
void testProvinceLoad() {
    long validId = 33; // 假设1是一个有效的省份ID
    Province* province = ProvinceService::load(validId);
    assert(province != NULL); // 断言省份对象不是NULL
    assert(province->getId() == validId); // 断言省份对象的ID匹配
    cout << "load a province:" << endl;
    province->print();
}

// 测试省份存在性检查
void testProvinceExists() {
    long validId = 33; // 假设1是一个有效的省份ID
    long invalidId = 999; // 假设999是一个无效的省份ID
    assert(ProvinceService::exists(validId) == true); // 断言有效ID存在
    assert(ProvinceService::exists(invalidId) == false); // 断言无效ID不存在
}

// 测试加载所有省份
void testProvinceLoadAll() {
    vector<Province*> provinces = ProvinceService::loadAll();
    assert(provinces.size() > 0); // 断言返回的向量不为空
    cout << "load all of the privinces:" << endl;
    for(Province *province : provinces)
        if(province!=nullptr) province->print();
}

// 测试省份边界条件
void testProvinceBoundaryConditions() {
    long minId = 33; // 假设33是最小的有效ID
    long maxId = 50; // 假设50是最大的有效ID
    assert(ProvinceService::exists(minId) == true); // 检查最小ID存在
    assert(ProvinceService::exists(maxId) == true); // 检查最大ID存在
    assert(ProvinceService::exists(-1) == false); // 检查负数ID不存在
}

// 主测试函数
void testProvinceService() {
    cout << ">>>ProvinceService: begin test" << endl;
    initProvince();
    testProvinceLoad();
    testProvinceExists();
    testProvinceLoadAll();
    testProvinceBoundaryConditions();
    cout << ">>>ProvinceService: All tests passed!" << endl;
}