// given two numbers, find the new number from them such that it has ith bit as 1 if the bits of given number's ith bit differ otherwise it is 0(i.e if they are same)
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int main()
{
    int t;
    cin>> t;
    while (t--)
    {
        int n1,n2;
        cin>> n1>> n2;    // they are of same length i.e having same number of bits
        int newNo = 0;
        int ith = 0;

        while(n1 > 0)
        {
            if((n1 & 1) != (n2 & 1))
            {
                newNo += pow(2, ith);
            }

            ith++;
            n1 = n1 >> 1;
            n2 = n2 >> 1;


        }

        cout<<"\nnew number formed is : " << newNo;
        cout<<endl;

    }
    


}