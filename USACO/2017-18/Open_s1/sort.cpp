#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("sort.in");
ofstream fout("sort.out");

int n, mx;
vector<pair<int,int>> a;

int main()
{
    fin >> n;
    a.resize(n);
    int i;
    for (i=0; i<n; i++)
    {
        fin >> a[i].first;
        a[i].second=i+1;
    }
    sort(a.begin(), a.end());

    for (i=0; i<n; i++)
    {
        mx=max(mx, a[i].second-i);
    }
    fout << mx;
    return 0;
}
