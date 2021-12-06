#include <iostream>
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
string str;
int nb, ns, nc, pb, ps, pc, cb, cs, cc;
long long r;

int main()
{
    cin >> str >> nb >> ns >> nc >> pb >> ps >> pc >> r;
    int n=str.size();
    for (int i=0; i<n; i++)
    {
        if (str[i]=='B')
        {
            cb++;
        }
        else if (str[i]=='S')
        {
            cs++;
        }
        else
        {
            cc++;
        }
    }

    long long low=0, high=2000000000000, mid;
    while (low!=high)
    {
        mid=(low+high+1)/2;
        if (pb*max((ll)0, mid*cb-nb)+ps*max((ll)0, mid*cs-ns)+pc*max((ll)0, mid*cc-nc)<=r)
        {
            low=mid;
        }
        else
        {
            high=--mid;
        }
    }

    cout << mid << endl;

    return 0;
}

/*
BBBSSC
6 4 1
1 2 3
4
*/