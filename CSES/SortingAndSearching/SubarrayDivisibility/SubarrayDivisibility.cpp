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
int n, sum;
long long ans;
map<int, int> occ;

int main()
{
    cin >> n;
    occ[0]=1;
    for (int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        sum=(n+(sum+a)%n)%n;
        ans+=occ[sum];
        occ[sum]++;
    }

    cout << ans << endl;

    return 0;
}

/*
5
3 1 2 7 4
*/