#include<iostream>
using namespace std;

int removeDuplicates(int *arr,int n)
{
    int count = 0;
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++ )
            if( *(arr+i) == *(arr+j)){
                if(j == n-1){
                    *(arr+j) = 0;
                    continue;
                }
                for(int k=j; k<n; k++){
                    if(k == n-1){
                       *(arr+k) = 0;
                        continue;
                    }
                    *(arr+k) = *(arr+(k+1));
                }
                count++;
            }
        
    return count;
}

int main()
{
    int numbers[] = {1,1,4,2,4,7,2,9,4};
    int sizeN = 0;
    sizeN = sizeof(numbers)/sizeof(numbers[0]);
    cout<<"-------- Before updating the array ------- \n{";
    for(int i=0; i<sizeN; i++){
        if(i!=0)
            cout << ", ";
        cout<<*(numbers+i);
    }
    int newSize = 0;
    newSize = removeDuplicates(numbers, sizeN);
    cout<<"}\n------- After updating the array --------\n{";
    for(int i=0; i<newSize; i++){
        if(i!=0)
            cout << ", ";
        cout<<*(numbers+i);
    }
    cout<<"}"<<endl;
}

