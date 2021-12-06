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

int n, m, k, ans;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    vector<int> person(n), room(m);
    for (int i=0; i<n; i++)
    {
        cin >> person[i];
    }
    for (int i=0; i<m; i++)
    {
        cin >> room[i];
    }
    sort(person.begin(), person.end());
    sort(room.begin(), room.end());

    int j=0;
    for (int i=0; i<n; i++)
    {
        while (j<m-1 && room[j]<person[i]-k)
        {
            j++;
        }
        if (person[i]+k>=room[j] && person[i]-k<=room[j])
        {
            ans++;
            j++;
        }
    }

    cout << ans << endl;

    return 0;
}

/*
4 3 5
60 45 80 60
30 60 75
*/