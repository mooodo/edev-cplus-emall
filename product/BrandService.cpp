#include "BrandService.h"
#include "../support/Repository.hpp"

using namespace std;

// 根据ID查找品牌
Brand* BrandService::load(long brandId) {
    return Repository<Brand, long>::load(brandId);
}

// 根据ID检查品牌是否存在
bool BrandService::exists(long brandId) {
    return load(brandId) != NULL;
}

// 查找所有品牌
vector<Brand*> BrandService::loadAll() {
    return Repository<Brand, long>::loadAll(NULL);
}