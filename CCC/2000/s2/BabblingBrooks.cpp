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

int n;

int main()
{
    cin >> n;
    vector<double> v(n+1);
    for (int i=1; i<=n; i++)
    {
        cin >> v[i];
    }
    
    int instruction=0;
    while (instruction!=77)
    {
        cin >> instruction;
        int ind, ratio;
        if (instruction==99)
        {
            cin >> ind >> ratio;
            double cur=v[ind];

            v[ind]=cur*ratio/100;
            v.insert(v.begin()+ind+1, cur*(100-ratio)/100);
        }
        else if (instruction==88)
        {
            cin >> ind;
            v[ind]=v[ind]+v[ind+1];
            v.erase(v.begin()+ind+1);
        }
    }

    for (int i=1; i<v.size(); i++)
    {
        cout << (int)(v[i]+0.5) << " ";
    }
    cout << endl;

    return 0;
}

/*
3
10
20
30
99
1
50
88
3
88
2
77
*/