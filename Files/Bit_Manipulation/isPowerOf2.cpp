// #include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    /*
    n-1 : find the first set bit from the right , then flip all the bit bits after it
    after applying bitwise & (n & n-1) if all the bits are not set then return true or else false
    for ex= 128
    10000000
    01111111
    --------
    00000000
    for ex=129
    10000001
    10000001
    --------
    10000001
    */
    bool isPowerofTwo(long long n)
    {
        if (n <= 0)
            return false;
        if ((n & (n - 1)) == 0)
            return true;
        else
            return false;
    }
};

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        long long n;
        cin >> n;

        Solution ob;
        if (ob.isPowerofTwo(n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
