#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("berries.in");
ofstream fout("berries.out");

int n, k, m, total;
vector<int> b;

int main()
{
    fin >> n >> k;
    b.resize(n);
    int i,j;
    for (i=0; i<n; i++)
    {
        fin >> b[i];
        m=max(m,b[i]);
    }
    for (i=1; i<=m; i++)
    {
        int groups=0;
        vector<int> remain;
        for (j=0; j<n; j++)
        {
            groups+=b[j]/i;
            remain.push_back(b[j]%i);
        }
        if (groups<k/2)
        {
            break;
        }
        if (groups>=k)
        {
            total=max(total,i*(k/2));
            continue;
        }
        int t=i*(groups-k/2);
        sort(remain.begin(),remain.end());
        reverse(remain.begin(),remain.end());
        for (j=0; j<remain.size() && j+groups<k; j++)
        {
            t+=remain[j]%i;
        }
        total=max(total,t);
    }
    fout << total << endl;
    return 0;
}
