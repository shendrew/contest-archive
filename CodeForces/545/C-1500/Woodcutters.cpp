#include <iostream>
#include <vector>
using namespace std;

#define f first
#define s second

int n;
vector<pair<long long,int>> v, occ;

int main()
{
    cin >> n;
    v.resize(n);
    int i;
    for (i=0; i<n; i++)
    {
        cin >> v[i].f >> v[i].s;
    }
    v.push_back(make_pair(3000000000,0));
    int ans=1;
    occ.push_back(make_pair(v[0].f-v[0].s, v[0].f));
    for (i=1; i<n; i++)
    {
        if (v[i].f-v[i].s>occ[occ.size()-1].s)
        {
            occ.push_back(make_pair(v[i].f-v[i].s, v[i].f));
            ans++;
        }
        else if (v[i].f+v[i].s<v[i+1].f)
        {
            occ.push_back(make_pair(v[i].f, v[i].f+v[i].s));
            ans++;
        }
        else
        {
            occ.push_back(make_pair(v[i].f,v[i].f));
        }
    }
    cout << ans;
    return 0;
}
