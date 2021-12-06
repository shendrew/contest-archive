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
    while (t--)
    {
        long long n;
        cin >> n;
        int ans=0;
        string str=to_string(n/2050);
        for (int i=0; i<str.size(); i++)
        {
            ans+=str[i]-'0';
        }
        if (n%2050==0 && n>=2050)
        {
            cout << ans << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}

/*
6
205
2050
4100
20500
22550
25308639900
*/