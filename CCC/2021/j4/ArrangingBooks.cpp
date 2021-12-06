#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <string>
using namespace std;

#define f first
#define s second
int ans, outOfPlace;
string str;
vector<int> v, sorted;
int a[4][4];

void swap(int x, int y)
{
    int swaps=min(a[x][y], a[y][x]);
    ans+=swaps;
    a[x][y]-swaps, a[y][x]-swaps;
    outOfPlace-=2*swaps;
}

int main()
{
    cin >> str;
    for (int i=0; i<str.size(); i++)
    {
        if (str[i]=="L"[0])
        {
            v.push_back(3);
            sorted.push_back(3);
        }
        else if (str[i]=="M"[0])
        {
            v.push_back(2);
            sorted.push_back(2);
        }
        else
        {
            v.push_back(1);
            sorted.push_back(1);
        }
    }
    sort(sorted.begin(), sorted.end());
    reverse(sorted.begin(), sorted.end());

    for (int i=0; i<str.size(); i++)
    {
        a[v[i]][sorted[i]]++;
        outOfPlace+=(v[i]!=sorted[i]);
    }

    swap(1,2);
    swap(1,3);
    swap(2,3);
    ans+=(outOfPlace/3)*2;

    cout << ans << endl;

    return 0;
}
/*
LLSLM
*/