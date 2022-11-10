/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//  Written By : Student Name                    Environment : ubuntu:bionic               //
//  Date ......: 2021/02/10                      Compiler ...: clang-10                    //
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
// clang-format on
/////////////////////////////////////////////////////////////////////////////////////////////
//                             Framework Set-up //
/////////////////////////////////////////////////////////////////////////////////////////////
#include "../catch/catch.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                                 Includes //
/////////////////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
#include <iostream>
#include <vector>

#include "../includes/ERP.h"

/////////////////////////////////////////////////////////////////////////////////////////////
//                             Helpers/Constants //
/////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////
//                                Test Cases //
/////////////////////////////////////////////////////////////////////////////////////////////

TEST_CASE("Input resource", "[unit-1]") {
    //REQUIRE(1 == 1);
    ERP* erp = new ERP();
    erp->addResource("2x4 Oak Plank", "price,1.50,quantity,1000,type,wood,region:string,New_Hampshire,weight:int,5kg/sqm");
    REQUIRE(erp->getPrice("2x4 Oak Plank") == 1.50);
    REQUIRE(erp->getQuantity("2x4 Oak Plank") == 1000);
    REQUIRE(erp->getType("2x4 Oak Plank") == "wood");
    REQUIRE(erp->getInfo("2x4 Oak Plank", "region") == "New_Hampshire");
    REQUIRE(erp->getInfo("2x4 Oak Plank", "weight") == "5kg/sqm");
}

TEST_CASE("Set Resources", "[unit-1]") {
    ERP* erp = new ERP();
    erp->addResource("Sheet metal", "price,10.50,quantity,500,type,steel,region:string,China");

    REQUIRE(erp->getPrice("Sheet metal") == 10.50);
    erp->setPrice("Sheet metal", 11.50);
    REQUIRE(erp->getPrice("Sheet metal") == 11.50);

    REQUIRE(erp->getQuantity("Sheet metal") == 500);
    erp->setQuantity("Sheet metal", 400);
    REQUIRE(erp->getQuantity("Sheet metal") == 400);

    REQUIRE(erp->getType("Sheet metal") == "steel");
    erp->setType("Sheet metal", "titanium");
    REQUIRE(erp->getType("Sheet metal") == "titanium");

    REQUIRE(erp->getInfo("Sheet metal", "region") == "China");
    erp->setInfo("Sheet metal", "region", "Japan", "titanium");
    REQUIRE(erp->getInfo("Sheet metal", "region") == "Japan");

}
