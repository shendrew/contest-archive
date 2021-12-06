#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
using namespace std;

#define f first
#define s second
int n;
double a[10001], b[10001];
double ans;

int main()
{
    cin >> n;
    for (int i=0; i<=n; i++)
    {
        cin >> a[i];
    }
    for (int i=0; i<n; i++)
    {
        cin >> b[i];
    }
    for (int i=1; i<=n; i++)
    {
        ans+=((a[i-1]+a[i])*b[i-1]);
    }
    cout << ans/2 << endl;
    return 0;
}
/*
3
2 3 6 2
4 1 1

1
4 4
3
*/