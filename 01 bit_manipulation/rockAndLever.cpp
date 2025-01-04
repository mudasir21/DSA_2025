// given an array arr, print pairs such that for i < j, arr[i] & arr[j] > arr[i] xor arr[j]
#include<bits/stdc++.h>
using namespace std;

// idea: the most significant bits of both ai and aj would be 1 for a[i] & a[j] to be greater than a[i] xor a[j]
// if msb is not same, then xor would be always > AND , hence find pairs which have msb both 1

bool msb(int num1, int num2)
{
    int position_msb_n1 = int(log2(num1));
    int position_msb_n2 = int(log2(num2));

    if(position_msb_n1 == position_msb_n2)
    return true;

    else return false;
}

// brute
vector<pair<int, int>> findPairs(vector<int> nums)
{
    vector<pair<int, int>> res;
    for(int i = 0 ;i < nums.size() ; i++)
    {
        for(int j = i+1; j < nums.size(); j++)
        {
            if(msb(nums[i], nums[j]))  // both are 1 then they form a pair
            {
                res.push_back({nums[i], nums[j]});
            }
        }
    }

    return res;
}


int msb_bit_position(int num)
{
    return (int)log2(num);
}
// efficient : for each element, when you enter in array you check its msb, and keep the position of msb as key and enter in map, so all the elements coming(j > already present(index in array)) having same msb would be mapped to same key and hence count of pairs are sizeofmap/2, i store also the elements having same msb as values of key
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int size;
        cin >> size;
        vector<int> arr(size);
        unordered_map<int, vector<int> > mp;
        for (int i = 0; i < size; i++)
        {
            // int element;
            // cin >> element;
            // arr[i] = element; can also directly enter
            cin>> arr[i];

            mp[msb_bit_position(arr[i])].push_back(arr[i]);
        }

        // vector<pair<int, int>> res = findPairs(arr);
        // cout<<"\npairs are : ";
        // for(auto p : res)
        // {
        //     cout<<p.first <<" "<<p.second<<endl;
        // }

        // if each key has value as vector and vector has size > 1 then pairs formed are nC2 (order matters, if order doesn't matter and (i,j) and (j, i) are considered different then pairs = N(N-1))
        int count_pairs = 0;
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            int each_vec_size = (it->second).size();
            count_pairs += ((each_vec_size)*(each_vec_size-1))/2;
        }

        cout<<"total pairs : " <<count_pairs<<endl;


    }

}