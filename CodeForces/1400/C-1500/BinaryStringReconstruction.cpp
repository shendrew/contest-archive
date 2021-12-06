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
        string str;
        int x, n;
        cin >> str >> x;
        n=str.size();
        vector<int> v;
        for (int i=0; i<n; i++)
        {
            v.push_back(1);
        }
        for (int i=0; i<n; i++)
        {
            if (!(str[i]-'0'))
            {
                if (i-x>=0)
                {
                    v[i-x]=0;
                }
                if (i+x<n)
                {
                    v[i+x]=0;
                }
            }
        }

        bool good=true;
        for (int i=0; i<n; i++)
        {
            if (str[i]-'0')
            {
                good=false;
                if (i-x>=0 && v[i-x])
                {
                    good=true;
                }
                if (i+x<n && v[i+x])
                {
                    good=true;
                }
                if (!good)
                {
                    break;
                }
            }
        }

        if (good)
        {
            for (auto &i: v)
            {
                cout << i;
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}

/*
3
101110
2
01
1
110
1
*/