#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("paintbarn.in");
ofstream fout("paintbarn.out");

int n,k,total;
int a[1001][1001];

int main()
{
    fin >> n >> k;
    int i, j, x1, y1, x2, y2;
    for (i=0; i<n; i++)
    {
        fin >> x1 >> y1 >> x2 >> y2;
        for (int xi=x1; xi<x2; xi++)
        {
            a[xi][y1]++;
            a[xi][y2]--;
        }
    }
    for (i=0; i<1001; i++)
    {
        for (j=0; j<1001; j++)
        {
            if (a[i][j]==k)
                total++;
            a[i][j+1]+=a[i][j];
        }
    }
    fout << total;
    return 0;
}

