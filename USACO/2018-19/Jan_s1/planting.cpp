#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("planting.in");
ofstream fout("planting.out");

int n, total;
int graph[100001];

int main()
{
    fin >> n;
    int i, a, b;
    for (i=0; i<n-1; i++)
    {
        fin >> a >> b;
        graph[a]++, graph[b]++;
    }

    for (i=1; i<=n;i++)
    {
        total=max(total,graph[i]);
    }
    fout << total+1;
    return 0;
}
