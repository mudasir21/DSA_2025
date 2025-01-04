// find range of numbers from l to r(inclusive)
#include<bits/stdc++.h>
using namespace std;
// brute is to iterate from l to r and find AND
// efficient: bitwise and would always produce a number less or equal to smaller number, hence we try to reach smaller number first and then do bitwise which would be and of range between left and right

int rangeBitwiseAND(int left, int right)
{
    while(right > left)
    right = right &(right - 1);

    return left & right;
}
int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int l, r;
        cin>> l>> r;

        int res = rangeBitwiseAND(l, r);
        cout<<"\nAND of numbers from L to R is : "<<res<<endl;
    }
}