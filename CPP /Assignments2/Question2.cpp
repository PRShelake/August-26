#include<iostream>
#include<memory>
using namespace std;

class Patient{
    int patientId;
    string name;
    int age;
    string ward;
    const string bloodGroup;
public: 

    // GETTERS
    int getpatientId() const {
        return patientId;
    }

    string getPatientName() const{
        return name;
    }

    int getAge() const {
        return age;
    }

    string getWard() const {
        return ward;
    }

    string getBloodGroup()const{
        return bloodGroup;
    }

    // SETTERS

    void setPatientId(int patientId){
        this-> patientId = patientId;
    }

    void setPatientName(const string& patientName){
        name = patientName;
    }

    void setAge(int patientAge){
        age = patientAge;
    }

    void setWard(const string& ward){
        this-> ward = ward;
    }


    // Constructor 1 — Default: id=0, name="Unknown", age=0, ward="General",
    Patient(): patientId(0) , name("Unknown") , age(0) , ward("General") , bloodGroup("O+"){
        cout<< "Default Patient Registered!" << endl;
    }

    // Constructor 2 — Emergency admission: only id and name known
    Patient(int id, const string& name) : bloodGroup("O+"),  age(0) , ward("General"){
        patientId= id;
        this->name = name;
        cout<< "Emergency Patient Registered !!"  << name << endl;
    }

    // Constructor 3 — Full admission details
    Patient(int id, const string& name, int age, const string& ward, const string& bg) : bloodGroup(bg){
        patientId = id;
        this-> name = name;
        this -> age = age;
        this -> ward = ward;
        cout<< "Normal Patient Registered!" << endl;
    }

    // Destructor — print "Patient <name> discharged." when object is destroyed
    ~Patient(){
        cout<< name << " discharged !!!" << endl;
    }

    void displayRecord() const{
        cout<< "Patient Record:" << endl;
        cout<< "ID\t : " << getpatientId() << endl;
        cout<< "Name\t : " << getPatientName() << endl;
        cout<< "Age\t : " << getAge() << endl;
        cout<< "Ward\t : " << getWard() << endl;
        cout<< "BloodGroup\t : " << getBloodGroup() << endl;

    }
    void transferWard(const string& newWard){
        ward = newWard;
        cout<< "Ward Transfer:  : " << getPatientName() << "-> " << newWard <<endl;
    }

};



int main(){

    Patient p1;

    Patient p2(1001, "MUNNABHAI");

    Patient p3(1002, "SELMON BHAI" , 43 , "NORMAL" , "B-");

    Patient *arr = new Patient[4];
    p3.displayRecord();

    for(int i = 0;i<4;i++){
        arr[i].displayRecord();
    }
    p3.transferWard("ICU");

    delete[] arr;

}
