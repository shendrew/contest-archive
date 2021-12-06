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

int q;

long long calc(long long n, long long m)
{
    return min((m-1)*m/2, n-m)+n-m;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> q;
    while (q--)
    {
        long long n;
        cin >> n;
        long long low=1, high=n, p1, p2;
        while (low<high)
        {
            p1=low+(high-low)/3;
            p2=high-(high-low)/3;
            long long ans1=calc(n, p1), ans2=calc(n, p2);
            if (low+1==high && ans1==ans2)
            {
                break;
            }
            if (low+2==high && ans1==ans2)
            {
                low++;
                break;
            }
            if (ans1>ans2)
            {
                high=p2-1;
            }
            else if (ans1<ans2)
            {
                low=p1+1;
            }
            else
            {
                low=p1, high=p2;
            }
        }
        cout << calc(n, low) << endl;
    }

    return 0;
}

/*
3
3
4
6
*/