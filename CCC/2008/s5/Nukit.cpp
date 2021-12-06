#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n;
map<vector<int>, bool> dp;

bool nuk_reaction(int pa, int pb, int pc, int pd)
{
    int a=pa, b=pb, c=pc, d=pd;
    if (dp.count({pa,pb,pc,pd})) return dp[{pa,pb,pc,pd}];
    vector<vector<int>> move={{2,1,0,2}, {1,1,1,1}, {0,0,2,1}, {0,3,0,0}, {1,0,0,1}};
    vector<vector<int>> result_a;
    for (auto &option_a : move)
    {
        if (pa-option_a[0]>=0 && pb-option_a[1]>=0 && pc-option_a[2]>=0 && pd-option_a[3]>=0)
        {
            result_a.push_back({pa-option_a[0],pb-option_a[1],pc-option_a[2],pd-option_a[3]});
        }
    }
    if (!result_a.size())
    {
        dp[{a,b,c,d}]=false;
        return false;
    }
    for (auto &possible_a : result_a)
    {
        vector<vector<int>> result_b;
        pa=possible_a[0], pb=possible_a[1], pc=possible_a[2], pd=possible_a[3];
        for (auto &option_b : move)
        {
            if (pa-option_b[0]>=0 && pb-option_b[1]>=0 && pc-option_b[2]>=0 && pd-option_b[3]>=0)
            {
                result_b.push_back({pa-option_b[0],pb-option_b[1],pc-option_b[2],pd-option_b[3]});
            }
        }
        if (!result_b.size())
        {
            dp[{a,b,c,d}]=true;
            return true;
        }
        bool a_wins;
        for (auto &possible_b : result_b)
        {
            pa=possible_b[0], pb=possible_b[1], pc=possible_b[2], pd=possible_b[3];
            a_wins=nuk_reaction(pa,pb,pc,pd); //RECURSIVE
            if (!a_wins)
                break;
        }
        if (a_wins)
        {
            dp[{a,b,c,d}]=true;
            return true;
        }
    }
    dp[{a,b,c,d}]=false;
    return false;
}

int main()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (nuk_reaction(a, b, c, d))
            cout << "Patrick" << endl;
        else
            cout << "Roland" << endl;
    }
}

/*
6
0 2 0 2
1 3 1 3
1 5 0 3
3 3 3 3
8 8 6 7
8 8 8 8
*/
