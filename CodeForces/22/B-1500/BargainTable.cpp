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
int n, m, ans;
int a[25][25];

int main()
{
    cin >> n >> m;

    for (int i=0; i<n; i++)
    {
        string str;
        cin >> str;
        for (int j=0; j<m; j++)
        {
            a[i][j]=str[j]-'0';
        }
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            int row=i, col=m-1;
            while (row<n && !a[row][j])
            {
                int ind=j;
                while (ind+1<m && !a[row][ind+1])
                {
                    ind++;
                }
                col=min(col, ind);
                ans=max(ans, (row-i+1)*2+(col-j+1)*2);
                row++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}

/*
5 4
1100
0000
0000
0000
0000
*/