#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
using namespace std;

#define f first
#define s second
int n, m, k;
map<int,int> rm, cm;
set<int> row, col;

int main()
{
    cin >> n >> m >> k;
    for (int i=0; i<k; i++)
    {
        string dir;
        int num;
        cin >> dir >> num;
        if (dir=="R")
        {
            rm[num]++;
            row.insert(num);
        }
        else
        {
            cm[num]++;
            col.insert(num);
        }
    }

    long long rcount=0, ccount=0;
    for (auto &i : row)
    {
        if (rm[i]%2==1)
        {
            rcount++;
        }
    }
    for (auto &i : col)
    {
        if (cm[i]%2==1)
        {
            ccount++;
        }
    }
    long long ans=(rcount*m)+(ccount*n)-(rcount*ccount*2);
    cout << ans << endl;

    return 0;
}
/*
3
3
2
R 1
C 1

4
5
7
R 3
C 1
C 2
R 2
R 2
C 1
R 4
*/