#include<iostream>
using namespace std;

int * findIndices(int *nums, int target,int size){
    int *ans = new int[2];
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if( *(nums+i) + *(nums+j) == target){
               *ans = i;
               *(ans+1) = j;
                return ans;
            }
        }
    }

    return 0;
}

int main(){
    int size;
    cout<<"Enter size :";
    cin>>size;
    int target;
    cout<<"Enter target :";
    cin>>target;
    int *arr = new int[size];
    cout<<"Enter the elements: ";
    for(int i=0; i<size; i++){
        cout<<" ";
        cin>>*(arr+i);
    }
    cout<<"nums= [";
    for(int i=0; i<size; i++){
        cout<<" "<<*(arr+i);
    }
    cout<<" ]\n";

    int *newArr = findIndices(arr,target,size);
    cout<<"Output = [";
    for(int i=0; i<2; i++){
        cout<<" "<<*(newArr+i);
    }
    cout<<" ]\n";

    delete[] newArr;
    delete[] arr;
    newArr = arr = nullptr;
}