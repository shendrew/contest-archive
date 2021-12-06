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
int n, q;
int a[300000], t[300000];
int color[51];

int main()
{
    cin >> n >> q;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
        if (!color[a[i]])
        {
            color[a[i]]=i+1;
        }
    }
    for (int i=0; i<q; i++)
    {
        cin >> t[i];
        cout << color[t[i]] << " ";
        for (int j=1; j<=50; j++)
        {
            if (color[j] && color[j]<color[t[i]])
            {
                color[j]++;
            }
        }
        color[t[i]]=1;
    }

    return 0;
}

/*
7 5
2 1 1 4 3 3 1
3 2 1 1 4
*/