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

string str;
int q, n;
multiset<int> dif, len;

void mod(int x)
{
    if (x==1 || x==n+1)
    {
        return;
    }
    if (dif.find(x)!=dif.end())
    {
        auto ind=dif.find(x);
        len.erase(len.find(*next(ind)-*ind));
        len.erase(len.find(*ind-*prev(ind)));
        len.insert(*next(ind)-*prev(ind));
        dif.erase(x);
    }
    else
    {
        dif.insert(x);
        auto ind=dif.find(x);
        len.erase(len.find(*next(ind)-*prev(ind)));
        len.insert(*ind-*prev(ind));
        len.insert(*next(ind)-*ind);
    }
}

int main()
{
    cin >> str >> q;
    n=str.size();

    int pre=-1;
    dif.insert(n+1);
    for (int i=0; i<n; i++)
    {
        if (pre!=str[i]-'0')
        {
            dif.insert(i+1);
        }
        pre=str[i]-'0';
    }
    dif.insert(0);
    for (auto i=next(dif.begin()); i!=dif.end(); i++)
    {
        len.insert(*i-*prev(i));
    }

    for (int i=0; i<q; i++)
    {
        int x;
        cin >> x;

        mod(x);
        mod(x+1);

        cout << *len.rbegin() << " ";
    }
    cout << endl;

    return 0;
}

/*
001011
3
3 2 5
*/