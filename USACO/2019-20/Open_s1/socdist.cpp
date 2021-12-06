#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream fin("socdist.in");
ofstream fout("socdist.out");

int n,m;
long long mind=1,maxd,mid,ans;
vector<pair<long long,long long>> vp;

bool fits(long long d)
{
    long long pre=vp[0].first;
    int cows=1;
    for (int i=0; i<vp.size(); i++)
    {
        while (max(pre + d, vp[i].first) <= vp[i].second && cows<n)
        {
            pre=max(pre + d, vp[i].first);
            cows++;
        }
        if (cows>=n)
            break;
    }
    return cows>=n;
}

int main()
{
    fin >> n >> m;
    vp.resize(m);
    for(int i=0; i<m; i++)
    {
        fin >> vp[i].first >> vp[i].second;
    }
    sort(vp.begin(), vp.end());
    
    maxd=vp[m-1].second;
    while(mind <= maxd)
    {
        mid=(mind+maxd)/2;
        
        if (fits(mid))
        {
            ans=mid;
            mind=mid+1;
        }
        else
            maxd=mid-1;
    }
    fout << ans << endl;
    cout << ans << endl;
    return 0;
}
