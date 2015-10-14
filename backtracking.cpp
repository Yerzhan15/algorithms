#ifdef WIN32
    #define I "%I64d"
        #else
    #define I "%lld"
#endif
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <algorithm>
#include <windows.h>
#include <cmath>
#include <math.h>
#include <string>
#include <string.h>
#include <cstring>
#include <ctime>
#include <time.h>
#include <vector>
#include <map>
inline int Rand() {return (rand() << 16) | rand();}
inline int max(int x, int y) {return (x > y ? x : y);}
inline int min(int x, int y) {return (x < y ? x : y);}
#define y1 abcde
#define sqr(a) (a) * (a)
using namespace std;


char a[11][11];
int t, n = 10, i, j;
string tmp;
bool used[11][11];


bool valid(int u, int v, char C) {
    if (u && v && u <= n && v <= n && a[u][v] == C) {
        if (a[u][v] == 'B' && used[u][v])
            return false;
        return true;
    }
    return false;
}

int add[2] = {-1, 1}, startx, starty;

int dfs(int x, int y) {
    int res = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            int u = x + add[i];
            int v = y + add[j];
            if (valid(u, v, 'B')) {
                u = x + 2 * add[i];
                v = y + 2 * add[j];
                if (valid(u, v, '#') || (u == startx && v == starty)) {
                    used[x + add[i]][y + add[j]] = true;
                    // before we enter the new STATE of game we denote that we have passed this cell
                    res = max(res, dfs(u, v));
                    used[x + add[i]][y + add[j]] = false;
                    // after DFS the cell was not entered because we have returned from it
                }
            }
        }
    return res + 1;
}

int main()  {
    srand(GetTickCount());
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r" , stdin);
    freopen("a.out", "w", stdout);
    #endif

    cin >> t;
    while (t--) {
        getline(cin, tmp);
        int ans = 0;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                cin >> a[i][j];

        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (a[i][j] == 'W') {
                    startx = i;
                    starty = j;
                    ans = max(ans, dfs(i, j) - 1);
                }
        cout << ans << endl;
    }


    return 0;
}
