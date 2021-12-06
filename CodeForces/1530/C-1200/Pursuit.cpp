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
        vector<int> a(n), b(n), prefix(n);
        for (int i=0; i<n; i++)
        {
            cin >> a[i];
        }
        for (int i=0; i<n; i++)
        {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());
        prefix[0]=b[0];
        for (int i=1; i<n; i++)
        {
            prefix[i]=prefix[i-1]+b[i];
        }

        int len=n, sumA=0, left=len/4, sumB=prefix[min(n, len-(len/4))-1];
        for (int i=len/4; i<n; i++)
        {
            sumA+=a[i];
        }
        while (sumA<sumB)
        {
            a.push_back(100);
            sumA+=100;
            len++;
            if (len%4==0)
            {
                sumA-=a[left];
                left++;
            }
            sumB=prefix[min(n, len-(len/4))-1];
        }
        cout << len-n << endl;
    }

    return 0;
}

/*
5
1
100
0
1
0
100
4
20 30 40 50
100 100 100 100
4
10 20 30 40
100 100 100 100
7
7 59 62 52 27 31 55
33 35 50 98 83 80 64
*/