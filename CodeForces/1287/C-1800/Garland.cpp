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
double n;
int ans;

int main()
{
    cin >> n;
    vector<int> v(n+2);
    int nOdd=ceil(n/2), nEven=n/2;
    for (int i=1; i<=n; i++)
    {
        int a;
        cin >> a;
        if (!a)
        {
            v[i]=0;
        }
        else if (a%2)
        {
            v[i]=1;
            nOdd--;
        }
        else
        {
            v[i]=2;
            nEven--;
        }
    }
    if (nOdd+nEven==n)
    {
        if (n==1)
            cout << 0 << endl;
        else
            cout << 1 << endl;
        return 0;
    }

    v[0]=-1, v[n+1]=-1;
    
    int start, finish, sParity, fParity, l=0;
    vector<int> odd, even;
    while (l<=n)
    {
        int r=l+1;
        while (!v[r])
        {
            r++;
        }

        if (v[l]==-1)
        {
            start=r-l-1;
            sParity=v[r];
        }
        else if (v[r]==-1)
        {
            finish=r-l-1;
            fParity=v[l];
        }
        else if (v[l]!=v[r])
        {
            ans++;
        }
        else if (r-l-1>0)
        {
            if (v[l]==1)
            {
                odd.push_back(r-l-1);
            }
            else
            {
                even.push_back(r-l-1);
            }
        }
        l=r;
    }
    sort(odd.begin(), odd.end()), sort(even.begin(), even.end());
    int doneOdd=0, doneEven=0;
    for (int i=0; i<odd.size(); i++)
    {
        if (nOdd<odd[i])
        {
            break;
        }
        nOdd-=odd[i];
        doneOdd++;
    }
    for (int i=0; i<even.size(); i++)
    {
        if (nEven<even[i])
        {
            break;
        }
        nEven-=even[i];
        doneEven++;
    }

    ans+=(odd.size()-doneOdd)*2+(even.size()-doneEven)*2;

    if (sParity==1)
    {
        if (nOdd<start)
            ans++;
        else
            nOdd-=start;
    }
    else
    {
        if (nEven<start)
            ans++;
        else
            nEven-=start;
    }
    if (fParity==1)
    {
        if (nOdd<finish)
            ans++;
    }
    else
    {
        if (nEven<finish)
            ans++;
    }

    cout << ans << endl;
    return 0;
}

/*
5
0 5 0 2 3
*/