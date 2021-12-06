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
int t;

string to26(int n)
{
    string str="";
    while (n)
    {
        if (!(n%26))
        {
            str='Z'+str;
            n/=26;
            n--;
            continue;
        }
        str=(char)((n%26)+'A'-1)+str;
        n/=26;
    }
    return str;
}

int toDecimal(string str)
{
    int n=0, exponent=1;
    for (int i=0; i<str.size(); i++)
    {
        n+=(str[str.size()-i-1]-'A'+1)*exponent;
        exponent*=26;
    }
    return n;
}

int main()
{
    cin >> t;
    
    for (int i=0; i<t; i++)
    {
        string str;
        cin >> str;
        
        bool decimal=false, preInt=false;
        for (int j=0; j<str.size(); j++)
        {
            if (preInt && str[j]=='C')
            {
                decimal=true;
                break;
            }
            if (isdigit(str[j]))
            {
                preInt=true;
            }
        }

        int col;
        if (!decimal)
        {
            int ind=0;
            for (int j=0; j<str.size(); j++)
            {
                if (isdigit(str[ind]))
                {
                    break;
                }
                ind++;
            }
            col=toDecimal(str.substr(0, ind));

            cout << "R" << str.substr(ind) << "C" << col << endl;
        }
        else
        {
            int ind_c=str.find('C');
            col=stoi(str.substr(ind_c+1));

            cout << to26(col) << str.substr(1, ind_c-1) << endl;
        }
    }

    return 0;
}

/*
2
R23C55
BC23
*/