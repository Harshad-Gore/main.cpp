#include <iostream>

class Product
{
public:
    float price;
    void setPrice(float p)
    {
        price = p;
    }
};

class DiscountedProduct : public Product
{
public:
    float discount;
    void setDiscount(float d)
    {
        discount = d;
    }
};

int main()
{
    Product p;
    p.setPrice(49.99);

    DiscountedProduct dp;
    dp.setPrice(49.99);
    dp.setDiscount(0.1);

    Product *basePtr = &dp;
    DiscountedProduct *derivedPtr = static_cast<DiscountedProduct *>(basePtr);

    float totalCost = derivedPtr->price * (1 - derivedPtr->discount);
    int totalItems = static_cast<int>(100 / totalCost);

    std::cout << "Total cost after discount: " << totalCost << std::endl;
    std::cout << "Total items that can be bought with $100: " << totalItems << std::endl;

    return 0;
}