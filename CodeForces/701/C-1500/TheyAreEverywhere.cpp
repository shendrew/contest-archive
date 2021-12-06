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
int n;
string str;

int main()
{
    cin >> n >> str;
    int type=0;
    map<char, int> cnt;
    for (int i=0; i<n; i++)
    {
        if (!cnt[str[i]])
        {
            type++;
        }
        cnt[str[i]]++;
    }
    if (type==1)
    {
        cout << 1 << endl;
        return 0;
    }

    cnt={};

    int ans=100001, r=0, uni=1;
    cnt[str[0]]++;
    for (int l=0; l<n; l++)
    {
        while (uni<type && r<n-1)
        {
            r++;
            cnt[str[r]]++;
            if (cnt[str[r]]==1)
            {
                uni++;
            }
        }
        if (uni==type)
        {
            ans=min(ans, r-l+1);
        }
        cnt[str[l]]--;
        if (cnt[str[l]]==0)
        {
            uni--;
        }
    }

    cout << ans << endl;

    return 0;
}

/*
6
aaBCCe
*/