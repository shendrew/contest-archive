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

ifstream fin("diamond.in");
ofstream fout("diamond.out");

#define f first
#define s second
#define ll long long
int n, k, ans;

int main()
{
    fin >> n >> k;
    vector<int> v(n), group(n), maxSuffix(n+1);
    for (int i=0; i<n; i++)
    {
        fin >> v[i];
    }
    sort(v.begin(), v.end());

    int r=0;
    for (int l=0; l<n; l++)
    {
        while (r<n-1 && v[r+1]-v[l]<=k)
        {
            r++;
        }
        group[l]=r-l+1;
    }

    for (int i=n-1; i>=0; i--)
    {
        maxSuffix[i]=max(maxSuffix[i+1], group[i]);
    }

    for (int i=0; i<n; i++)
    {
        cout << maxSuffix[i] << endl;
        ans=max(ans, group[i]+maxSuffix[i+group[i]]);
    }

    fout << ans << endl;

    return 0;
}