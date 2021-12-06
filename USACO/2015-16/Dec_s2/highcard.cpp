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
using namespace std;

ifstream fin("highcard.in");
ofstream fout("highcard.out");

#define f first
#define s second
#define ll long long

int n, ans;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    fin >> n;
    vector<int> elsie(n), bessie;
    for (int i=0; i<n; i++)
    {
        fin >> elsie[i];
    }
    sort(elsie.begin(), elsie.end());
    int ind=0;
    for (int i=1; i<=2*n; i++)
    {
        if (ind>=n || elsie[ind]!=i)
        {
            bessie.push_back(i);
            continue;
        }
        ind++;
    }

    int l=0, r=0;
    for (; l<n; l++)
    {
        while (r<n-1 && bessie[r]<elsie[l])
        {
            r++;
        }
        if (r<n && bessie[r]>elsie[l])
        {
            ans++;
            r++;
        }
    }

    fout << ans << endl;

    return 0;
}