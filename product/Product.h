#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <ctime>
#include <iostream>
#include "../supplier/supplier.h"
#include "../support/Repository.hpp"
using namespace std;

// 商品分类（ProductCategory）领域对象
struct ProductCategory : Entity<long> {
    long id;                // 分类ID
    string name;            // 分类名称
    string description;     // 分类描述
    long parentId;          // 上级分类ID
    void print() {
        cout << "  { id: " << getId()
        << ", name: " << name
        << ", description: " << description
        << ", parentId: " << parentId << " }" << endl;
    }
};

// 品牌（Brand）领域对象
struct Brand : Entity<long> {
    long id;                // 品牌ID
    string name;            // 品牌名称
    string description;     // 品牌描述
    void print() {
        cout << "  { id: " << getId()
        << ", name: " << name
        << ", description: " << description << " }" << endl;
    }
};

// 商品（Product）领域对象
struct Product : Entity<long> {
    long id;                // 商品ID
    string name;            // 商品名称
    string description;     // 商品描述
    long supplierId;        // 供应商ID
    long categoryId;        // 商品分类ID
    long brandId;           // 品牌ID
    double price;           // 商品价格
    string imageUrl;        // 商品图片地址
    string tip;             // 商品提示信息
    string status;          // 商品状态
    time_t createTime;      // 创建时间
    time_t modifyTime;      // 最后修改时间
    Supplier *supplier;      // 关联的供应商
    Brand *brand;            // 关联的品牌
    ProductCategory *category; // 关联的商品分类
    void print() const {
        cout << "  {" << endl;
        cout << "  id: " << id
                  << ", name: " << name
                  << ", description: " << description
                  << ", supplierId: " << supplierId
                  << ", categoryId: " << categoryId
                  << ",\n  brandId: " << brandId
                  << ", price: " << price
                  << ", imageUrl: " << imageUrl
                  << ", tip: " << tip
                  << ", status: " << status
                  << ",\n  createTime: " << createTime
                  << ", modifyTime: " << modifyTime << endl;
        if (supplier != nullptr) {
            std::cout << "  Supplier: ";
            supplier->print(); // 假设Supplier有一个print函数
        }
        if (brand != nullptr) {
            std::cout << "  Brand: ";
            brand->print(); // 假设Brand有一个print函数
        }
        if (category != nullptr) {
            std::cout << "  Category: ";
            category->print(); // 假设ProductCategory有一个print函数
        }
        cout << "  }" << endl;
    }
};

#endif // PRODUCT_H