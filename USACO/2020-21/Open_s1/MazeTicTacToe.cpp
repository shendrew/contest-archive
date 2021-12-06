#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <numeric>
#include <math.h>
#include <string>
#include <string.h>
#include <iomanip>
#include <functional>
using namespace std;

#define f first
#define s second
#define ll long long

/*
0, 1, 2
3, 4, 5
6, 7, 8
*/
int n, bx, by;
int arr[25][25];
int board[9];
int vis[25][25][20000];
map<pair<int, int>, pair<int, int>> rule;
set<int> ans;

bool check(int n1, int n2, int n3)
{
    if (board[n1]+board[n2]+board[n3]==4 && board[n2]==1 && board[n1] && board[n3])
    {
        return true;
    }
    return false;
}

bool setBoard(int b)
{
    for (int i=0; i<9; i++)
    {
        board[i]=0;
    }
    for (int i=8; i>=0; i--)
    {
        for (int j=2; j>0; j--)
        {
            if (b>=j*pow(3, i))
            {
                board[i]=j;
                b-=j*pow(3, i);
                break;
            }
        }
    }

    bool ret=false;
    ret|=check(0, 1, 2);
    ret|=check(3, 4, 5);
    ret|=check(6, 7, 8);

    ret|=check(0, 3, 6);
    ret|=check(1, 4, 7);
    ret|=check(2, 5, 8);
    
    ret|=check(0, 4, 8);
    ret|=check(2, 4, 6);
    return ret;
}

void flood(int r, int c, int b)
{
    if (!arr[r][c] || vis[r][c][b])
    {
        return;
    }
    vis[r][c][b]=1;
    if (arr[r][c]==2 || arr[r][c]==3)
    {
        int val=arr[r][c]-1, ind=rule[{r, c}].f*3+rule[{r, c}].s;
        if ((b/(int)pow(3, ind))%3==0)
        {
            b+=val*pow(3, ind);
            vis[r][c][b]=1;
            if (setBoard(b))
            {
                ans.insert(b);
                return;
            }
        }
    }

    flood(r+1, c, b);
    flood(r-1, c, b);
    flood(r, c+1, b);
    flood(r, c-1, b);
}

int main()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        string str;
        cin >> str;
        for (int j=0; j<n; j++)
        {
            if (str[j*3]=='.')
            {
                arr[i][j]=1;
            }
            else if (str[j*3]=='O')
            {
                arr[i][j]=2;
                rule[{i, j}]={str[j*3+1]-'1', str[j*3+2]-'1'};
            }
            else if (str[j*3]=='M')
            {
                arr[i][j]=3;
                rule[{i, j}]={str[j*3+1]-'1', str[j*3+2]-'1'};
            }
            else if (str[j*3]=='B')
            {
                arr[i][j]=1;
                bx=i, by=j;
            }
        }
    }

    flood(bx, by, 0);

    cout << ans.size() << endl;

    return 0;
}

/*
7
#####################
###O11###...###M13###
###......O22......###
###...######M22######
###BBB###M31###M11###
###...O32...M33O31###
#####################
*/