#include "DistrictService.h"
#include "../support/Repository.hpp"

using namespace std;

// 根据ID查找区县信息
District* DistrictService::load(long id) {
    return Repository<District, long>::load(id);
}

// 根据ID检查该区县是否存在
bool DistrictService::exists(long id) {
    return load(id) != NULL;
}

// 查找所有的区县
vector<District*> DistrictService::loadAll() {
    return Repository<District, long>::loadAll(NULL);
}