#ifndef VIP_H
#define VIP_H
#include <string>
#include <ctime>
#include <iostream>
#include "../support/Repository.hpp"
using namespace std;

// 积分规则（PointsRule）领域对象
struct PointsRule : Entity<long> {
    long id;                // 规则ID
    int pointsPerYuan;     // 每消费一定金额获得的积分数
    int pointsCap;           // 单次购买可获得的积分上限
    void print() const {
        cout << "  { id: " << id
        << ", pointsPerYuan: " << pointsPerYuan
        << ", pointsCap: " << pointsCap << " }" << endl;
    }
};

// 升级规则（UpgroundRule）领域对象
struct UpgroundRule : Entity<long> {
    long id;                // 规则ID
    int vipLevel;           // 会员的等级
    int pointsNeed;         // 达到该等级所需的积分
    void print() const {
        cout << "  { id: " << id
        << ", vipLevel: " << vipLevel
        << ", pointsNeed: " << pointsNeed << " }" << endl;
    }
};

// 会员（Vip）领域对象
struct Vip : Entity<long> {
    long id;                // 会员ID
    string name;            // 会员名称，关联客户姓名
    int points;             // 会员当前积分
    int accumulatedPoints;  // 会员累计积分
    int vipLevel;           // 会员当前等级
    time_t createTime;      // 会员创建时间
    time_t modifyTime;      // 会员信息最后修改时间
    void print() const {
        cout << "  { id: " << id
        << ", name: " << name
        << ", points: " << points
        << ", accumulatedPoints: " << accumulatedPoints
        << ", vipLevel: " << vipLevel
        << ", createTime: " << createTime
        << ", modifyTime: " << modifyTime << " }" << endl;
    }
};

#endif // VIP_H