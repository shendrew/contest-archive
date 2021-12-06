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
        int n, m;
        cin >> n >> m;
        multiset<pair<int, char>> uni;
        for (int i=0; i<n; i++)
        {
            string str;
            cin >> str;
            for (int j=0; j<m; j++)
            {
                uni.insert({j, str[j]});
            }
        }
        for (int i=0; i<n-1; i++)
        {
            string str;
            cin >> str;
            for (int j=0; j<m; j++)
            {
                uni.erase(uni.find({j, str[j]}));
            }
        }
        for (auto &i: uni)
        {
            cout << i.s;
        }
        cout << endl << flush;
    }

    return 0;
}

/*
3
3 5
aaaaa
bbbbb
ccccc
aaaaa
bbbbb
3 4
aaaa
bbbb
cccc
aabb
bbaa
5 6
abcdef
uuuuuu
kekeke
ekekek
xyzklm
xbcklf
eueueu
ayzdem
ukukuk
*/