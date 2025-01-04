// find all the prime numbers strictly lesser than N         ========> Sea of Erathosthenes
#include<iostream>
#include<vector>
using namespace std;
bool isPrime(int num)
{
    for(int i = 2; i*i <= num; i++)
    {
        if(num %i == 0)
        return false;
    }

    return true;
}

int countPrimes(int n)
{
    // effiecinet => Sieve of erathosthenes
    if(n == 0 || n == 1)
    return 0;

    vector<bool> primes(n, true);

    for(int i = 2; i*i <= n; i++)
    {
        for(int j = i*i; j<= n; j+=i)        // becoz step is multiple of i, for example i = 5 (prime) then go to next multiple of 5 i.e 2*5 = 10 and then next multiple of 5 = (10)+i(=5) = 15 and so on
        {
            primes[j] = 0;
        }
    }

    // now count the remaining 1's in primes those are actual prime numbers
    int count = 0;
    for(int i = 2; i<= n; i++)
    {
        if(primes[i])
        count++;
    }
    return count;

}

int countPrimes2(int n)
{
    // better approach
    // create an array of n+1 size and assume everyone as prime, but as you visit a prime from start, then all its multiples would eliminate to be prime and so on, we create size of n+1 to also include the number n coz zero based indexing
    vector<int> primes(n);
    for(int i = 2; i<= n; i++)
    primes[i] = 1;                    // assuming all prime

    for(int i = 2; i <= n; i++)
    {
        for(int j = 2*i; j<= n; j+=i)        // becoz step is multiple of i, for example i = 5 (prime) then go to next multiple of 5 i.e 2*5 = 10 and then next multiple of 5 = (10)+i(=5) = 15 and so on
        {
            primes[j] = 0;
        }
    }

    // now count the remaining 1's in primes those are actual prime numbers
    int count = 0;
    for(int i = 2; i<= n; i++)
    {
        if(primes[i])
        count++;
    }
    return count;


}
int countPrimes1(int n)    // changed name to keep it here without erasing
{
    // brute force => O(N*sqrt(N))        => giving TLE in 20/60 test case
    int count = 0;
    for(int i = 2; i < n ; i++)  // 37 has prime only itself but we have to find primes < n 
    {
        if(isPrime(i))
        count++;
    }

    return count;
}

int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int n;
        cin>> n;

        cout<<"Number of primes below n are : ";
        int count = countPrimes(n);     // for all primes instead of count create a vector and recieve vector instead of count;
        cout<<count<<endl;
    }
}