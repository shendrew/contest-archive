#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
using namespace std;

#define f first
#define s second
int t;

int main()
{
    cin >> t;
    for (int i=0; i<t; i++)
    {
        int n;
        cin >> n;
        int a[100]={0};
        for (int j=0; j<n; j++)
        {
            cin >> a[j];
        }
        sort(a, a+n);
        int weak=a[0], ans=n;

        for (int j=0; j<n; j++)
        {
            if (a[j]==weak)
            {
                ans--;
            }
            else
            {
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

/*
3
3
3 2 2
2
5 5
4
1 3 3 7
*/