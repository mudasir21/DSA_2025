#include<iostream>
#include<vector>
#include<string>
using namespace std;

void filterSubstrings(int num, vector<string>& res, string str)
{
    string substring = "";
    int index = 0;
    while(num > 0)
    {
        if(num & 1)
        {
            substring += str[index];
        }
        num = num >> 1;
        index++;
    }

    res.push_back(substring);
}

vector<string> findAllSubstrings(string str)
{
    vector<string> res;
    int n = str.length();

    // total substrings = 2^n where n is no. of characters in string
    // bits set in each number corresponds to the substrings of str abc : for example 0 = 000 => substring = '', 1 = 001 => substring = 'a'(0 = c, 0=b, 1 = a) and so on for 6 = 110 => substring 'cb'
    for(int i = 0 ; i < 1<<n; i++)
    {
        filterSubstrings(i, res, str);
    }

    return res;

}
int main()
{
    string str;
    cout<<"enter string: ";
    getline(cin, str);

    vector<string> subsets = findAllSubstrings(str);
    cout<<"All subsets of string "<<str<<" are :"<<endl;
    int i = 1;
    for(auto it = subsets.begin(); it != subsets.end(); it++)
    {
        cout<<i<<" "<<*it<<endl;
        i++;
    }

}