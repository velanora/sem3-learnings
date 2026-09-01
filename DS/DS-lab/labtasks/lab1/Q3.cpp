// 3 Rearrange Positive and Negative Values
#include<iostream>
using namespace std;

void rearrangeArray(int* arr, int size)
{
    // two pointer approach 
    int left =0;
    int right = size-1;
    for(int a=0; a<size; a++){
        if(*(arr+left)<0 ) left++;
        else if( *(arr+right)>=0) right--;
        else if( *(arr+left)>=0 && *(arr+right)<0) swap(*(arr+left),*(arr+right));
    }
}
int main(){
    int numbers[] = {4,-2, 7, -8, 3, -1, 5};
    int Nsize = sizeof(numbers)/ sizeof(numbers[0]);
    cout<<"--------- Values Before rearranging Numbers ---------\n{ ";
    for(int num : numbers)
        cout<<num<<" ";
    cout<<"}\n";
    rearrangeArray(numbers, Nsize);
    cout<<"--------- Values After rearranging Numbers ---------\n{ ";
    for(int num : numbers)
        cout<<num<<" ";
    cout<<"}\n";
    return 0;

}