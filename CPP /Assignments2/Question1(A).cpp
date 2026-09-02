#include<iostream>
using namespace std;

class IMS{
    static int productId;
    string name;
    double price;
    int quantity;
    int thisID;

public:
    IMS(){
        thisID = ++productId;
    }
    //setter
    void setName (const string& n){
        if(n != "" && n != " "){
            name = n;
        }
        else{
            cout<<"Name cannot be empty!"<<endl;
        }
    }

    void setPrice(double p){
        price = p;
    }

    void setQuantity(int q){
        if(q > 0){
            quantity = q;
        }
    }

    

    //getter
    int getQuantity()const {
        return this->quantity;
    }

    string getName()const {
        return name;
    }
    
    double getPrice() const {
        return this->price;
    }

    int getProductId() const {
        return this->thisID;
    }


    void acceptDetails(){
        // Read all fields from user
     
        string name;
        double price;
        int quantity;

        cout<<"Enter the name!!"<<endl;
        cin>>name;
        setName(name);

        cout<< "Enter the price!!" <<endl;
        cin>>price;
        if(price > 0){
            setPrice(price);
        }else{
            cout<< "Enter the right price!!!"<<endl;
        }
        
        cout<< "Enter the quantity!!" <<endl;
        cin>>quantity;
        setQuantity(quantity);

    } 
    void displayDetails(int threshold) const{
        double price = getPrice();
        int quantity = getQuantity();
        double totalValue = totalValue1(price,quantity);

        bool stock = isLowStock(threshold);

        cout<<"===== INVENTORY REPORT ====="<<endl;
        cout<<"ID \tName \tprice \tQty \tTotal Value"<<endl;
        cout<<getProductId() << "\t" << getName() << "\t" <<price << "\t" << quantity << "\t" << totalValue << (stock?" \t\t<-LOW STOCK" : "") << endl ;

    } // Print formatted product info
    double totalValue1(double price , int quantity) const{
        return price* quantity;

    }
        // price * quantity
    bool isLowStock(int threshold) const{
        int quantity = getQuantity();

        if(quantity < threshold){
            return true;
        }else{
            return false;
        }
    } // true if quantity < threshold

    void highestValueProduct(IMS ims[] , int size){
        int price = ims[0].getPrice();
        int quantity = ims[0].getQuantity();
        string productName = ims[0].getName();

        int maxValue = price * quantity;

        for(int i = 1 ; i<size ; i++){
            price = ims[i].getPrice();
            quantity = ims[i].getQuantity();
            int totalValue = price * quantity;
            if(totalValue > maxValue ){
                maxValue = totalValue;
                productName = ims[i].getName();
            }
        }

        cout<< "Highest Value Product : "<< productName <<" (Rs. "<< maxValue << " ) " <<endl;
        
    }

    void lowStockThreshold(IMS ims[] , int size , int threshold){
        cout<< "Low Stock (threshold: "<<threshold<<" ) : ";
        for(int i = 0; i < size ; i++ ){
            if(ims[i].getQuantity() <= threshold){
                cout<< ims[i].getName() << " , ";
            }
        }
    }

};

int IMS::productId = 1000;

int main(){
    int size;
    cout<<"Enter the size of the array : ";
    cin>> size;

    int threshold;
    cout<< "Enter the threshold : ";
    cin>>threshold;

    IMS ims[size];

    for(int i = 0;i<size;i++){
        cout<<"------- Enter the data for PRODUCT -------  " << i+1 << endl;
        ims[i].acceptDetails();
    }

    for(int i = 0;i<size;i++){
        ims[i].displayDetails(threshold);
    }

    IMS i1;
    i1.highestValueProduct(ims , size);
    i1.lowStockThreshold(ims,size,threshold);
    return 0;
}
