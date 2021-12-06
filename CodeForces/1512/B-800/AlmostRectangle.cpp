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
        int n;
        cin >> n;
        bool found=false;
        pair<int,int> loc1, loc2;
        vector<vector<char>> v;
        v.resize(n);
        for (int j=0; j<n; j++)
        {
            string str;
            cin >> str;
            for (int k=0; k<n; k++)
            {
                v[j].push_back(str[k]);
                if (str[k]=='*')
                {
                    if (!found)
                    {
                        loc1={j, k};
                        found=true;
                    }
                    else
                    {
                        loc2={j, k};
                    }
                }
            }
        }

        if (loc1.f==loc2.f)
        {
            if (loc1.f<n-1)
            {
                v[loc1.f+1][loc1.s]='*';
                v[loc2.f+1][loc2.s]='*';
            }
            else
            {
                v[loc1.f-1][loc1.s]='*';
                v[loc2.f-1][loc2.s]='*';
            }
        }
        else if (loc1.s==loc2.s)
        {
            if (loc1.s<n-1)
            {
                v[loc1.f][loc1.s+1]='*';
                v[loc2.f][loc2.s+1]='*';
            }
            else
            {
                v[loc1.f][loc1.s-1]='*';
                v[loc2.f][loc2.s-1]='*';
            }
        }
        else
        {
            v[loc1.f][loc2.s]='*';
            v[loc2.f][loc1.s]='*';
        }
        for (auto &j: v)
        {
            for (auto &k: j)
            {
                cout << k;
            }
            cout << endl;
        }
    }

    return 0;
}

/*
6
4
..*.
....
*...
....
2
*.
.*
2
.*
.*
3
*.*
...
...
5
.....
..*..
.....
.*...
.....
4
....
....
*...
*...
*/