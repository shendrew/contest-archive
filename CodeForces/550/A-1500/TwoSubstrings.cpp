#include <iostream>
#include <set>
#include <string>
using namespace std;

int ab, ba, ab2, ba2;
int main()
{
    string s;
    cin >> s;
    int i;
    for (i=0; i<s.size()-1; i++)
    {
        if (!ab && s.substr(i,2)=="AB")
            ab=i+1;
        if (!ba && s.substr(i,2)=="BA")
            ba=i+1;
    }
    for (i=ab+1; i<s.size()-1; i++)
    {
        if (s.substr(i,2)=="BA")
        {
            ab2=i;
            break;
        }
    }
    for (i=ba+1; i<s.size()-1; i++)
    {
        if (s.substr(i,2)=="AB")
        {
            ba2=i;
            break;
        }
    }
    if ((ab&&ab2) || (ba&&ba2))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
