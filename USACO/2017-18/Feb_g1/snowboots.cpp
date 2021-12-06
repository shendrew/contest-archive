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

ifstream fin("snowboots.in");
ofstream fout("snowboots.out");

#define f first
#define s second
#define ll long long

int n, b, mx;

int main()
{
    fin >> n >> b;
    set<pair<int, int>> boots;
    for (int i=0; i<n; i++)
    {
        int fi;
        fin >> fi;
        mx=max(mx, fi);
        boots.insert({fi, i});
    }

    vector<int> v;
    for (auto &i: boots)
    {
        v.push_back(i.s);
    }
    vector<int> prefix(n);
    set<int> taken={v[0]};
    multiset<int, greater<int>> segments;
    for (int i=1; i<n; i++)
    {
        taken.insert(v[i]);
        auto ind=taken.lower_bound(v[i]), last=taken.end(), sec=taken.begin();
        sec++, last--;
        auto secLast=last;
        secLast--;
        if (ind==taken.begin())
        {
            segments.insert(*sec-*taken.begin());
        }
        else if (ind==last)
        {
            segments.insert(*last-*secLast);
        }
        else
        {
            auto right=taken.upper_bound(v[i]), left=taken.lower_bound(v[i]);
            left--;
            segments.erase(segments.find(*right-*left));
            segments.insert(v[i]-*left);
            segments.insert(*right-v[i]);
        }
        prefix[v[i]]=*segments.begin();
    }
    
    for (int i=0; i<b; i++)
    {
        int si, di;
        fin >> si >> di;
        auto ind=boots.upper_bound({si, n});
        if (ind==boots.begin())
        {
            fout << 0 << endl;
            continue;
        }
        if (si>=mx)
        {
            fout << 1 << endl;
            continue;
        }
        ind--;
        if (prefix[(*ind).s]<=di)
        {
            fout << 1 << endl;
        }
        else
        {
            fout << 0 << endl;
        }
    }


    return 0;
}