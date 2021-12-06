#include <iostream>
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
int n, q, c;
int prefix[11][101][101];

int main()
{
    scanf("%d%d%d", &n, &q, &c);
    for (int i=0; i<n; i++)
    {
        int xi, yi, si;
        scanf("%d%d%d", &xi, &yi, &si);
        for (int j=0; j<=c; j++)
        {
            prefix[j][xi][yi]+=(j+si)%(c+1);
        }
    }

    for (int i=0; i<=10; i++)
    {
        for (int j=1; j<=100; j++)
        {
            for (int k=1; k<=100; k++)
            {
                prefix[i][j][k]+=prefix[i][j-1][k]+prefix[i][j][k-1]-prefix[i][j-1][k-1];
            }
        }
    }

    for (int i=0; i<q; i++)
    {
        int t, x1, y1, x2, y2;
        scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
        printf("%d\n", prefix[t%(c+1)][x2][y2]-prefix[t%(c+1)][x1-1][y2]-prefix[t%(c+1)][x2][y1-1]+prefix[t%(c+1)][x1-1][y1-1]);
    }

    return 0;
}

/*
2 3 3
1 1 1
3 2 0
2 1 1 2 2
0 2 1 4 5
5 1 1 5 5
*/