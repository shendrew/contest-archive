#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("lemonade.in");
ofstream fout("lemonade.out");

int n;
vector <int> v;

int main()
{
    fin >> n;
    v.resize(n);
    int i;
    for (i=0; i<n; i++)
    {
        fin >> v[i];
    }
    sort(v.begin(),v.end());
    reverse(v.begin(), v.end());
    for (i=0; i<n; i++)
    {
        if (v[i]<i)
        {
            break;
        }
    }
    fout << i;
    
    return 0;
}
