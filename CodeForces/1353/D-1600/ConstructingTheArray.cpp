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

struct compare
{
    bool operator()(pair<int, int> const& p1, pair<int, int> const& p2)
    {
        if (p1.s-p1.f == p2.s-p2.f)
        {
            return p1.f > p2.f;
        }
        else
        {
            return p1.s-p1.f < p2.s-p2.f;
        }
    }
};

int main()
{
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans[200000];
        memset(ans, 0, sizeof(ans));
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> que;
        que.push({0, n-1});
        int ind=1;
        while (que.size())
        {
            pair<int, int> cur=que.top();
            que.pop();
            if (!ans[(cur.f+cur.s)/2])
            {
                ans[(cur.f+cur.s)/2]=ind;
                ind++;
            }

            if (cur.f!=cur.s)
            {
                que.push({cur.f, max((cur.f+cur.s)/2-1, cur.f)});
                que.push({(cur.f+cur.s)/2+1, cur.s});
            }
        }

        for (int i=0; i<n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
6
1
2
3
4
5
6
*/