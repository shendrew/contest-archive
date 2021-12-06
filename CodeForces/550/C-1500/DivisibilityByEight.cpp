#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;
vector<string> num;
bool ans;

int main()
{
    cin >> s;
    int i, j;
    for (i=0; i<=999; i++)
    {
        if (i%8==0)
            num.push_back(to_string(i));
    }
    for (i=0; i<num.size(); i++)
    {
        int digit=0;
        for (int j=0; j<s.size(); j++)
        {
            if (num[i][digit]==s[j])
            {
                digit++;
            }
            if (digit==num[i].size())
            {
                ans=true;
                break;
            }
        }
        if (ans)
        {
            cout << "YES" << endl << num[i];
            ans=true;
            break;
        }
    }
    if (!ans)
        cout << "NO";
    return 0;
}
