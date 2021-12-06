#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
ifstream fin("cownomics.in");
ofstream fout("cownomics.out");

int n, m, ans;
int a[64];
vector<string> v;
vector<vector<int>> spot, plain;

int main()
{
    fin >> n >> m;
    v.resize(n*2), spot.resize(n), plain.resize(n);
    int i, j, e, k;
    for (i=0; i<n*2; i++)
    {
        fin >> v[i];
    }
    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            if (v[i][j]=='A')
                spot[i].push_back(0);
            else if (v[i][j]=='C')
                spot[i].push_back(1);
            else if (v[i][j]=='G')
                spot[i].push_back(2);
            else if (v[i][j]=='T')
                spot[i].push_back(3);
            if (v[n+i][j]=='A')
                plain[i].push_back(0);
            else if (v[n+i][j]=='C')
                plain[i].push_back(1);
            else if (v[n+i][j]=='G')
                plain[i].push_back(2);
            else if (v[n+i][j]=='T')
                plain[i].push_back(3);
        }
    }
    
    for (i=0; i<m-2; i++)
    {
        for (j=i+1; j<m-1; j++)
        {
            for (e=j+1; e<m; e++)
            {
                bool special=true;
                for (k=0; k<n; k++)
                {
                    a[16*spot[k][i]+4*spot[k][j]+spot[k][e]]=1;
                }
                for (k=0; k<n; k++) {
                    if (a[16*plain[k][i]+4*plain[k][j]+plain[k][e]])
                        special=false;
                }
                for (k=0; k<n; k++)
                {
                    a[16*spot[k][i]+4*spot[k][j]+spot[k][e]]=0;
                }
                if (special)
                    ans++;
            }
        }
    }
    
    //cout << ans << endl;
    fout << ans;
    return 0;
}
