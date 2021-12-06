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
#include <iomanip>
#include <functional>
using namespace std;

#define f first
#define s second
#define ll long long

int t, n, ans;
int score[5];
set<pair<int, int>> games;

void dfs(set<pair<int, int>>::iterator it)
{
    if (it==games.end())
    {
        bool possible=true;
        for (int i=1; i<=4; i++)
        {
            if (i!=t && score[t]<=score[i])
            {
                possible=false;
            }
        }
        if (possible)
        {
            ans++;
        }
        return;
    }
    
    score[(*it).f]+=3;
    dfs(next(it));
    score[(*it).f]-=3;

    score[(*it).s]+=3;
    dfs(next(it));
    score[(*it).s]-=3;

    score[(*it).f]+=1, score[(*it).s]+=1;
    dfs(next(it));
    score[(*it).f]-=1, score[(*it).s]-=1;
}

int main()
{
    cin >> t >> n;

    for (int i=1; i<=3; i++)
        for (int j=i+1; j<=4; j++)
            games.insert({i, j});

    for (int i=0; i<n; i++)
    {
        int a, b, sa, sb;
        cin >> a >> b >> sa >> sb;
        if (sa>sb)
        {
            score[a]+=3;
        }
        else if (sa<sb)
        {
            score[b]+=3;
        }
        else
        {
            score[a]++;
            score[b]++;
        }
        games.erase({a, b});
    }

    dfs(games.begin());

    cout << ans << endl;

    return 0;
}

/*
3
3
1 3 7 5
3 4 0 8
2 4 2 2
*/