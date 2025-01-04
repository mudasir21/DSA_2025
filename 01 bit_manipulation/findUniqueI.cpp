#include<iostream>
using namespace std;

// the approach is :
/* if there were only duplicated(thrice's) then each number occurs thrice and 
   hence no. of bits at each position is multiple of 3. when a unique number is
   included it either adds one bit at each position(if 1 at that position) or
   remains same(if 0 at that position).

   create an array of 64 bits(maximum number would have 64 bits-64 bit architecture)
   for each number add the bits at position to index i, hence array would contain 
   no. of bits at each position, now find modulo 3 at each position, i.e eliminate
   all numbers occuring thrice, remained is only unique element.


   ***
   This method can be expanded to five elements => 5N or 5N+1 at each position of array similarly any number of occurences of each element
*/

int main()
{
    int n;
    cout<<"enter no. of numbers : ";
    cin>> n;
    // O(1) space coz it is not varying with n
    int arr[64] = {0};

    // for each number enter into array
    for(int i = 0 ; i < n ; i++)
    {
        int no;
        cin>> no;
        int indexarr = 0;      // for each number store the set and unset bits at specific positions
        while(no > 0)
        {
            int last_bit = (no&1);
            arr[indexarr] += last_bit;
            indexarr++;

            no = no>>1;
        }
    }

    int p = 1;       // keeps track of index and hence multiplies by 2; example index zero has 2^0 = 1 = p, index 1 has 2^1 = 2 = p and so on =>keep updating p according to position of index
    int res = 0;
    for(int i = 0 ; i< 64; i++)
    {
        arr[i] = (arr[i]%3);   // remained is of unique element and hence create unique element back
        res += (arr[i]*p);
        p = p <<1;           // p = p*2
    }

    cout<<endl<<"unique element from given numbers is : "<<res;

}