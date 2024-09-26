#ifndef SUPPLIER_H
#define SUPPLIER_H
#include <string>
#include <ctime>
#include <iostream>
#include "../support/Repository.hpp"
using namespace std;

// 供应商（Supplier）领域对象
struct Supplier : Entity<long> {
    long id;                // 供应商ID
    string name;            // 供应商名称
    string phoneNumber;     // 联系电话
    string email;           // 电子邮箱
    string address;         // 办公地址
    time_t createTime;      // 创建时间
    time_t modifyTime;      // 最后更新时间
    void print() {
        cout << "  { id: " << getId()
        << ", name: " << name
        << ", phoneNumber: " << phoneNumber
        << ", email: " << email
        << ",\n  address: " << address
        << ", createTime: " << createTime
        << ", modifyTime: " << modifyTime << " }" << endl;
    }
};

// 供应商员工（Staff）领域对象
struct Staff : Entity<long> {
    long id;                // 员工ID
    string name;            // 员工姓名
    string gender;          // 性别
    string identification;  // 身份证号
    time_t birthdate;        // 出生日期
    string phoneNumber;     // 联系电话
    string email;           // 联系邮箱
    string position;        // 职位
    long supplierId;        // 所属供应商ID
    time_t createTime;      // 创建时间
    time_t modifyTime;      // 最后更新时间
    void print() {
        cout << "  { id: " << getId()
        << ", name: " << name
        << ", gender: " << gender
        << ", identification: " << identification
        << ", birthdate: " << birthdate
        << ",\n  phoneNumber: " << phoneNumber
        << ", email: " << email
        << ", position: " << position
        << ", supplierId: " << supplierId
        << ",\n  createTime: " << createTime
        << ", modifyTime: " << modifyTime << " }" << endl;
    }
};

#endif // SUPPLIER_H