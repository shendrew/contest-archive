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
int n;
long long ans, change;
set<long long> a;
map<long long, long long> slope;

int main()
{
    cin >> n;

    for (int i=0; i<n; i++)
    {
        long long p, w, d;
        cin >> p >> w >> d;
        p+=1000000000;
        a.insert(p-d);
        a.insert(p+d);
        slope[p-d]+=w;
        slope[p+d]+=w;
        ans+=(p-d)*w;
        change-=w;
    }

    long long pre=0, cur=ans;
    for (auto &i: a)
    {
        cur+=(i-pre)*change;
        ans=min(ans, cur);
        change+=slope[i];
        pre=i;
    }

    cout << ans << endl;
    return 0;
}

/*
1
0 1000 0

2
10 4 3
20 4 2

3
6 8 3
1 4 1
14 5 2

3
6 8 3
3 4 3
14 5 2
*/