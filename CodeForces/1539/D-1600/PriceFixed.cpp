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
#define ll long long
int n;
long long sum;

int main()
{
    cin >> n;
    vector<pair<long long, long long>> v(n);
    for (int i=0; i<n; i++)
    {
        long long a, b;
        cin >> a >> b;
        sum+=a;
        v[i]={b,a};
    }
    sort(v.begin(), v.end());
    
    long long ind=1, start, finish, ans=sum*2;
    for (int i=0; i<n; i++)
    {
        if (ind>sum)
        {
            break;
        }
        start=max(ind, v[i].f+1);
        finish=min(sum, start+v[i].s-1);
        ans-=max((ll) 0, finish-start+1);
        ind=finish+1;
    }

    cout << ans << endl;

    return 0;
}

/*
5
2 7
2 8
1 2
2 4
1 8
*/