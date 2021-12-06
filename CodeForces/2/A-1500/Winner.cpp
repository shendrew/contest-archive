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
int n, maxm;
string name[1000];
int score[1000];
map<string, int> m;

int main()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int scr;
        cin >> name[i] >> scr;
        m[name[i]]+=scr;
        score[i]=m[name[i]];
    }

    for (int i=0; i<n; i++)
    {
        maxm=max(maxm, m[name[i]]);
    }

    for (int i=0; i<n; i++)
    {
        if (m[name[i]]==maxm && score[i]>=maxm)
        {
            cout << name[i] << endl;
            break;
        }
    }
    return 0;
}

/*
3
andrew 3
andrew 2
mike 5
*/