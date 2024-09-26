#include "CountryService.h"
#include "../support/Repository.hpp"
using namespace std;

// 根据ID查找国家信息
Country* CountryService::load(long id) {
	return Repository<Country,long>::load(id);
}

// 根据ID检查该国家是否存在
bool CountryService::exists(long id) {
	return load(id) != NULL;
}

// 查找所有的国家
vector<Country*> CountryService::loadAll() {
	return Repository<Country,long>::loadAll(NULL);
}

