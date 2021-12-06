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

const int MOD=1e9+7;

long long solve(long long n, long long m)
{
    vector<long long> v;
    while (m)
    {
        long long exp=log2(m);
        m-=pow(2, exp);
        v.push_back(exp);
    }
    reverse(v.begin(), v.end());

    long long ans=1, pre=0, sqr=n;
    for (int i=0; i<v.size(); i++)
    {
        for (int j=0; j<v[i]-pre; j++)
        {
            sqr=(sqr*sqr)%MOD;
        }
        ans=(ans*sqr)%MOD;
        pre=v[i];
    }
    return ans;
}

int t;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        long long a, b, c;
        cin >> a >> b >> c;

        b=solve(b, c);
        cout << solve(a, b) << endl;
    }

    return 0;
}

/*
3
3 7 1
15 2 2
3 4 5
*/