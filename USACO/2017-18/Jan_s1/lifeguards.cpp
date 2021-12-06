#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("lifeguards.in");
ofstream fout("lifeguards.out");

int n, total;
vector<pair<int,int>> guards;

int main()
{
    fin >> n;
    guards.resize(n);
    int i;
    for (i=0; i<n; i++)
    {
        fin >> guards[i].first >> guards[i].second;
    }
    sort(guards.begin(),guards.end());
    int startp=guards[0].first,endp=guards[0].second;
    bool inside=false;
    for (i=1; i<n; i++)
    {
        if (guards[i].second < endp)
        {
            inside=true;
        }
        if (i==n-1 && guards[i].first > endp)
        {
            total+=guards[i].second-guards[i].first+endp-startp;
        }
        else if (guards[i].first > endp)
        {
            total+=endp-startp;
            startp=guards[i].first;
        }
        else if (i==n-1)
        {
            total+=max(endp,guards[i].second)-startp;
        }
        endp=max(endp,guards[i].second);
    }

    if (inside)
    {
        fout << total << endl;
    }
    else
    {
        cout << total << endl;
        int small=guards[0].second-guards[0].first-max(guards[0].second-guards[1].first,0);
        cout << small << endl;
        for (i=1; i<n-1; i++)
        {
            small=min(small, max(0,guards[i].second-guards[i].first-max(guards[i-1].second-guards[i].first,0)-max(guards[i].second-guards[i+1].first,0)));
        }
        small=min(small, guards[n-1].second-guards[n-1].first-max(guards[n-2].second-guards[n-1].first,0));
        cout << small<< endl;
        fout << total-small << endl;
    }

    return 0;
}
