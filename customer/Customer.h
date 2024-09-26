#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include "../support/Repository.hpp"

using namespace std;

// 区县（District）领域对象
struct District : Entity<long> {
    long id;                // 区县ID
    string name;            // 区县名称
    long cityId;            // 所属地市的ID
    string districtCode;    // 区县的代码
    void print() {
        cout << "  { id: " << getId() << ", name: " << name
        << ", cityId: " << cityId << ", districtCode: " << districtCode << "}" << endl;
    }
};

// 地市（City）领域对象
struct City : Entity<long> {
    long id;                // 地市ID
    string name;            // 地市名称
    long provinceId;        // 所属省份的ID
    string cityCode;        // 地市的代码
    void print() {
        cout << "  { id: " << getId() << ", name: " << name
        << ", provinceId: " << provinceId << ", cityCode: " << cityCode << "}" << endl;
    }
};

// 省份（Province）领域对象
struct Province : Entity<long> {
    long id;                // 省份ID
    string name;            // 省份名称
    long countryId;         // 所属国家的ID
    string provinceCode;    // 省份的代码
        void print() {
        cout << "  { id: " << getId() << ", name: " << name
        << ", countryId: " << countryId << ", provinceCode: " << provinceCode << "}" << endl;
    }
};

// 国家（Country）领域对象
struct Country : Entity<long> {
    long id;                // 国家ID
    string name;            // 国家名称
    string countryCode;     // 国家代码
    string currencyType;    // 货币类型
    void print() {
        cout << "  { id: " << getId() << ", name: " << name
        << ", countryCode: " << countryCode << ", currencyType: " << currencyType << "}" << endl;
    }
};

// 地址（Address）领域对象
struct Address : Entity<long> {
    long id;                // 地址ID
    long customerId;        // 所属客户ID
    long countryId;         // 国家ID
    long provinceId;        // 省份ID
    long cityId;            // 地市ID
    long districtId;        // 区县ID
    string detail;          // 详细地址
    string postalCode;      // 邮政编码
    string phoneNumber;     // 联系电话
    Country* country;        // 国家
    Province* province;      // 省份
    City* city;              // 地市
    District* district;      // 区县

    bool operator==(const Address& address) const {
        if(id!=0 && id != address.id ) { return false; }
        if(customerId!=0 && customerId != address.customerId ) { return false; }
        if(countryId!=0 && countryId != address.countryId ) { return false; }
        if(provinceId!=0 && provinceId != address.provinceId ) { return false; }
        if(cityId!=0 && cityId != address.cityId ) { return false; }
        if(districtId!=0 && districtId != address.districtId ) { return false; }
        return true;
    }

    void print() {
        cout << "  {" << endl;
        cout << "  id: " << getId() << ", customerId: " << customerId
        << ", countryId: " << countryId << ", provinceId: " << provinceId
        << ", cityId: " << cityId << ", districtId: " << districtId
        << ", detail: " << detail << ", postalCode: " << postalCode
        << ", phoneNumber: " << phoneNumber << endl;
        if (country!=nullptr) {
            cout << "  country:" << endl;
            country->print();
        }
        if (province!=nullptr) {
            cout << "  province:" << endl;
            province->print();
        }
        if (city!=nullptr) {
            cout << "  city:" << endl;
            city->print();
        }
        if (district!=nullptr) {
            cout << "  district:" << endl;
            district->print();
        }
        cout << "  }" << endl;
    }
};

// 客户（Customer）领域对象
struct Customer : Entity<long> {
    long id;                // 客户ID
    string name;            // 真实姓名
    string gender;          // 性别
    string identification;  // 身份证号
    time_t birthdate;       // 出生日期
    string email;           // 联系邮箱
    string phoneNumber;     // 联系电话
    time_t createTime;     // 注册时间
    time_t modifyTime;      // 最后更新时间
    vector<Address*> addresses; // 客户可以有多个地址

    bool operator==(const Customer& customer) const {
        if(id!=0 && id != customer.id ) { return false; }
        if(!name.empty() && customer.name != name) { return false; }
        if(!gender.empty() && customer.gender != gender) { return false; }
        if(!identification.empty() && customer.identification != identification) { return false; }
        if(birthdate!=0 && customer.birthdate != birthdate) { return false; }
        if(!email.empty() && customer.email != email) { return false; }
        if(!phoneNumber.empty() && customer.phoneNumber != phoneNumber) { return false; }
        return true;
    }

    void print() {
        cout << "  {" << endl;
        cout << "  id: " << getId() << ", name: " << name
        << ", gender: " << gender << ", identification: " << identification
        << ", birthdate: " << birthdate << ", \n  email: " << email
        << ", phoneNumber: " << phoneNumber
        << ", createTime: " << createTime << ", modifyTime: " << modifyTime << endl;
        if (!addresses.empty()) {
            cout << "  addresses: [" << endl;
            for (Address* addr : addresses) 
                if (addr != nullptr) addr->print();
            cout << "  ]" << endl;
        }
        cout << "  }" << endl;
    }
};

#endif // CUSTOMER_H