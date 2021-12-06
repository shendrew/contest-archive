#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("reststops.in");
ofstream fout("reststops.out");

int l, n, f, b;
vector<pair<long long,long long>> rests;

int main()
{
    fin >> l >> n >> f >> b;
    rests.resize(n+1);
    int i;
    for (i=0; i<n; i++)
    {
        fin >> rests[i].second >> rests[i].first;
    }
    sort(rests.begin(),rests.end());
    reverse(rests.begin(), rests.end());
    long long time=(f-b)*(rests[0].second), pre=rests[0].second;
    long long tasty=rests[0].first*time;
    // prioritize the tastiest stops, eat until fj catches up, go to the next stop that is after the current one.
    for (i=1; i<n; i++)
    {
        if (rests[i].second>pre)
        {
            time=(f-b)*(rests[i].second-pre);
            tasty+=rests[i].first*time;
            pre=rests[i].second;
        }
    }
    fout << tasty;
    return 0;
}
