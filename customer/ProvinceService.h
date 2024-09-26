#ifndef PROVINCE_SERVICE_H
#define PROVINCE_SERVICE_H

#include <vector>
#include "Customer.h"

using namespace std;

// 省份服务（ProvinceService）
class ProvinceService {
public:
    // 根据ID查找省份信息
    static Province* load(long id);
    // 根据ID检查该省份是否存在
    static bool exists(long id);
    // 查找所有的省份
    static vector<Province*> loadAll();
};

#endif // PROVINCE_SERVICE_H