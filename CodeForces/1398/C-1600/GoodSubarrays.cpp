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
int t;

int main()
{
    cin >> t;
    while (t--)
    {
        int n;
        string str;
        cin >> n >> str;
        long long sum=0, ans=0;
        map<long long, long long> occ;
        occ[0]=1;
        for (int i=0; i<n; i++)
        {
            sum+=str[i]-'0';
            ans+=occ[sum-(i+1)];
            occ[sum-(i+1)]++;
        }

        cout << ans << endl;
    }

    return 0;
}

/*
3
3
120
5
11011
6
600005
*/