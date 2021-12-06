#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("herding.in");
ofstream fout("herding.out");

int n, minMoves, maxMoves;
vector<int> a;

int slidingWindow()
{
    if ((a[n-2]-a[0]==n-2 && a[n-1]-a[n-2]>2) || (a[n-1]-a[1]==n-2 && a[1]-a[0]>2)) // special case listed in the solution
    {
        return 2;
    }

    int i, j, mx=0;
    for (i=0; i<n; i++) // sliding window
    {
        j=i;
        while (j+1<n && a[j+1]-a[i]<=n-1)
        {
            j++;
        }
        mx=max(mx, j+1-i);
    }
    return n-mx;
}

int main()
{
    fin >> n;
    int i;
    a.resize(n);
    for (i=0; i<n; i++)
    {
        fin >> a[i];
    }

    sort(a.begin(),a.end());
    minMoves=slidingWindow();
    maxMoves=max(a[n-2]-a[0],a[n-1]-a[1])-(n-2); // utilize all of the other spaces expect the smaller gap at the ends
    fout << minMoves << endl << maxMoves;
    return 0;
}
