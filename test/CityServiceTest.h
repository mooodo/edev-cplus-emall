#pragma once

#include <iostream>
#include <cassert>
#include "../customer/CityService.h"
#include "../support/GenericCache.hpp"
using namespace std;

// 初始化城市数据的函数
void initCity() {
    City* city1 = new City();
    city1->setId(3701);
    city1->name = "济南";
    city1->provinceId = 37;
    city1->cityCode = "370100";

    City* city2 = new City();
    city2->setId(3301);
    city2->name = "杭州";
    city2->provinceId = 33;
    city2->cityCode = "330100";

    City* city3 = new City();
    city3->setId(5001);
    city3->name = "重庆";
    city3->provinceId = 50;
    city3->cityCode = "500100";

    map<long, City*> cityMap = { {city1->getId(), city1}, {city2->getId(), city2}, {city3->getId(), city3} };
    GenericCache<City*, long>* cache = GenericCache<City*, long>::getInstance();
    cache->setAll(cityMap);
}

// 测试城市加载功能
void testCityLoad() {
    long validId = 3301; // 假设3301是一个有效的城市ID
    City* city = CityService::load(validId);
    assert(city != NULL); // 断言城市对象不是NULL
    assert(city->getId() == validId); // 断言城市对象的ID匹配
    cout << "load a city:" << endl;
    city->print();
}

// 测试城市存在性检查
void testCityExists() {
    long validId = 3301; // 假设3301是一个有效的城市ID
    long invalidId = 999; // 假设999是一个无效的城市ID
    assert(CityService::exists(validId) == true); // 断言有效ID存在
    assert(CityService::exists(invalidId) == false); // 断言无效ID不存在
}

// 测试加载所有城市
void testCityLoadAll() {
    std::vector<City*> cities = CityService::loadAll();
    assert(cities.size() > 0); // 断言返回的向量不为空
    cout << "load all of the cities:" << endl;
    for(City *city : cities)
        if(city!=nullptr) city->print();
}

// 测试城市边界条件
void testCityBoundaryConditions() {
    long minId = 3301; // 假设3301是最小的有效ID
    long maxId = 5001; // 假设5001是最大的有效ID
    assert(CityService::exists(minId) == true); // 检查最小ID存在
    assert(CityService::exists(maxId) == true); // 检查最大ID存在
    assert(CityService::exists(-1) == false); // 检查负数ID不存在
}

// 主测试函数
void testCityService() {
    cout << ">>>CityService: begin test" << endl;
    initCity();
    testCityLoad();
    testCityExists();
    testCityLoadAll();
    testCityBoundaryConditions();
    cout << ">>>CityService: All tests passed!" << endl;
}