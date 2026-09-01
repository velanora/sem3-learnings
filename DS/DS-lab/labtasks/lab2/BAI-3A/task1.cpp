#include<iostream>
using namespace std;

int* leaderElements(int *arr,int &size){
    int *newArr = new int[size];
    int count =0;
    bool leader = 1;
    for(int i=0; i<size; i++){
        leader =1;
        for(int j=i+1; j<size; j++)
            if(*(arr+i) < *(arr+j) ) leader = 0;

        if(leader == 1) {
            *(newArr+count) = *(arr+i); 
            count++;
        }
    }
    size = count;
    return newArr;
}

int main(){
    int n;
    cout<<"enter size:";
    cin>>n;
    int *ptr = new int[n];
    cout<<"Enter elements:";
    for(int i=0; i<n; i++){
        cout<<" ";
        cin>>*(ptr+i);
    }
    cout<<"\noriginal array:";
    for(int i=0; i<n; i++){
       cout<<" "<<*(ptr+i);
    }
    int *answer = leaderElements(ptr,n);
    cout<<"\nupdated:";
    for(int i=0; i<n; i++){
       cout<<" "<<*(answer+i);
    }
    delete[] answer;
    answer = nullptr;
    delete[] ptr;
    ptr = nullptr;

}