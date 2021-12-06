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
ifstream fin("hps.in");
ofstream fout("hps.out");

#define f first
#define s second
#define mx 100001
int n, ans;
int ph[mx], pp[mx], ps[mx];

int main()
{
    fin >> n;
    for (int i=1; i<=n; i++)
    {
        ph[i]=ph[i-1];
        pp[i]=pp[i-1];
        ps[i]=ps[i-1];
        char c;
        fin >> c;
        if (c=='H')
        {
            ph[i]++;
        }
        else if (c=='P')
        {
            pp[i]++;
        }
        else
        {
            ps[i]++;
        }
    }

    for (int i=1; i<=n; i++)
    {
        ans=max(ans, max(ph[i], max(pp[i], ps[i])) + max(ph[n]-ph[i], max(pp[n]-pp[i], ps[n]-ps[i])));
    }
    fout << ans << endl;

    return 0;
}
