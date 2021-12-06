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
long long k;
long long occ[10];
string str="codeforces";

int main()
{
    for (int i=0; i<10; i++)
    {
        occ[i]=1;
    }
    cin >> k;
    long long sub=1, ind=0;
    while (sub<k)
    {
        sub/=occ[ind];
        occ[ind]++;
        sub*=occ[ind];
        ind++;
        ind%=10;
    }
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<occ[i]; j++)
        {
            cout << str[i];
        }
    }
    return 0;
}

/*
5
*/