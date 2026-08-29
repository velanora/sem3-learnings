#include<iostream>
using namespace std;

int main(){
    /*
    int a = 10;
    double b = 6.5;
    void *ptra = nullptr;
    ptra = &a;
    ptra = &b;

    cout<<(ptra)<<endl;
    cout<<static_cast<double *>(ptra)<<endl; // gives address
    cout<<*(static_cast<double *>(ptra))<<endl; // gives double

    */


    /*
    // we can't do arr = nullptr after assigning elements to array
    // exmp

    double marks[] = {64,80,74};
    double *ptrb = marks;
    // ! marks = nullptr 

    // Post increment
    // first value will be dereferenced than it will be incremented
    cout<< *ptrb++<<endl; 
    cout<< *ptrb++<<endl;
    cout<< *ptrb<<endl;

    */

    
    // In function paramters, int *arr is equal to int arr[]

    double sumarray(int size, double *arr){
        double sum = 0;
        for ( double mark : marks){
            cout<< mark << " ";
        }
    }

    char* fullName = "Ali khan";
    cout<<fullName + 4<<endl;

    

    
}