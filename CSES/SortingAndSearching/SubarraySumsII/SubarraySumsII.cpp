#include <iostream>
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

#define f first
#define s second
int n, x;
long long sum, ans;
map<long long, int> occ;

int main()
{
    cin >> n >> x;
    occ[0]=1;
    for (int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        sum+=a;
        ans+=occ[sum-x];
        occ[sum]++;
    }
    cout << ans << endl;
    return 0;
}

/*
5 7
2 -1 3 5 -2
*/