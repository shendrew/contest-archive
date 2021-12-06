#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define f first
#define s second
int n;
long long ans;
vector<pair<int,int>> vp;
vector<int> yValue;
int a[2501][2501];

int main()
{
    cin >> n;
    vp.resize(n);
    for (int i=0; i<n; i++)
    {
        cin >> vp[i].f >> vp[i].s;
        yValue.push_back(vp[i].s);
    }
    sort(vp.begin(), vp.end());
    sort(yValue.begin(), yValue.end());

    vector<pair<int,int>> xy;
    for (int i=0; i<n; i++)
    {
        int num;
        for (num=0; num<n; num++)
        {
            if (yValue[num]==vp[i].s)
            {
                break;
            }
        }
        a[i+1][num+1]=1;
        xy.push_back({i+1,num+1});
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }

    sort(xy.begin(), xy.end());
    int above, below;
    for (int i=0; i<n-1; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            int maxX=xy[j].f, minX=xy[i].f, maxY=max(xy[i].s,xy[j].s), minY=min(xy[i].s,xy[j].s);
            above=a[maxX][n]-a[maxX][maxY-1]-a[minX-1][n]+a[minX-1][maxY-1];
            below=a[maxX][minY]-a[minX-1][minY];
            ans+=above*below;
        }
    }
    cout << ans+n+1 << endl;

    return 0;
}

/*
4
0 2
1 0
2 3
3 5
*/
