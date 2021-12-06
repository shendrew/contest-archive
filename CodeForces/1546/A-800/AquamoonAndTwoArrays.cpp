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
using namespace std;

#define f first
#define s second
#define ll long long

int t;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        int sumA=0, sumB=0;
        for (int i=0; i<n; i++)
        {
            cin >> a[i];
            sumA+=a[i];
        }
        for (int i=0; i<n; i++)
        {
            cin >> b[i];
            sumB+=b[i];
        }
        if (sumA!=sumB)
        {
            cout << -1 << endl;
            continue;
        }

        bool loop=true;
        vector<pair<int, int>> ans;
        while (loop)
        {
            loop=false;
            for (int i=0; i<n; i++)
            {
                int j;
                if (a[i]>b[i])
                {
                    for (j=0; j<n; j++)
                    {
                        if (a[j]<b[j] && i!=j)
                        {
                            break;
                        }
                    }
                    a[i]--;
                    a[min(j,n-1)]++;
                    ans.push_back({i+1, min(j+1, n)});
                    loop=true;
                }
                else if (a[i]<b[i])
                {
                    for (j=0; j<n; j++)
                    {
                        if (a[j]>b[j] && i!=j)
                        {
                            break;
                        }
                    }
                    a[min(j,n-1)]--;
                    a[i]++;
                    ans.push_back({min(j+1, n), i+1});
                    loop=true;
                }
            }
        }

        cout << ans.size() << endl;
        for (auto &i: ans)
        {
            cout << i.f << " " << i.s << endl;
        }
    }

    return 0;
}

/*
4
4
1 2 3 4
3 1 2 4
2
1 3
2 1
1
0
0
5
4 3 2 1 0
0 1 2 3 4
*/