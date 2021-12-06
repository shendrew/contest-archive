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
        int n, k;
        cin >> n >> k;

        vector<int> v1, v2;
        for (int i=1; i<=n; i++)
        {
            v1.push_back(i);
            v2.push_back(n-i+1);
        }

        if (k>(n-1)/2)
        {
            cout << -1 << endl;
            continue;
        }

        int peak=0, sInd=0, lInd=0;
        bool prePeak=true;
        vector<int> ans;
        for (int i=1; i<=n; i++)
        {
            if (peak==k)
            {
                ans.push_back(v2[lInd]);
                lInd++;
            }
            else if (!prePeak && peak<k)
            {
                ans.push_back(v2[lInd]);
                prePeak=true;
                peak++;
                lInd++;
            }
            else
            {
                ans.push_back(v1[sInd]);
                prePeak=false;
                sInd++;
            }
        }
        for (auto &i: ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
5
1 0
5 2
6 6
2 1
6 1
*/