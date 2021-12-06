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

ifstream fin("lazy.in");
ofstream fout("lazy.out");

#define f first
#define s second
int n, k, ans;
int prefix[401][401];

int calc (int i, int l, int r)
{
    return prefix[i][min(n, r)]-prefix[i][max(0, l)];
}

int main()
{
    fin >> n >> k;

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            int g;
            fin >> g;
            prefix[i][j]=prefix[i][j-1]+g;
        }
    }

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            int sum=0;
            for (int e=k; e>=1; e--)
            {
                if (i+e>n)
                {
                    continue;
                }
                sum+=calc(i+e, j-(k-e)-1, j+(k-e));
            }
            sum+=calc(i, j-k-1, j+k);
            for (int e=1; e<=k; e++)
            {
                if (i-e<1)
                {
                    continue;
                }
                sum+=calc(i-e, j-(k-e)-1, j+(k-e));
            }
            ans=max(ans, sum);
        }
    }

    fout << ans << endl;

    return 0;
}