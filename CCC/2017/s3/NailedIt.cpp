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
int n, ans1, ans2;
map<int, int> occ, sum;

int main()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int l;
        cin >> l;
        occ[l]++;
    }

    for (int i=1; i<=2000; i++)
    {
        if (occ[i])
        {
            sum[2*i]+=occ[i]/2;
            for (int j=i+1; j<=2000; j++)
            {
                sum[i+j]+=min(occ[i], occ[j]);
            }
        }
    }
    
    for (int i=1; i<=4000; i++)
    {
        if (ans1 < sum[i])
        {
            ans1=sum[i];
            ans2=1;
        }
        else if (ans1 == sum[i])
        {
            ans2++;
        }
    }

    cout << ans1 << " " << ans2 << endl;

    return 0;
}

/*
4
1 2 3 4
*/