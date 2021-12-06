#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, p;
vector<int> v;
vector<vector<long>> hole;

int main()
{
    ifstream fin("wormsort.in");
    ofstream fout("wormsort.out");
    fin >> n >> m;
    for(int i=0; i<n; i++)
    {
        fin >> p;
        if(p-1!=i) v.push_back(p);
    }

    if(v.size()==0)
    {
        cout << -1 << endl;
        fout << -1 << endl;
    }
    else
    {
        for(int i=0; i<m; i++)
        {
            int a, b , c;
            fin >> a >> b >> c;
            hole.push_back({c, a, b});
        }
        sort(hole.begin(),hole.end());
        for (int i=0; i<m; i++)
        {
            cout << hole[i][2] << endl;
        }
    }
    return 0;
}
