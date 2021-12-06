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

ifstream fin("shuffle.in");
ofstream fout("shuffle.out");

#define f first
#define s second
#define ll long long

int n, ans;
int a[100005], vis[100005];

int main()
{
    fin >> n;
    for (int i=1; i<=n; i++)
    {
        fin >> a[i];
    }

    for (int i=1; i<=n; i++)
    {
        if (!vis[i])
        {
            map<int, int> ind;
            int p=1, cur=i;
            while (1)
            {
                if (vis[cur])
                {
                    if (ind[cur])
                    {
                        ans+=p-ind[cur];
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
                vis[cur]++;
                ind[cur]=p;
                cur=a[cur];
                p++;
            }
        }
    }

    fout << ans << endl;

    return 0;
}