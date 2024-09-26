#include "ProvinceService.h"
#include "../support/Repository.hpp"

using namespace std;

// 根据ID查找省份信息
Province* ProvinceService::load(long id) {
    return Repository<Province, long>::load(id);
}

// 根据ID检查该省份是否存在
bool ProvinceService::exists(long id) {
    return load(id) != NULL;
}

// 查找所有的省份
vector<Province*> ProvinceService::loadAll() {
    return Repository<Province, long>::loadAll(NULL);
}