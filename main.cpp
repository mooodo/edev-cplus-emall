#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include "test/CountryServiceTest.h"
#include "test/ProvinceServiceTest.h"
#include "test/CityServiceTest.h"
#include "test/DistrictServiceTest.h"
#include "test/BrandServiceTest.h"
#include "test/ProductCategoryServiceTest.h"
#include "test/CustomerServiceTest.h"
#include "test/VipServiceTest.h"
#include "test/SupplierServiceTest.h"
#include "test/StaffServiceTest.h"
#include "test/ProductServiceTest.h"
#include "test/InventoryServiceTest.h"
#include "test/OrderServiceTest.h"
#include "test/PaymentServiceTest.h"
#include "test/OrderAggServiceTest.h"

using namespace std;

int main()
{
    testCountryService();
    testProvinceService();
    testCityService();
    testDistrictService();
    testCustomerService();
    testVipService();

    testSupplierService();
    testStaffService();
    testBrandService();
    testProductCategoryService();
    testProductService();
    testInventoryService();

    testOrderService();
    testPaymentService();
    testOrderAggService();
    return 0;
}
