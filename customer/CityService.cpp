#include "CityService.h"
#include "../support/Repository.hpp"

using namespace std;

// 根据ID查找地区信息
City* CityService::load(long id) {
    return Repository<City, long>::load(id);
}

// 根据ID检查该地区是否存在
bool CityService::exists(long id) {
    return load(id) != NULL;

}

// 查找所有的地区
vector<City*> CityService::loadAll() {
    return Repository<City, long>::loadAll(NULL);
}