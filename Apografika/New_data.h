#pragma once

using namespace System;

namespace Apografika {

    public enum class ProductType {
        Type1,
        Type2,
        Type3
    };

    public ref class New_data
    {
    public:
        DateTime purchaseDate; // Change to value type
        String^ supplier;
        String^ productName;
        int quantity;
        double init_price;
        double final_price;
        ProductType productType; // New variable for product type

        New_data(DateTime purchaseDate,
            String^ supplier,
            String^ productName,
            int quantity,
            double init_price,
            double final_price,
            ProductType productType
            );
    };
}
