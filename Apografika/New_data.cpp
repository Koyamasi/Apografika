#include "New_data.h"

using namespace Apografika;

New_data::New_data
(DateTime purchaseDate,
    String^ supplier,
    String^ productName,
    int quantity,
    double init_price,
    double final_price,
    ProductType productType
)
{
    this->purchaseDate = purchaseDate; // No change needed here
    this->productName = productName;
    this->supplier = supplier;
    this->quantity = quantity;
    this->init_price = init_price;
    this->final_price = final_price;
    this->productType = productType; // Initialize product type
}
