#pragma once

#include <iostream>
#include <cassert>
#include "../customer/CountryService.h"
#include "../support/GenericCache.hpp"

void initCountry() {
    Country* country1 = new Country();
    country1->setId(1);
    country1->name = "China";
    country1->countryCode = "86";
    country1->currencyType = "RMB";

    Country* country2 = new Country();
    country2->setId(2);
    country2->name = "USA";
    country2->countryCode = "1";
    country2->currencyType = "USD";

    Country* country3 = new Country();
    country3->setId(3);
    country3->name = "Russia";
    country3->countryCode = "7";
    country3->currencyType = "RUB";

    map<long, Country*> countries = {
        {country1->getId(), country1},
        {country2->getId(), country2},
        {country3->getId(), country3}
    };
    GenericCache<Country*,long>* cache = GenericCache<Country*,long>::getInstance();
    cache->setAll(countries);
}

void testCountryLoad() {
    long validId = 1; // 假设1是一个有效的国家ID
    Country* country = CountryService::load(validId);
    assert(country != NULL); // 断言国家对象不是NULL
    assert(country->getId() == validId); // 断言国家对象的ID匹配
    cout << "load a country: " << endl;
    country->print();
}

void testCountryExists() {
    long validId = 1; // 假设1是一个有效的国家ID
    long invalidId = 999; // 假设999是一个无效的国家ID
    assert(CountryService::exists(validId) == true); // 断言有效ID存在
    assert(CountryService::exists(invalidId) == false); // 断言无效ID不存在
}

void testCountryLoadAll() {
    vector<Country*> countries = CountryService::loadAll();
    assert(countries.size() > 0); // 断言返回的向量不为空
    cout << "load all of the countries: " << endl;
    for( Country *country : countries) 
        if(country!=nullptr) country->print();
}

void testCountryBoundaryConditions() {
    long minId = 1; // 假设1是最小的有效ID
    long maxId = 3; // 假设3是最大的有效ID
    assert(CountryService::exists(minId) == true); // 检查最小ID存在
    assert(CountryService::exists(maxId) == true); // 检查最大ID存在
    assert(CountryService::exists(-1) == false); // 检查负数ID不存在
}

void testCountryService() {
    cout << ">>>CountryService: begin test" << endl;
    initCountry();
    testCountryLoad();
    testCountryExists();
    testCountryLoadAll();
    testCountryBoundaryConditions();
    cout << ">>>CountryService: All tests passed!" << endl;
}
