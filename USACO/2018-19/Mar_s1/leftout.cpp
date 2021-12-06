#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("leftout.in");
ofstream fout("leftout.out");

int n, total;
vector<vector<int>> v;

int main()
{
    fin >> n;
    v.resize(n);
    int i, j;
    string x;
    for (i=0; i<n; i++)
    {
        v.push_back({});
        fin >> x;
        for (j=0; j<n; j++)
        {
            if (x[j]=='R')
            {
                v[i].push_back(1);
            }
            else
            {
                v[i].push_back(0);
            }
        }
    }
    for (i=0; i<n; i++)
    {
        if (v[0][i])
        {
            for (j=0; j<n; j++)
            {
                v[j][i]=(v[j][i]+1)%2;
            }
        }
        if (v[i][0])
        {
            for (j=0; j<n; j++)
            {
                v[i][j]=(v[i][j]+1)%2;
            }
        }
    }

    int ri=0, ci=0;
    pair<int,int> f(0,0);
    for (i=1; i<n; i++)
    {
        int row=0, col=0;
        for (j=1; j<n; j++)
        {
            if (v[i][j] && !f.first && !f.second)
            {
                f.first=i+1, f.second=j+1;
            }
            if (v[i][j])
            {
                total++, row++;
            }
            if (v[j][i])
            {
                col++;
            }
        }
        if (!ri && row==n-1)
        {
            ri=i+1;
        }
        if (!ci && col==n-1)
        {
            ci=i+1;
        }
    }
    bool possible=true;
    if (total==(n-1)*(n-1))
        f.first=1, f.second=1;
    else if (ci)
        f.first=1, f.second=ci;
    else if (ri)
        f.first=ri, f.second=1;
    else if (!total || total>1)
        possible=false;
    if (possible)
        fout << f.first << " " << f.second;
    else
        fout << -1;

    return 0;
}
