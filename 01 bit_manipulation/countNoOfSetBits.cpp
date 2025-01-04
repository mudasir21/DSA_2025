// given a number count number of set bits
/* there are different methods to do this
   1. keep left shifting and checking last bit if 1 count++ otherwise not
   2. keep iterating as many times as there are number of set bits which  coule be found using : n & (n-1)
   3. using inbuild function : __builtin_popcount(n);  // two underscores

*/

#include<iostream>
using namespace std;

int method1(int n)
{
    int count = 0;
    while(n != 0)
    {
        // if(n&1 == 1)
        // count++;
        count += (n&1);

        n = n>>1;
    }

    return count;
    // time complexity is (logn)

}

int FastMethod(int n)
{
    int count = 0;
    // here we remove the set bits from right side and hence the time complexity = O(no. of set bits)
    while(n > 0)
    {
        n = n & (n-1);
        count++;         // thus this loop will run as many times as there are set bits instead of whole number of bits in n which makes it faster
    }

    return count;

}

int main()
{
    int n;
    cout<<"enter number : ";
    cin>> n;

    cout<<"number of bits using method1 : "<<method1(n)<<endl;
    cout<<"number of bits using FastMethod : "<<FastMethod(n)<<endl;
    cout<<"number of bits using __builtin_popcount : "<<__builtin_popcount(n)<<endl;
}