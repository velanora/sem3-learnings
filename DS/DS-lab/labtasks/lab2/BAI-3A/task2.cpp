#include<iostream>
using namespace std;
int * sumArray(int *temp_arr1,int *temp_arr2,int size){
    int *sum = new int[size];
    for(int i =0; i<size; i++)
        *(sum+i) = *(temp_arr1+i) + *(temp_arr2+i);
    return sum;
};

int * diffArray(int *temp_arr1,int *temp_arr2,int size){
    int *diff = new int[size];
    for(int i =0; i<size; i++)
        *(diff+i) = *(temp_arr1+i) - *(temp_arr2+i);
    return diff;
};

int * productArray(int *temp_arr1,int *temp_arr2,int size){
    int *product = new int[size];
    for(int i =0; i<size; i++)
        *(product+i) = (*(temp_arr1+i)) * (*(temp_arr2+i));
    return product;
};

int main(){
    int n;
    cout<<"Enter size of arrays : ";
    cin>>n;
    int *arr1 = new int[n];
    int *arr2 = new int[n];
    cout<<"\nEnter elements of array 1:";
    for(int i=0; i<n; i++){
        cout<<" ";
        cin>>*(arr1+i);
    }
    cout<<"\nEnter elements of array 2:";
    for(int i=0; i<n; i++){
        cout<<" ";
        cin>>*(arr2+i);
    }
    cout<<"\narray 1:";
    for(int i=0; i<n; i++){
       cout<<" "<<*(arr1+i);
    }
    cout<<"\narray 2:";
    for(int i=0; i<n; i++){
       cout<<" "<<*(arr2+i);
    }
    int *sum = sumArray(arr1,arr2,n);
    cout<<"\nSum of arrays:";
    for(int i=0; i<n; i++){
       cout<<" "<<*(sum+i);
    }
    int *diff = diffArray(arr1,arr2,n);
    cout<<"\nSum of arrays:";
    for(int i=0; i<n; i++){
       cout<<" "<<*(diff+i);
    }
    int *product = sumArray(arr1,arr2,n);
    cout<<"\nSum of arrays:";
    for(int i=0; i<n; i++){
       cout<<" "<<*(product+i);
    }

    delete[] arr1,arr2,sum,diff,product;
    arr1=arr2=sum=diff=product = nullptr;
    return 0;
}