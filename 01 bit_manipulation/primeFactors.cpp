#include<iostream>
#include<vector>
using namespace std;
vector<int> primeFactors(int num)
{

}
int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int n;
        cin>> n;

        vector<int>res = primeFactors(n);
        for(auto x: res)
        cout<<x<<" ";

        cout<<endl;
    }
}