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

long long a, b, ans;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> a >> b;

    for (int i=1; i<=b-1; i++)
    {
        long long n=a, m=((a*(a+1)/2)%MOD*b)%MOD;
        ans=(ans+(((n+m)*i)%MOD))%MOD;
    }

    cout << ans << endl;

    return 0;
}

/*
2 2
*/