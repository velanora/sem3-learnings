#include<iostream>
using namespace std;

int single_nonRepeatingElement(int* arr,int size){
    int single = true;
    for(int i=0; i<size; i++){
        single = true;
        for(int j=i+1; j<size; j++){
            if( *(arr+i) == *(arr+j)){
                single = false;
            }
        }

        if(single)  return *(arr+i);
    }

}
int main(){
    int n;
    cout<<"Enter odd size of array : ";
    cin>>n;
    int *integers= new int[n];
    cout<<"Enter the elements: ";
    for(int i=0; i<n; i++){
        cin>>*(integers+i);
    }
    cout<<"Array : ";
    for(int i=0; i<n; i++) 
        cout<<" "<<*(integers+i);
    
    int ans = single_nonRepeatingElement(integers,n);
    cout<<"\nSingle non-Repeating Element : " <<ans<<endl;
    delete[] integers;

}