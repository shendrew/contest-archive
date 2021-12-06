#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <string>
using namespace std;

#define f first
#define s second
int t;

int main()
{
    cin >> t;
    for (int i=0; i<t; i++)
    {
        long long n;
        cin >> n;

        while (true)
        {
            long long sum=0;
            string str=to_string(n);
            for (int j=0; j<str.size(); j++)
            {
                sum+=(int)str[j]-(int)'0';
            }
            int gcd=sum;
            while(gcd)
            {
                if (n%gcd==0 && sum%gcd==0)
                {
                    break;
                }
                gcd--;
            }
            if (gcd>1)
            {
                break;
            }
            n++;
        }
        
        cout << n << endl;
    }

    return 0;
}
/*
3
11
31
75
*/