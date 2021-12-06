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
#include <functional>
using namespace std;

#define f first
#define s second
#define ll long long

int t;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        int n;
        string str1, str2;
        cin >> n >> str1 >> str2;
        vector<int> a(n), b(n);
        for (int i=0; i<n; i++)
        {
            a[i]=str1[i]-'0';
            b[i]=str2[i]-'0';
        }
        
        vector<int> v;
        for (int i=0; i<n; i++)
        {
            set<int> uni={0, 1, 2};
            uni.erase(a[i]);
            uni.erase(b[i]);
            v.push_back(*uni.begin());
        }
        v.push_back(2);

        int ind=0, ans=0;
        while (ind<n)
        {
            if (v[ind]==2)
            {
                ans+=2;
            }
            else if (v[ind]==1)
            {
                ans+=1;
                if (v[ind+1]==0)
                {
                    ans+=1;
                    ind++;
                }
            }
            else if (v[ind]==0 && v[ind+1]==1)
            {
                ans+=2;
                ind++;
            }
            ind++;
        }

        cout << ans << endl;
    }

    return 0;
}

/*
4
7
0101000
1101100
5
01100
10101
2
01
01
6
000000
111111
*/