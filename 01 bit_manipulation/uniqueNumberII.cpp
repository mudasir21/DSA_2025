// given an array which contains every element thrice except one, find that one number

#include<bits/stdc++.h>
using namespace std;

// idea: the sum of bits at each position would be either 3N(if unique number doesn't have set bit at this position) or 3N+1(if unique no. have set bit at this position)
// find sum of bits at each position and do form a number from those of corresponding position with modulo 3, the result number would be unique number

int singleNumber(vector<int> nums)
{
    //         doesn't work on negative numbers
    int resNum = 0;
        int cnt[64] = {0};      // constant space
        for(auto num : nums)
        {
            int j = 0;
            while(num > 0)
            {
                cnt[j] += num&1;
                num = num/2;
                j++;
            }
        }

        for(int i = 0; i < 64; i++)
        {
             resNum += (cnt[i]%3)*pow(2, i);
        }

        return resNum;

}

int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int size;
        cin >> size;
        vector<int> arr(size);

        for (int i = 0; i < size; i++)
        {
            int element;
            cin >> element;
            arr[i] = element;
        }

        int res = singleNumber(arr);


    }
}
