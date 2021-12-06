#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <set>
using namespace std;

#define f first
#define s second
int n;
vector<pair<int,int>> v;

int main() {
    ifstream fin("teleport.in");
    ofstream fout("teleport.out");
    fin >> n;
    v.resize(n);
    int i, j, x, y, sml=100000000, big=-100000000;
    for (i=0; i<n; i++)
    {
        fin >> x >> y;
        sml=min(sml, min(x,y)), big=max(big, max(x,y));
        v[i].f=min(x,y), v[i].s=max(x,y);
    }
    long long ans=numeric_limits<long long>::max();
    for (i=sml; i<=big; i++)
    {
        long long current=0;
        for (j=0; j<n; j++)
        {
            current+=min(min(abs(0-v[j].f)+abs(i-v[j].s), abs(0-v[j].s)+abs(i-v[j].f)), abs(v[j].s-v[j].f));
        }
        ans=min(ans, current);
    }
    fout << ans;
    return 0;
}
