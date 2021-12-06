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
using namespace std;

ifstream fin("sabotage.in");
ofstream fout("sabotage.out");

#define f first
#define s second
#define ll long long

int n;

int main()
{
    fin.tie(NULL);
    ios_base::sync_with_stdio(false);
    fin >> n;
    vector<int> v(n);
    long long total=0;
    for (int i=0; i<n; i++)
    {
        fin >> v[i];
        v[i]*=100000;
        total+=v[i];
    }

    long long low=1, high=1e9, mid;
    while (low<high)
    {
        mid=(low+high)/2;
        long long mx=v[1]-mid, cur=max((ll)0, v[1]-mid);
        for (int i=2; i<n-1; i++)
        {
            cur=max((ll) 0, cur+v[i]-mid);
            mx=max(mx, cur);
        }
        if (mx>=total-n*mid)
        {
            high=mid;
        }
        else
        {
            low=++mid;
        }
    }

    double ans=mid;
    fout << fixed << setprecision(3) << ans/100000 << endl;

    return 0;
}

/*
5
5
1
7
8
2
*/