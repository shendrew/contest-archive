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

int t;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n), sv(n);
        for (int i=0; i<n; i++)
        {
            cin >> v[i];
            sv[i]=v[i];
        }
        sort(sv.begin(), sv.end());

        map<int, int> odd, odd_sort, even, even_sort;
        for (int i=0; i<n; i++)
        {
            if (i%2)
            {
                odd[v[i]]++;
                odd_sort[sv[i]]++;
            }
            else
            {
                even[v[i]]++;
                even_sort[sv[i]]++;
            }
        }
        
        bool possible=true;
        for (auto &i: v)
        {
            if (odd[i]!=odd_sort[i] || even[i]!=even_sort[i])
            {
                possible=false;
                break;
            }
        }
        if (possible)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}

/*
3
4
4 3 2 5
4
3 3 2 2
5
1 2 3 5 4
*/