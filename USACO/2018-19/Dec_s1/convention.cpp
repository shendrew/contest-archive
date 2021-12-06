#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("convention.in");
ofstream fout("convention.out");

int n, m, c, t;
vector<int> v;

int main()
{
    fin >> n >> m >> c;
    v.resize(n);
    for (int i=0; i<n; i++)
        fin >> v[i];
    sort(v.begin(),v.end());
    
    int mi=0, mx=v[n-1];
    while (mi!=mx)
    {
        int mid=(mi+mx)/2, first=v[0], bus=1, cows=1, i=1;
        while (i<n)
        {
            if (cows<c && v[i]-first<=mid)
            {
                cows++;
            }
            else if (cows==c || v[i]-first>mid)
            {
                bus++;
                cows=1;
                first=v[i];
            }
            i++;
        }
        if (bus>m)
            mi=mid+1;
        else
            mx=mid;
    }
    
    fout << mi << endl;
    return 0;
}
