// find number of set bits in range L to R(inclusive) in each test case
#include<iostream>
using namespace std;

int setbits(int num)
{
    int res = 0;
    while(num > 0)
    {
        num = (num & (num-1));
        res++;
    }

    return res;
}

// for each number from L to R, find the number of sets bits in it and add to sum
int findsetbits(int l, int r, int sum)
{
    for(int i = l; i <= r; i++)
    {
        sum += setbits(i);
    }

    return sum;
}
int main()
{
    int t;
    cout<<"test cases : ";
    cin>> t;
    while(t--)
    {
        int L, R;
        cout<<"\ntwo numbers : ";
        cin>> L >> R;
        int sum = 0;
        cout<<"\ntotal set bits from "<<L<<" to "<<R<<" =  "<< findsetbits(L, R, sum);
    }
}