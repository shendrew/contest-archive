#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("haybales.in");
ofstream fout("haybales.out");

int n, q;
vector<int> haybales;
vector<pair<int,int>> intervals;

int binSearch(int mn, int mx)
{
    int l=0, h=n-1, mid;
    while (l!=h)            // binary search for highest numebr lower than it *round down
    {
        mid=(l+h+1)/2;
        if (haybales[mid]>mx)
        {
            mid--;
            h=mid;
        }
        else if (haybales[mid]<mx)
        {
            l=mid;
        }
        if (haybales[mid]==mx)
        {
            break;
        }
    }
    int finish=mid;

    l=0, h=n-1;
    while (l!=h)        // binary search for lowest number higher than it *round up
    {
        mid=(l+h)/2;
        if (haybales[mid]>mn)
        {
            h=mid;
        }
        else if (haybales[mid]<mn)
        {
            mid++;
            l=mid;
        }
        if (haybales[mid]==mn)
        {
            break;
        }
    }
    int start=mid;

    return finish-start+1;
}

int main()
{
    fin >> n >> q;
    int i, searchLow, searchHigh;
    haybales.resize(n);
    for (i=0; i<n; i++)
    {
        fin >> haybales[i];
    }
    sort(haybales.begin(),haybales.end());
    for (i=0; i<q; i++)
    {
        fin >> searchLow >> searchHigh;
        if (searchLow>haybales[n-1] || searchHigh<haybales[0]) // if the interval is outside of the data *ignore
        {
            fout << 0 << endl;
        }
        else
        {
            fout << binSearch(searchLow,searchHigh) << endl;
        }
    }
    return 0;
}
