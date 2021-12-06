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

ifstream fin("pails.in");
ofstream fout("pails.out");

int x, y, k, m, ans=300;
int vis[102][102][102];

void solve(int b1, int b2, int move)
{
    if (vis[b1][b2][move] || move>k) 
    {
        return;
    }
    ans=min(ans, abs(m-(b1+b2)));
    vis[b1][b2][move]=1;
    solve(x, b2, move+1); // fill
    solve(b1, y, move+1);

    solve(0, b2, move+1); // empty
    solve(b1, 0, move+1);

    solve(b1-min(b1, y-b2), b2+min(b1, y-b2), move+1); // a -> b
    solve(b1+min(b2, x-b1), b2-min(b2, x-b1), move+1);
}

int main()
{
    fin >> x >> y >> k >> m;

    solve(0, 0, 0);

    fout << ans << endl;

    return 0;
}