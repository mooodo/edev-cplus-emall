#include "VipService.h"
#include "../support/Repository.hpp"
#include "../support/ValidException.h"
#include "../support/DateUtils.h"
#include "../customer/CustomerService.h"
using namespace std;

void valid(Vip* vip) {
    Customer* customer = CustomerService::load(vip->getId());
    if(customer==NULL) throw new ValidException("Customer does not exist");
    vip->name = customer->name;
}

// 客户注册成为会员
long VipService::create(Vip* vip) {
    valid(vip);
    vip->createTime = DateUtils::getNow();
    return Repository<Vip, long>::insert(vip);
}

// 会员对自己的信息进行更新
void VipService::modify(Vip* vip) {
    valid(vip);
    vip->modifyTime = DateUtils::getNow();
    Repository<Vip, long>::update(vip);
}

// 系统管理员删除会员信息
void VipService::remove(long vipId) {
    Repository<Vip, long>::remove(vipId);
}

// 根据ID查找会员信息
Vip* VipService::load(long vipId) {
    return Repository<Vip, long>::load(vipId);
}

// 根据ID检查会员是否存在
bool VipService::exists(long vipId) {
    return load(vipId) != NULL;
}

// 根据客户查找对应的会员信息
Vip* VipService::loadByCustomer(Customer* customer) {
    return load(customer->getId());
}

// 购买商品后累积积分
void VipService::accumulatePoints(long vipId, int points) {
    Vip* vip = load(vipId);
    vip->points += points;
    vip->accumulatedPoints += points;
    modify(vip);
}

// 使用积分进行兑换
void VipService::redeemPoints(long vipId, int points) {
    Vip* vip = load(vipId);
    vip->points -= points;
    modify(vip);
}





