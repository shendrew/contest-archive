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

ifstream fin("measurement.in");
ofstream fout("measurement.out");

int n, g, ans;

int main()
{
    fin >> n >> g;
    vector<vector<int>> log;
    for (int i=0; i<n; i++)
    {
        vector<int> li(3);
        fin >> li[0] >> li[1] >> li[2];
        log.push_back(li);
    }

    sort(log.begin(), log.end());

    map<int, int> milk;
    set<pair<int, int>, greater<pair<int, int>>> rank;
    for (int i=0; i<n; i++)
    {
        rank.insert({g, log[i][1]});
        milk[log[i][1]]=g;
    }


    int i=0, curMax=0;
    set<int> board, newBoard;
    while (i<n)
    {
        int day=log[i][0];
        while (i<n && log[i][0]==day)
        {
            int cow=log[i][1], change=log[i][2];
            pair<int, int> pos={milk[cow], cow};
            milk[cow]+=change;
            rank.erase(pos);
            rank.insert({milk[cow], cow});
            i++;
        }

        newBoard={};
        int best=(*rank.begin()).f;
        for (auto &j: rank)
        {
            if (j.f != best)
            {
                break;
            }
            newBoard.insert(j.s);
        }
        if (board!=newBoard)
        {
            board=newBoard;
            ans++;
        }
    }

    fout << ans << endl;

    return 0;
}

/*
4 10
7 3 +3
4 2 -1
9 3 -1
1 1 +2
*/