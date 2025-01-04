#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 1024;

    cout<<(31 - __builtin_clz(n))<<endl;
    cout<<int(log2(n))<<endl;
}