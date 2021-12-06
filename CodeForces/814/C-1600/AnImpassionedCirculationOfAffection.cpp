#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <numeric>
#include <math.h>
#include <string>
#include <string.h>
using namespace std;

#define f first
#define s second
#define ll long long
int n, q;
string str;
vector<int> gap[26];
map<char, bool> appear;

int main()
{
    cin >> n >> str >> q;
    for (char i='a'; i<='z'; i++)
    {
        int ind=0;
        for (; ind<n; ind++)
        {
            if (str[ind]==i)
            {
                appear[i]=1;
                break;
            }
        }
        int pre=ind, cur=ind+1;
        while (cur<n)
        {
            if (str[cur]==i)
            {
                gap[i-'a'].push_back(cur-pre-1);
                pre=cur;
            }
            cur++;
        }
    }

    while (q--)
    {
        int m, ans=0;
        char c;
        cin >> m >> c;
        int r=0, cost=0;
        for (int l=0; l<gap[c-'a'].size(); l++)
        {
            if (l>r)
            {
                r=l;
                cost=0;
            }
            while (r<gap[c-'a'].size() && cost+gap[c-'a'][r]<=m)
            {
                cost+=gap[c-'a'][r];
                r++;
            }
            ans=max(ans, min(r-l+1+m, n));
            cost-=gap[c-'a'][l];
        }
        if (!appear[c])
        {
            cout << m << endl;
        }
        else
        {
            cout << min(n, max(ans, m+1)) << endl;
        }
    }

    return 0;
}

/*
6
koyomi
3
1 o
4 o
4 m
*/