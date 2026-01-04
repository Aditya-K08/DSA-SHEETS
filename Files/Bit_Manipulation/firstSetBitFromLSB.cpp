// #include<bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    unsigned int getFirstSetBit(int n)
    {
        for (unsigned int i = 0; i < sizeof(int) * 8; i++)
        {
            if (n & (1 << i))
            {
                return i + 1;
            }
        }
        return 0;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        printf("%u\n", ob.getFirstSetBit(n));
    }
    return 0;
}