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
int a[200001];
string str;
int prefix[200001];

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    cin >> str;

    for (int i=1; i<n; i++)
    {
        prefix[i]=prefix[i-1]+str[i-1]-'0';
    }
    prefix[n]=prefix[n-1];

    bool possible=true;
    for (int i=1; i<=n; i++)
    {
        if (max(prefix[a[i]-1], prefix[i-1])-min(prefix[a[i]-1], prefix[i-1])<abs(a[i]-i))
        {
            possible=false;
        }
    }

    if (possible)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}

/*
6
1 2 5 3 4 6
01010
*/