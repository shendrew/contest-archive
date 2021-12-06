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

int t;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;

        vector<int> v;
        while (b)
        {
            int exp=log2(b);
            b-=pow(2, exp);
            v.push_back(exp);
        }
        reverse(v.begin(), v.end());

        long long ans=1, pre=0, sqr=a;
        for (int i=0; i<v.size(); i++)
        {
            for (int j=0; j<v[i]-pre; j++)
            {
                sqr=(sqr*sqr)%MOD;
            }
            ans=(ans*sqr)%MOD;
            pre=v[i];
        }
        cout << ans << endl;
    }

    return 0;
}

/*
3
3 4
2 8
123 123
*/