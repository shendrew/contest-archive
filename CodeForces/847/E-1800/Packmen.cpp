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
#include <iomanip>
using namespace std;

#define f first
#define s second
#define ll long long

int n;
string str;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> str;
    vector<int> v(n+1);
    for (int i=0; i<n; i++)
    {
        if (str[i]=='*')
        {
            v[i]=1;
        }
        else if (str[i]=='P')
        {
            v[i]=2;
        }
    }

    vector<int> food, pac;
    for (int i=0; i<n; i++)
    {
        if (v[i]==1)
        {
            food.push_back(i);
        }
        if (v[i]==2)
        {
            pac.push_back(i);
        }
    }

    int low=1, high=2*n, mid;
    while (low<high)
    {
        mid=low+(high-low)/2;
        int j=0;
        for (int i=0; i<pac.size(); i++)
        {
            int l=pac[i], r=pac[i];
            while (j<food.size())
            {
                if (food[j]<l && food[j]<pac[i])
                {
                    l=food[j];
                }
                else if (food[j]>r && food[j]>pac[i])
                {
                    r=food[j];
                }
                if (min((r-pac[i])*2+pac[i]-l, (pac[i]-l)*2+r-pac[i])>mid)
                {
                    break;
                }
                j++;
            }
        }
        if (j==food.size())
        {
            high=mid;
        }
        else
        {
            low=++mid;
        }
    }

    cout << mid << endl;

    return 0;
}

/*
10
.**PP.*P.*
*/