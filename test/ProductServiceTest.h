#pragma once

#include <iostream>
#include <cassert>
#include "../product/ProductService.h"
#include "../supplier/SupplierService.h"
#include "../support/GenericCache.hpp"
using namespace std;

// 初始化测试数据的函数
void initProductTestData() {
    Product* product1 = new Product();
    product1->setId(20001);
    product1->name = "Smart Phone";
    product1->supplierId = 30001;
    product1->categoryId = 1;
    product1->brandId = 1;
    product1->description = "A smart phone with 5.5 inch screen";
    product1->price = 1999.99;

    Product* product2 = new Product();
    product2->setId(20002);
    product2->name = "Laptop";
    product2->supplierId = 30002;
    product2->categoryId = 1;
    product2->brandId = 2;
    product2->description = "A laptop with 15.6 inch screen";
    product2->price = 3999.99;

    map<long, Product*> productMap = {
        {product1->getId(), product1}, {product2->getId(), product2}
    };
    GenericCache<Product*, long>::getInstance()->setAll(productMap);
}

// 测试创建新产品
void testCreateProduct() {
    Product* product = new Product();
    product->setId(1);
    product->name = "Node Book";
    product->supplierId = 30001;
    product->categoryId = 2;
    product->brandId = 3;
    product->description = "A book about Node.js";

    long newProductId = ProductService::create(product);
    assert(newProductId == 1); // 断言生成了新的产品ID
    assert(ProductService::exists(newProductId) == true); // 断言新创建的产品存在
    Product *newProduct = ProductService::load(newProductId);
    cout << "create a new product:" << endl;
    newProduct->print();
}

// 测试维护产品信息
void testModifyProduct() {
    Product* product = ProductService::load(1);
    product->description = "Updated description"; // 更新商品描述
    ProductService::modify(product);

    Product* modifiedProduct = ProductService::load(product->getId());
    assert(modifiedProduct->description == product->description); // 断言描述已更新
    cout << "modify a product:" << endl;
    modifiedProduct->print();
}

// 测试删除产品
void testRemoveProduct() {
    ProductService::remove(1);

    assert(ProductService::exists(1) == false); // 断言产品不存在
}

// 测试查找产品信息
void testLoadProduct() {
    Product* product = ProductService::load(20001);

    assert(product != NULL); // 断言返回的产品对象不是NULL
    cout << "load a product:" << endl;
    product->print();
}

// 测试检查产品是否存在
void testProductExists() {
    assert(ProductService::exists(20001) == true); // 假设20001是存在的产品ID
    assert(ProductService::exists(999) == false); // 假设999不存在
}

// 主测试函数
void testProductService() {
    cout << ">>>ProductService: begin test" << endl;
    initProductTestData();
    testCreateProduct();
    testModifyProduct();
    testRemoveProduct();
    testLoadProduct();
    testProductExists();
    cout << ">>>ProductService: All tests passed!" << endl;
}