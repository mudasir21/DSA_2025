// given an array such that all elements are present twice except for two elements which are present once, find them
#include<bits/stdc++.h>
using namespace std;

// idea: if we do xor of all elements then its result would be xor of unique elements. Now find the right most set bit of the result and check which no's have this bit set and do xor of all such no's you would get first no. and second = initial result XOR first no. 

vector<int> uniqueElements(vector<int> nums)
{
    int num1=0, num2 = 0;
    int xorRes = 0;
    for(auto element : nums)
    xorRes ^= element;

    // now find position of right most set bit of xorRes
    // int setBit = log2((xorRes & (xorRes - 1))^ xorRes);    gives position of set bit
    int setBitNum = (xorRes & (xorRes - 1))^ xorRes;    // gives number with only right most set bit

    for(auto x: nums)
    {
        if(setBitNum & x)       // if it is non-zero that means the x has bit set at position i wanted
        {
            num1 = num1^x;

        }
    }

    num2 = xorRes ^ num1;

    return {num1, num2};


}
int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int size;
        cin>> size;
        vector<int> arr(size);
        for(int i = 0; i < size; i++)
        {
            int element;
            cin>> element;
            arr[i] = element;

        }

        vector<int> res = uniqueElements(arr);
        cout<<"two unique elements are : ";
        for(auto ele : res)
        cout<<ele<<" ";

        cout<<endl;
        
    }
}