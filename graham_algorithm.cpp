// start time: 10:52 pm Oct 10
// end time: 11:37 pm Oct 10

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>


using namespace std;

#define INF 1000000000
#define ADD 10000000
#define sqr(a) (a) * (a)

#define N 410000


struct Tpoint {
	long long x, y;
}	a[N], b[N], s[N], mn;

long long Q, n, m, i, x, y;

void add(long long x, long long y) {
	++n;
	a[n].x = x + 1;	a[n].y = y;
	++n;
	a[n].x = x - 1;	a[n].y = y;
	++n;
	a[n].x = x;	a[n].y = y + 1;
	++n;
	a[n].x = x;	a[n].y = y - 1;
}

double len(Tpoint a, Tpoint c) {
	double x = abs(a.x - c.x);
	double y = abs(a.y - c.y);
	return min(x, y) * sqrt(2) + max(x, y) - min(x, y);
}

Tpoint make(Tpoint a, Tpoint b) {
	Tpoint c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return c;
}

long long product(Tpoint a, Tpoint b) {
	return a.x * b.y - a.y * b.x;
}

bool cmp(Tpoint a, Tpoint b) {
	return product(make(a, mn), make(b, mn)) < 0 || (product(make(a, mn), make(b, mn)) == 0 && len(a, mn) < len(b, mn));
}

int main() {
	
	while (cin >> Q) {
		m = n = 0;
		mn.x = INF;
		mn.y = INF;

		for (i = 0; i < Q; i++) {
			cin >> x >> y;
			add(x + ADD, y + ADD);
		}

		for (i = 1; i <= n; i++)
			if (a[i].x < mn.x || (a[i].x == mn.x && a[i].y < mn.y))
				mn = a[i];

		sort (a + 1, a + n + 1, cmp);

		s[++m] = a[1];
		s[++m] = a[2];
		
		for (i = 3; i <= n; i++) {
		  // here we want to delete some point which in convex hull and their vector product is < 0 (i.e right)
			while (m > 1 && product(make(s[m], s[m - 1]), make(a[i], s[m - 1])) > 0 
			|| (product(make(s[m], s[m - 1]), make(a[i], s[m - 1])) == 0 && len(s[m], s[m - 1]) < len(a[i], s[m - 1]))) 
				m--;
			s[++m] = a[i];
		}
        
        double ans = 0;

        s[m + 1] = s[1];
        for (i = 1; i <= m; i++)
        	ans += len(s[i + 1], s[i]);
	
	    printf("%.3lf\n", ans);
	}
		
	
	return 0;
}

