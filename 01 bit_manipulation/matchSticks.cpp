// Given array : arr[] = [2,1,1,2,2] , make square out of it: for example here it is possible: one side = 1+1, other sides are 2,2,2
#include<bits/stdc++.h>
using namespace std;

bool backtrackSticks(vector<int> nums, int lenOfEachSide, int index, vector<int> sides)
{
    if(index == nums.size())
    {
        return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
    }
    
    for(int i = 0; i < 4; i++)
    {
        // for each side we are trying to find side length
       if(sides[i] + nums[index] > lenOfEachSide) continue;
       /*optimization: if i have checked for a side why bother to check for that side again, just leave that side if you already have evaluated that*/
       int j = i;
       while(--j >= 0)
       {
            if(sides[j] == sides[i])
            break;
       }

       if(j != -1)
       continue;

       sides[i] = sides[i] + nums[index];
        if(backtrackSticks(nums, lenOfEachSide, index+1, sides))
        return true;

        // and when you find for one side, then for to next and reduce size of side if current stick doesn't favour to find solution
        sides[i] = sides[i] - nums[index];
        // cout<<"dobe"<<endl;
    }

    return false;
}

bool squareFromMatchsticks(vector<int> nums)
{
    int sum = 0;
    for(int x: nums)
    sum += x;

    int lenOfEachSide = sum/4;
    if(lenOfEachSide*4 != sum)           // if not possible to form square from given array
    return false;

    // sort in reverse order so that if an element(largest) > lenOfEachSide then we know that it is not possible to form squaer
    sort(nums.begin(), nums.end(), greater<>());
    vector<int> sides(4);

    return backtrackSticks(nums, lenOfEachSide, 0, sides); // 0=> to start from first element of nums and keep track of elements
}
// the idea is to check all possibilites if the square can be formed
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<int> nums;
        int size;
        cout<<"enter size";
        cin>> size;
        for(int i = 0 ; i < size; i++)
        {
            int element;
            cin>>element;
            nums.push_back(element);
        }

        if(squareFromMatchsticks(nums))
        cout<<"TRUE : Possible to form square from match sticks"<<endl;

        else
        cout<<"FALSE: Impossible to form square from match sticks"<<endl;

    }
}