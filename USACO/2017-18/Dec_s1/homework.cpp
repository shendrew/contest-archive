#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

ifstream fin("homework.in");
ofstream fout("homework.out");

int n;
float maxscore;
vector<int> v, lowest, ans;

int main()
{
    fin >> n;
    v.resize(n);
    int i;
    for (i=0; i<n; i++)
    {
        fin >> v[i];
    }
    
    lowest=v;
    sort(lowest.begin(),lowest.end());
    int sum=accumulate(v.begin(), v.end(), 0);
    float m;
    for (i=0; i<n-2; i++)
    {
        vector<int>::iterator position = find(lowest.begin(), lowest.end(), v[i]);
        if (position != lowest.end())
            lowest.erase(position);
        sum-=v[i];
        m=(sum-lowest[0])/(lowest.size()-1);
        if (m>maxscore)
        {
            maxscore=m;
            ans.resize(0);
            ans.push_back(i+1);
        }
        else if (m==maxscore)
        {
            ans.push_back(i+1);
        }
    }
    
    for (i=0; i<ans.size(); i++)
    {
        fout << ans[i] << endl;
    }
        
    return 0;
}
