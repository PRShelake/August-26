#include<iostream>
using namespace std;

double reorderCost(int qty, double unitPrice){
    // integer quantity
    return qty * unitPrice;

} 

double reorderCost(double qty, double unitPrice){    
    // fractional (by weight)
    return qty * unitPrice;
}

double reorderCost(int qty, double unitPrice, double taxRate){
    // with tax

    double cost = qty * unitPrice;
    return cost + (cost * taxRate / 100) ;

}

double applyDiscount(double price, double discountPercent = 10.0){
    // If no discount is passed, apply 10% by default

    return price - (price * discountPercent / 100);
    
}
int main(){
    int qty1;
    double qty2;
    double unitPrice1;
    double taxRate1;
    double discountPercent1;

    cout<< "Enter the quantity of the stock! : " ;
    cin>> qty1;
    cout<< "Enter the quantity of the stock in fractions " ;
    cin>> qty2;
    cout<< "Enter the price per unit : " ;
    cin>> unitPrice1;
    cout<< "Enter the percentage of tax : " ;
    cin>> taxRate1;
    cout<< "Enter the discount (If entered below 10 then by default 10 ) : " ;
    cin>> discountPercent1;
    

    double reorderCostValue = reorderCost(qty1,unitPrice1);
    cout<< "Reorder Cost is : " << reorderCostValue << endl;

    double reorderCostDouble = reorderCost(qty2,unitPrice1);
    cout<< "Reorder Cost of double is : " << reorderCostDouble << endl;

    double reorderCostTax = reorderCost(qty1 , unitPrice1 , taxRate1);
    cout<< "Price with tax is: " << reorderCostTax << endl;

    if(discountPercent1 < 10){
        cout << "Discount is: " << applyDiscount(qty1);
    }else{
        cout<< "Discount is: "<< applyDiscount(qty1 , discountPercent1);
    }

}
