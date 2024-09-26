#ifndef VIP_SERVICE_H
#define VIP_SERVICE_H

#include <string>
#include <ctime>
#include "Vip.h"
#include "../customer/Customer.h"

using namespace std;

// 会员服务（VipService）
class VipService {
public:
    // 客户注册成为会员
    static long create(Vip* vip);
    // 会员对自己的信息进行更新
    static void modify(Vip* vip);
    // 系统管理员删除会员信息
    static void remove(long vipId);
    // 根据ID查找会员信息
    static Vip* load(long vipId);
    // 根据ID检查会员是否存在
    static bool exists(long vipId);
    // 根据客户查找对应的会员信息
    static Vip* loadByCustomer(Customer* customer);
    // 购买商品后累积积分
    static void accumulatePoints(long vipId, int points);
    // 使用积分进行兑换
    static void redeemPoints(long vipId, int points);
};

#endif // VIP_SERVICE_H