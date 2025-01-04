// print out gray code sequence of N bits
#include<iostream>
#include<vector>
using namespace std;

// Gray code sequence has only one bit different between consecutive numbers
// for n bits => no's possible = 2^n => loop from 0 to 2^(n-1) and find gray code of each
// gray code of a number num is given by: (num )^(num >> 1)    (first bit as same to binar Right most, and then second bit Bk XOR Bk-1, third bit Bk-1 XOR Bk-2 and so on)
// also graycode to decimal
/*         if given gray code is : GkGk-1Gk-2 .. G1G0     (where Gi is ith bit of k bit gray code)
           then decimal is given by:
           Nk = Gk
           Nk-1 = Gk-1 ^ Nk
           Nk-2 = Gk-2 ^ Nk-1 
           ...
           N0 = G0 ^ N1
more info: https://cp-algorithms.com/algebra/gray-code.html
           
*/

vector<int> grayCode(int n)
{
    vector<int> res;
    // sequence of gray code of n bits
    for(int i = 0; i < 1<<n; i++)
    {
        int grayOfithNum = (i)^(i>>2);
        res.push_back(grayOfithNum);
    }

    return res;
}

int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int n;
        cin>> n;
        vector<int> graycode_sequence = grayCode(n);
    }
}