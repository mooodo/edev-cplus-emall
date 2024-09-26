#ifndef DISTRICT_SERVICE_H
#define DISTRICT_SERVICE_H

#include <vector>
#include "Customer.h"

using namespace std;

// 区县服务（DistrictService）
class DistrictService {
public:
    // 根据ID查找区县信息
    static District* load(long id);
    // 根据ID检查该区县是否存在
    static bool exists(long id);
    // 查找所有的区县
    static vector<District*> loadAll();
};

#endif // DISTRICT_SERVICE_H