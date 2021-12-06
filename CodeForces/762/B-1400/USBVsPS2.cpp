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

#define f first
#define s second
#define ll long long

int a, b, c, n, ans;
long long cost;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> c >> n;
    vector<int> usb, ps2;
    for (int i=0; i<n; i++)
    {
        int val;
        string type;
        cin >> val >> type;
        if (type=="USB")
        {
            usb.push_back(val);
        }
        else
        {
            ps2.push_back(val);
        }
    }
    sort(usb.begin(), usb.end());
    sort(ps2.begin(), ps2.end());
    
    int indu, indp;
    for (indu=0; indu<a && indu<usb.size(); indu++)
    {
        cost+=usb[indu];
        ans++;
    }
    for (indp=0; indp<b && indp<ps2.size(); indp++)
    {
        cost+=ps2[indp];
        ans++;
    }

    vector<int> combine;
    for (int i=indu; i<usb.size(); i++)
    {
        combine.push_back(usb[i]);
    }
    for (int i=indp; i<ps2.size(); i++)
    {
        combine.push_back(ps2[i]);
    }
    sort(combine.begin(), combine.end());
    
    for (int i=0; i<c && i<combine.size(); i++)
    {
        cost+=combine[i];
        ans++;
    }
    
    cout << ans << " " << cost << endl;

    return 0;
}

/*
2 1 1
4
5 USB
6 PS/2
3 PS/2
7 PS/2
*/