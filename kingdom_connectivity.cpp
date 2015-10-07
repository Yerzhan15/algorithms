#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define N 200000
#define INF 1000000000
#define mod (long long)1e9
     


vector <vector <int> > v1(N);
map <pair<int, int>, int> cnt;

int ts[N], color[N];
long long d[N];
int i, j, n, m, a, b, tsz, u;
int res[N];




void read() {
	cin >> n >> m;
	for (i = 1; i <= m; i++) {
		cin >> a >> b;
		if (!cnt[make_pair(a, b)])
			v1[a].push_back(b);
		cnt[make_pair(a, b)]++;
	}	
}

int dfs(int u) {
	res[u] = -1;
    bool cycle = false;
	color[u] = 1;	
	for (int i = 0; i < v1[u].size(); i++) {
		int to = v1[u][i];
		if (!color[to])	
			res[u] = max(res[u], dfs(to));
		else { 
			if (color[to] & 1) 
				cycle = true;
			else
				res[u] = max(res[u], res[to]);				
		}
	}

	color[u] = 2;
	ts[++tsz] = u;
	if (u != n) {
		if (cycle && res[u] > -1)
			res[u] = 1;
		// cout << u << " " << res[u] << endl;
		return res[u];
	} else {
		// cout << u << " " << 0 << endl;
		return 0;
	}
}

void solve() {
	if (dfs(1) == 1) {
		cout << "INFINITE PATHS";
	} else {
		d[1] = 1;
		for (i = n; i >= 1; i--) {
			u = ts[i];
			for (j = 0; j < v1[u].size(); j++) {
				int to = v1[u][j];
				d[to] = (d[to] + (d[u] * cnt[make_pair(u, to)]) % mod) % mod;
			}
		}
		cout << d[n];	
	}
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    freopen("input.txt", "r", stdin);

    read();
    solve();

    return 0;
}
