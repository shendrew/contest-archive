#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <string>
using namespace std;

#define f first
#define s second
int ans;
string needle, hay, sub;
map<size_t, int> visit;
hash<string> hasher;

void check(map<int,int> nm, map<int,int> hm)
{
    bool same=true;
    for (int j=0; j<26; j++)
    {
        if (nm[j]!=hm[j])
        {
            same=false;
            break;
        }
    }
    if (same && !visit[hasher(sub)])
    {
        ans++;
        visit[hasher(sub)]++;
    }
}

int main()
{
    cin >> needle >> hay;
    int n=needle.size(), h=hay.size();

    map<int, int> nmp, hmp;
    sub=hay.substr(0, n);
    for (int i=0; i<n; i++)
    {
        nmp[needle[i]-'a']++;
        hmp[sub[i]-'a']++;
    }
    check(nmp, hmp);

    for (int i=1; i<=h-n; i++)
    {
        sub=hay.substr(i, n);
        hmp[hay[i-1]-'a']--;
        hmp[hay[i+n-1]-'a']++;
        check(nmp, hmp);
    }

    cout << ans << endl;

    return 0;
}

/*
aab
abacabaa
*/