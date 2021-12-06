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

ifstream fin("stacking.in");
ofstream fout("stacking.out");

#define f first
#define s second
int n, k;
int prefix[1000002], arr[1000002];

int main()
{
    fin >> n >> k;
    for (int i=0; i<k; i++)
    {
        int a, b;
        fin >> a >> b;
        arr[a]++;
        arr[b+1]--;
    }
    vector<int> v;
    for (int i=1; i<=n; i++)
    {
        prefix[i]=prefix[i-1]+arr[i];
        v.push_back(prefix[i]);
    }
    sort(v.begin(), v.end());
    fout << v[n/2] << endl;


    return 0;
}