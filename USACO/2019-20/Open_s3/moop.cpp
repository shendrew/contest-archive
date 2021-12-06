#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("moop.in");
ofstream fout("moop.out");

int n;
vector<long> lower;
vector<pair<long,long>> vp;

int main()
{
    fin >> n;
    vp.resize(n);
    for(int i=0; i<n; i++)
    {
        fin >> vp[i].first >> vp[i].second;
    }
    sort(vp.begin(),vp.end());
    lower.push_back(vp[0].second);
    for (int i=1; i<n; i++)
    {
        if (lower[0]>vp[i].second)
            lower.insert(lower.begin(), vp[i].second);
        else if (lower.size()>1)
        {
            int c = 1;
            while (lower[c] <= vp[i].second && c<lower.size())
                c++;
            lower.erase(lower.begin()+1,lower.begin()+c);
        }
    }
    cout << lower.size() << endl;
    fout << lower.size() << endl;
    return 0;
}

