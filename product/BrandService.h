#ifndef BRAND_SERVICE_H
#define BRAND_SERVICE_H

#include <vector>
#include "Product.h"

using namespace std;

// 品牌服务（BrandService）
class BrandService {
public:
    // 根据ID查找品牌
    static Brand* load(long brandId);
    // 根据ID检查品牌是否存在
    static bool exists(long brandId);
    // 查找所有品牌
    static vector<Brand*> loadAll();
};

#endif // BRAND_SERVICE_H