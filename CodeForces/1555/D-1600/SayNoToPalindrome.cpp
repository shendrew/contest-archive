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
#include <iomanip>
#include <functional>
using namespace std;

#define f first
#define s second
#define ll long long

int n, m;
string str;
int preA[200005][3], preB[200005][3], preC[200005][3];

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> str;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++)
    {
        a[i]=int(str[i-1])-96;
    }

    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<3; j++)
            preA[i][j]=preA[i-1][j];

        for (int j=0; j<3; j++)
            preB[i][j]=preB[i-1][j];
        
        for (int j=0; j<3; j++)
            preC[i][j]=preC[i-1][j];

        if (a[i]==1)
        {
            preA[i][i%3]++;
        }
        else if (a[i]==2)
        {
            preB[i][i%3]++;
        }
        else if (a[i]==3)
        {
            preC[i][i%3]++;
        }
    }

    while (m--)
    {
        int l, r;
        cin >> l >> r;
        int good=0;
        for (int ai=0; ai<3; ai++)
        {
            for (int bi=0; bi<3; bi++)
            {
                for (int ci=0; ci<3; ci++)
                {
                    if (ai!=bi && ai!=ci && bi!=ci)
                    {
                        good=max(good, preA[r][ai]-preA[l-1][ai]+preB[r][bi]-preB[l-1][bi]+preC[r][ci]-preC[l-1][ci]);
                    }
                }
            }
        }
        cout << r-l+1-good << endl;
    }

    return 0;
}

/*
5 4
baacb
1 3
1 5
4 5
2 3
*/