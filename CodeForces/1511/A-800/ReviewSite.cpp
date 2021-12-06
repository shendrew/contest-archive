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
        int n, ans=0;
        cin >> n;
        for (int i=0; i<n; i++)
        {
            int p;
            cin >> p;
            if (p==1 || p==3)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}

/*
4
1
2
3
1 2 3
5
1 1 1 1 1
3
3 3 2
*/