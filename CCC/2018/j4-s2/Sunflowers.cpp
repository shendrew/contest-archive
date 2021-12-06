#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> v;

int main()
{
    cin >> n;
    v.resize(n);
    int i, j;
    for (i=0; i<n; i++)
    {
        v[i].resize(n);
        for (j=0; j<n; j++)
        {
            cin >> v[i][j];
        }
    }
    
    bool done=false;
    while (!done)
    {
        vector<vector<int>> correct;
        for (i=0; i<n; i++)
        {
            vector<int> sorted=v[i];
            sort(sorted.begin(),sorted.end());
            correct.push_back(sorted);
        }
        sort(correct.begin(),correct.end());
        if (v==correct)
        {
            done=true;
        }
        else
        {
            vector<vector<int>> v2;
            v2.resize(n);
            for (i=0; i<n; i++)
            {
                v2[i].resize(n);
            }
            for (i=0; i<n; i++)
            {
                for (j=0; j<n; j++)
                {
                    v2[i][j]=v[n-1-j][i];
                }
            }
            v=v2;
        }
    }
    
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/*
2
1 3
2 9
*/
