#ifndef COUNTRY_SERVICE_H
#define COUNTRY_SERVICE_H

#include <vector>
#include "Customer.h"

using namespace std;

// 国家服务（CountryService）
class CountryService {
public:
    // 根据ID查找国家信息
    static Country* load(long id);
    // 根据ID检查该国家是否存在
    static bool exists(long id);
    // 查找所有的国家
    static vector<Country*> loadAll();
};

#endif // COUNTRY_SERVICE_H