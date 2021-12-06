#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <string>
using namespace std;

#define f first
#define s second
int n, start, finish;
int a[200001];
long long prefix[200001];
long long tot, ans;

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
        a[i+n]=a[i];
    }

    cin >> start >> finish;

    for (int i=1; i<=n*2; i++)
    {
        prefix[i]=prefix[i-1]+a[i];
    }

    int ind=finish-start;
    for (int i=1; i<=n; i++)
    {
        if ((prefix[i+ind-1]-prefix[i-1]>tot) || (prefix[i+ind-1]-prefix[i-1]==tot && (n+(start-i)%n)%n+1<ans))
        {
            tot=prefix[i+ind-1]-prefix[i-1];
            ans=(n+(start-i)%n)%n+1;
        }
    }

    cout << ans << endl;

    return 0;
}

/*
5
1 2 3 4 1
1 3
*/