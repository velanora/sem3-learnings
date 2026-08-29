#include <iostream>
#include<string>
#include<cctype> // required for toupper()
using namespace std;

int conversion(char *r, int size)
{
    int ans=0;
    for (int i = 0; i < size; i++){
        *(r+i) = toupper(*(r+i)); ;
        switch (*(r+i)){
        case 'I': ans += 1; break;
        case 'V':
            if(i!=0 && *(r+i-1) == 'I' ) ans -= 1*2;
            ans += 5;
            break;
        case 'X':
            if(i!=0 && *(r+i-1) == 'I' ) ans -= 1*2;
            ans += 10; break;
        case 'L':
            if(i!=0 && *(r+i-1) == 'X' ) ans -= 10*2;
            ans += 50; break;
        case 'C':
            if(i!=0 && *(r+i-1) == 'X' ) ans -= 10*2;
            ans += 100; break;
        case 'D':
            if(i!=0 && *(r+i-1) == 'C' ) ans -= 100*2;
            ans += 500; break;
        case 'M':
            if(i!=0 && *(r+i-1) == 'C' ) ans -= 100*2;
            ans += 1000; break;
        default:
            cout << "Warning: Invalid character '" << *(r + i) << "' skipped.\n";
            break;
        }
    }
    return ans;
}

int main()
{
    string roman_temp;
    cout << "Enter a roman number : ";
    cin>>roman_temp;
    int size = roman_temp.length();
    // I could have used roman_temp.c_str() instead of &roman_temp[0] in case of const variable (immutable) if i didn't updated the string to  Upper case characters.
    char * r = &roman_temp[0];   
    cout<<"You entered : "<<roman_temp<<endl;
    int ans = conversion(r,size);
    cout << "answer : " << ans << endl;
    return 0;
}