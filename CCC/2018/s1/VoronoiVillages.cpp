#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int n;
vector<double> v;

int main()
{
    cin >> n;
    v.resize(n);
    int i;
    for (i=0; i<n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    double ans=2000000001;
    for (i=1; i<n-1; i++)
    {
        ans=min(ans, (v[i]-v[i-1])/2+(v[i+1]-v[i])/2);
    }
    cout << setprecision(1) << fixed << ans;
    return 0;
}

/*
 5
 16
 0
 10
 4
 15
 */
