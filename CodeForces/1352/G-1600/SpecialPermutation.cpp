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
int t, n;
int visit[1001];

bool test(int num)
{
    if (!visit[num] && num<=n && num>0)
    {
        visit[num]=1;
        return true;
    }
    return false;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n<=3)
        {
            cout << -1 << endl;
            continue;
        }
        vector<int> ans;
        set<int> uni;

        for (int i=1; i<=n; i++)
        {
            memset(visit, 0, sizeof(visit));
            visit[i]=1;
            ans={i};
            uni={i};
            int cur=i;
            while (ans.size()<n)
            {
                for (int j=2; j<=4; j++)
                {
                    if (test(cur+j))
                    {
                        cur+=j;
                        break;
                    }
                    if (test(cur-j))
                    {
                        cur-=j;
                        break;
                    }
                }
                visit[cur]=true;
                ans.push_back(cur);
                uni.insert(cur);
            }
            if (uni.size()==n)
            {
                break;
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
6
10
2
4
6
7
13
*/