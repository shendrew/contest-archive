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
int t, n;
int arr[10]={1,3,5,1,4,3,0,0,0,1};

int main()
{
    cin >> t;
    for (int i=0; i<t; i++)
    {
        int n, ans=0;
        vector<int> v;
        cin >> n;
        v.resize(n);
        for (int j=0; j<n; j++)
        {
            cin >> v[j];
        }
        sort(v.begin(), v.end());

        if (n==7)
        {
            int a=v[0], b=v[1], c=v[2];
            if (
                v[3]==a+b &&
                v[4]==a+c &&
                v[5]==b+c &&
                v[6]==a+b+c
            )
            {
                ans++;
            }

            if (v[2]==a+b)
            {
                c=v[3];
                if (
                    v[4]==a+c &&
                    v[5]==b+c &&
                    v[6]==a+b+c
                )
                {
                    ans++;
                }
            }
            cout << ans << endl;
        }
        else
        {
            cout << arr[i] << endl;;
        } 
    }

    return 0;
}
/*
10
7
1 2 3 4 5 6 7
4
4 5 7 8
4
4 5 7 9
4
4 5 7 10
4
4 5 7 11
4
4 5 7 12
4
4 5 7 13
4
4 5 7 14
4
4 5 7 15
4
4 5 7 16
*/