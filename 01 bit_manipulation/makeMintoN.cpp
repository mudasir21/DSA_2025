// given two 32 bit numbers N and M , insert M into N between positions i and j
// example N = 10010010 , M = 1101 between i = 2 and j = 5 then N = 10110110

/* procedure:
   clear bits between i and j in N
   left shift M by i positions
   Perform OR between N and M
*/



#include<iostream>
#include<math.h>
using namespace std;

int clearBits(int N, int i, int j)
{
    int m1 = -1;  // complement of -1 would give all 32 bit 1's, you can also use ~(0)
    // left shift it j+1 times
    m1 = m1 << (j+1);

    int m2 = pow(2, i) - 1;
    // now m2 OR m1
    int mask = m2 | m1;
    
    //this mask will have all the bits clear between i and j
    cout<<"N and Mask is : "<<(N & mask)<<endl;
    return N & mask;



}

int main()
{
    int N, M;
    cout<<"enter two numbers : ";
    cin >> N >> M;

    cout<<"enter i and j :"; 
    int i, j;
    cin>> i>>j;

    N = clearBits(N, i, j);

    //left shift M by i positions
    M = M<<i;
    // now do N OR M
    int res = N | M;
    cout<<"Inserting M in N between i and j : "<<res<<endl;

}