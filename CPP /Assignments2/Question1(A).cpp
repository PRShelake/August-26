#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Product
{
private:
    int productId;
    string name;
    double price;
    int quantity;

public:
    // Accept product details
    void acceptDetails()
    {
        cout << "Enter Product ID: ";
        cin >> productId;

        cout << "Enter Product Name: ";
        cin >> name;

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    // Display product details
    void displayDetails() const
    {
        cout << left << setw(8) << productId << setw(15) << name << setw(10) << fixed << setprecision(2) << price << setw(8) << quantity << setw(12) << totalValue();

        if (quantity < 10)
        {
            cout << "  LOW STOCK";
        }

        cout << endl;
    }

    // Calculate total value
    double totalValue() const
    {
        return price * quantity;
    }

    // Check low stock
    bool isLowStock(int threshold) const    //bool keyword means true of false; threshold => boundry stack
    {
        return quantity < threshold;
    }

    // Function to display highest value product
    void displayHighestProduct() const     // this function donot any return value they provide only out
    {
        cout << name << " (Rs. " << fixed << setprecision(2) << totalValue() << ")" << endl; // fixed - its is used to display decimal number in standerd decimal format
                                                                                             //  setprecision(2), example: 3.14322224 => 3.14
    }
};

int main()
{
    // in this hear i make Array of 5 Product objects on stack
    Product products[5]; //==>> products[0]; products[2]; products[2]; products[3]; products[4];

    // Accept details
    cout << "===== ENTER PRODUCT DETAILS =====" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "\nProduct " << i + 1 << endl;
        products[i].acceptDetails();
    }

    // Display all products
    cout << "\n\n===== INVENTORY REPORT =====" << endl;

    cout << left << setw(8) << "ID" << setw(15) << "Name" << setw(10) << "Price"<< setw(8) << "Qty" << setw(12) << "Total Value"<< endl;

    cout << "-------------------------------------------------------" << endl;

    for (int i = 0; i < 5; i++)
    {
        products[i].displayDetails();
    }

    // Find product with highest total value
    int highestIndex = 0;

    for (int i = 1; i < 5; i++)
    {
        if (products[i].totalValue() >
            products[highestIndex].totalValue())
        {
            highestIndex = i;
        }
    }

    cout << "\nHighest Value Product: ";
    products[highestIndex].displayHighestProduct();

    // Get threshold
    int threshold;

    cout << "\nEnter low stock threshold: ";
    cin >> threshold;

    // Display low stock products
    cout << "\nLow Stock Products (threshold: "<< threshold << "):" << endl;

    bool found = false;

    for (int i = 0; i < 5; i++)
    {
        if (products[i].isLowStock(threshold))
        {
            products[i].displayDetails();
            found = true;
        }
    }

    if (!found)
    {
        cout << "No products are below the threshold." << endl;
    }

    return 0;
}
