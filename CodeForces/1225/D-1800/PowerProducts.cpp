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

int n, k;
int prime[100005];
set<pair<int, int>> require[100005], factor[100005];
map<set<pair<int, int>>, int> occ;
long long ans;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for (int i=2; i<=100000; i++)
    {
        if (!prime[i])
        {
            for (int j=i; j<=100000; j+=i)
            {
                prime[j]=i;
            }
        }
    }

    cin >> n >> k;
    for (int i=0; i<n; i++)
    {
        int num;
        cin >> num;
        set<pair<int, int>> f, want;
        while (num>1)
        {
            int div=prime[num], cnt=0;
            while (num%div==0)
            {
                cnt++;
                num/=div;
            }
            if (cnt%k)
            {
                f.insert({div, cnt%k});
            }
            if ((k-(cnt%k))%k)
            {
                want.insert({div, (k-(cnt%k))%k});
            }
        }
        occ[f]++;
        factor[i]=f;
        require[i]=want;
    }

    for (int i=0; i<n; i++)
    {
        ans+=occ[require[i]];
        if (require[i]==factor[i])
        {
            ans--;
        }
    }
    cout << ans/2 << endl;

    return 0;
}

/*
6 3
1 3 9 8 24 1
*/