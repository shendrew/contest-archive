#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("maxcross.in");
ofstream fout("maxcross.out");

int n, k, b, mx;

int main()
{
    fin >> n >> k >> b;
    vector<int> v(n+1,1);
    v[0]=0;
    int i, bi;
    for (i=0; i<k; i++)
    {
        fin >> bi;
        v[bi]=0;
    }

    vector<int> prefix={0};
    for (i=1; i<=n; i++)
    {
        prefix.push_back(prefix[i-1]+v[i]);
    }

    for (i=k; i<=n; i++)
    {
        mx=max(mx, prefix[i]-prefix[i-k]);
        cout << prefix[i]-prefix[i-k];
    }
    fout << k-mx;
    return 0;
}
