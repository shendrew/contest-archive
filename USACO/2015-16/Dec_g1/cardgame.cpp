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

ifstream fin("cardgame.in");
ofstream fout("cardgame.out");

#define f first
#define s second
#define ll long long

int n, ans;

int main()
{
    fin >> n;
    vector<int> elsie(n), bessie, v;
    for (int i=0; i<n; i++)
    {
        fin >> elsie[i];
        v.push_back(elsie[i]);
    }
    sort(v.begin(), v.end());
    int ind=0;
    for (int i=1; i<=2*n; i++)
    {
        if (ind>=n || v[ind]!=i)
        {
            bessie.push_back(i);
            continue;
        }
        ind++;
    }

    vector<int> lb, hb, le, he;
    for (int i=0; i<n/2; i++)
    {
        lb.push_back(bessie[i]);
        he.push_back(elsie[i]);
    }
    for (int i=n/2; i<n; i++)
    {
        hb.push_back(bessie[i]);
        le.push_back(elsie[i]);
    }
    sort(he.begin(), he.end());
    sort(le.begin(), le.end(), greater<int>());
    sort(lb.begin(), lb.end(), greater<int>());

    n/=2;
    int l=0, r=0;
    for (; l<n; l++)
    {
        while (r<n-1 && hb[r]<he[l])
        {
            r++;
        }
        if (r<n && hb[r]>he[l])
        {
            ans++;
            r++;
        }
    }
    l=0, r=0;
    for (; l<n; l++)
    {
        while (r<n-1 && lb[r]>le[l])
        {
            r++;
        }
        if (r<n && lb[r]<le[l])
        {
            ans++;
            r++;
        }
    }

    fout << ans << endl;

    return 0;
}