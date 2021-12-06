#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <string>
using namespace std;

ifstream fin("div7.in");
ofstream fout("div7.out");
#define f first
#define s second
int n;
long long ans;
long long a[50000], prefix[50001], cows[50001];
vector<int> v;

int main()
{
    fin >> n;

    for (int i=0; i<n; i++)
    {
        fin >> a[i];
        a[i]%=7;
    }

    int pre=1;
    for (int i=0; i<n; i++)
    {
        if (a[i] || pre)
        {
            v.push_back(a[i]);
        }
        pre=a[i];
        cows[v.size()]=i+1;
    }

    for (int i=1; i<=v.size(); i++)
    {
        prefix[i]=prefix[i-1]+v[i-1];
    }

    bool done=false;
    for (int i=v.size(); i>=1; i--)
    {
        for (int j=v.size(); j>=i; j--)
        {
            if ((prefix[j]-prefix[j-i])%7==0)
            {
                ans=max(ans, cows[j]-cows[j-i]);
                done=true;
            }
        }
    }

    fout << ans << endl;

    return 0;
}