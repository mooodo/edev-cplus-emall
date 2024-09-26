#ifndef CITY_SERVICE_H
#define CITY_SERVICE_H

#include <vector>
#include "Customer.h"

using namespace std;

// 地区服务（CityService）
class CityService {
public:
    // 根据ID查找地区信息
    static City* load(long id);
    // 根据ID检查该地区是否存在
    static bool exists(long id);
    // 查找所有的地区
    static vector<City*> loadAll();
};

#endif // CITY_SERVICE_H