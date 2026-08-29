#include<iostream>
#include <climits>
using namespace std;

int find_second_smallest(int n, int *arr)
{
    // storing the largest possible number a integer can hold
    int smallest = INT_MAX;
    int second_smallest = INT_MAX;
    for(int i=0; i<n; i++){
        // smallest number
        if( *(arr+i)<smallest){
            second_smallest = smallest;
            smallest = *(arr+i);
        }
        //second smallest number
        else if( *(arr+i)<second_smallest && *(arr+i)!= smallest )
            second_smallest = *(arr+i);
    }
    return second_smallest;
}
int main(){
    int numbers[] = {10, 8, 5, 10, 3, 5};
    int Nsize = sizeof(numbers)/ sizeof(numbers[0]);
    cout<<"--------- Numbers ---------\n{ ";
    int count =0;
    for(int num : numbers){
        if(count>0)
            cout << ", ";
        cout<<num;
        count++;
    }
    int sec_smallest;
    sec_smallest = find_second_smallest(Nsize,numbers);
    cout<<" }\nSecond smallest number: "<<sec_smallest<<endl;
    return 0;
}