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

ifstream fin("where.in");
ofstream fout("where.out");

#define f first
#define s second
#define ll long long

int n;
int arr[25][25], vis[25][25];

int main()
{
    fin >> n;
    for (int i=1; i<=n; i++)
    {
        string str;
        fin >> str;
        for (int j=1; j<=n; j++)
        {
            arr[i][j]=int(str[j-1])-64;
        }
    }

    vector<vector<int>> pcl;
    for (int r1=1; r1<=n; r1++)
    {
        for (int c1=1; c1<=n; c1++)
        {
            for (int r2=n; r2>=r1; r2--)
            {
                for (int c2=n; c2>=c1; c2--)
                {
                    bool contained=false;
                    for (auto &i: pcl)
                    {
                        if (r1>=i[0] && c1>=i[1] && r2<=i[2] && c2<=i[3])
                        {
                            contained=true;
                            break;
                        }
                    }

                    if (contained)
                    {
                        continue;
                    }

                    int color;

                    function<void (int, int)> flood;
                    flood = [&](int r, int c)
                    {
                        if (vis[r][c] || color!=arr[r][c] || r<r1 || c<c1 || r>r2 || c>c2)
                        {
                            return;
                        }
                        vis[r][c]=1;
                        flood(r+1, c);
                        flood(r-1, c);
                        flood(r, c+1);
                        flood(r, c-1);
                    };
                    
                    memset(vis, 0, sizeof(vis));
                    map<int, int> colors;
                    for (int i=r1; i<=r2; i++)
                    {
                        for (int j=c1; j<=c2; j++)
                        {
                            if (!vis[i][j])
                            {
                                colors[arr[i][j]]++;
                                color=arr[i][j];
                                flood(i, j);
                            }
                        }
                    }

                    bool single=false, multi=false;
                    if (colors.size()==2)
                    {
                        for (auto &i: colors)
                        {
                            if (i.s==1)
                            {
                                single=true;
                            }
                            else if (i.s>1)
                            {
                                multi=true;
                            }
                        }
                    }

                    if (single && multi)
                    {
                        pcl.push_back({r1, c1, r2, c2});
                    }
                }
            }
        }
    }

    fout << pcl.size() << endl;

    return 0;
}