#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter n : "<<endl;
    cin>> n;

    int k = 1;
    while(k <= n)
    {
        k = k*2;
    }

    // now k is maximum power of 2 from 0 to n
    //set bits = for 0nes place 2^k/2 times, for tens place 2^k/2 , for hundrends place 2^k/2 and so on until 2^k

    //after 2^k remained numbers = n - 2^k, they will have all , first bit set => set bits += ( n - 2^k) times and remaining are set bits of n>>2 for these (n-2^k) numbers

    while(1)
    {

    }

}

// i have written how to clear bits between i and j in program makeMintoN, clear can be done same ways

