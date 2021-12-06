#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin ("snowboots.in");
ofstream fout ("snowboots.out");

int n,b;
vector<int> f;
vector<pair<int,int>> sd;
int path[250];

int main()
{
    int i,j;
    fin >> n >> b;
    f.resize(n);
    sd.resize(n);
    for (i=0; i<n; i++)
        fin >> f[i];
    for (i=0; i<b; i++)
        fin >> sd[i].first >> sd[i].second;
    
    vector<int> parent {0};
    for (i=0; i<b; i++)
    {
        int ind=0;
        while (parent.size() >= ind+1)
        {
            for (j=1; j<=sd[i].second; j++)
                if (f[parent[ind]] <= sd[i].first && f[parent[ind]+j] <= sd[i].first && not path[n-1])
                {
                    if (not count(parent.begin(), parent.end(), parent[ind]+j))
                    {
                        parent.push_back(parent[ind]+j);
                        path[parent[ind]+j]=i+1;
                    }
                }
            ind++;
        }
        if (path[n-1]) break;
    }
    //cout << path[n-1]-1 << endl;
    fout << path[n-1]-1 << endl;
    return 0;
}
