#include <iostream>
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
int n, t;
string s1, s2;
vector<int> same, diff;
char ans[100000];

int main()
{
    cin >> n >> t >> s1 >> s2;
    for (int i=0; i<n; i++)
    {
        if (s1[i]!='a' && s2[i]!='a')
        {
            ans[i]='a';
        }
        else if (s1[i]!='b' && s2[i]!='b')
        {
            ans[i]='b';
        }
        else
        {
            ans[i]='c';
        }
    }
    for (int i=0; i<n; i++)
    {
        if (s1[i]==s2[i])
        {
            same.push_back(i);
        }
        else
        {
            diff.push_back(i);
        }
    }
    
    int sm=(n-t)*2;
    for (int i=0; i<same.size(); i++)
    {
        if (sm==0)
        {
            break;
        }
        ans[same[i]]=s1[same[i]];
        sm-=2;
    }

    for (int i=0; i<diff.size(); i++)
    {
        if (sm==0)
        {
            break;
        }
        if (i%2)
        {
            ans[diff[i]]=s1[diff[i]];
        }
        else
        {
            ans[diff[i]]=s2[diff[i]];
        }
        sm--;
    }

    if (sm==0)
    {
        for (int i=0; i<n; i++)
        {
            cout << ans[i];
        }
    }
    else
    {
        cout << -1;
    }
    cout << endl;

    return 0;
}

/*
3 2
abc
xyc
*/