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
#define n 5000
char str[5001];
int q;
int pal[5001][5001], pre[5001][5001];

int main()
{
    scanf("%5000s%d", str, &q);
    for (int i=1; i<=n; i++)
    {
        pal[i][i]=1;
    }
    for (int i=1; i<n; i++)
    {
        if (str[i-1]==str[i])
        {
            pal[i][i+1]=1;
        }
    }
    for (int i=3; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (j+i-1>n)
            {
                break;
            }
            pal[j][j+i-1]=(pal[j+1][j+i-2] && str[j-1]==str[j+i-2]);
        }
    }

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            pre[i][j]=pal[i][j]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
        }
    }
    
    for (int i=0; i<q; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", pre[r][r]-pre[r][l-1]-pre[l-1][r]+pre[l-1][l-1]);
    }
    
    return 0;
}

/*
caaaba
5
1 1
1 4
2 3
4 6
4 5
*/