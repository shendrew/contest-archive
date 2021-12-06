#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <string>
#include <string.h>
using namespace std;

#define f first
#define s second
int t;
string str;

int cost(int chr, int l, int r)
{
    int cnt=0;
    for (int i=l; i<=r; i++)
    {
        cnt+=(str[i]-'a'!=chr);
    }
    return cnt;
}

int solve(int chr, int l, int r)
{
    int m=(l+r)/2;
    if (l==r)
    {
        return 1-(str[m]-'a'==chr);
    }
    int a=solve(chr+1, l, m)+cost(chr, m+1, r);
    int b=solve(chr+1, m+1, r)+cost(chr, l, m);
    return min(a, b);
}

int main()
{
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n >> str;

        cout << solve(0, 0, n-1) << endl;
    }

    return 0;
}

/*
6
8
bbdcaaaa
8
asdfghjk
8
ceaaaabb
8
bbaaddcc
1
z
2
ac

1
8
aacdaeee
*/