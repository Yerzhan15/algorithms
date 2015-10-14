#include <stdio.h>


#define N 500000

long long d[20][N + 1];
int t[N + 1];
int i, j, test, n, K;
long long ans;

int is(int i) {
    int m = 0;
    while ((1 << m) < i)
        m++;
    return 1 * ((1 << m) - i == 0);
}

long long max(long long a, long long b) {
	if (a > b)
		return a;
	return b;
}

long long gcd(long long a, long long b) {
	while (a * b) {
		if (a < b) {
			long long d = a;
			a = b;
			b = d;
		}
		a = a % b;
	}
	return a + b;
}

long long GCD(int l, int r) {
	int k = t[r - l + 1];
	return gcd(d[k][l], d[k][r - (1 << k) + 1]);
}

int lower(int l, int r, int R, long long cur) {
	int res;
	while (r - l >= 0) {
		int m = (l + r) / 2;
		if (GCD(m, R) == cur) {
			res = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	return res;
}

int upper(int l, int r, int L, long long cur) {
	int res;
	while (r - l >= 0) {
		int m = (l + r) / 2;
		if (GCD(L, m) == cur) {
			res = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	return res;
}

int main(void) {
	// your code goes here
	
	scanf("%I64d", &test);
	
	for (i = 2; i < N; i++)
		t[i] = t[i - 1] + is(i); 
	
	while (test--) {
		scanf("%I64d", &n);
		
		ans = 0;
		for (i = 1; i <= n; i++) {
			scanf("%I64d", &d[0][i]);
			ans = max(ans, d[0][i]);
		}
		
		K = 2;
        while ((1 << K) < n)
            K++;
		
		for (i = 1; i <= K; i++)
			for (j = 1; j <= n - (1 << i) + 1; j++)
				d[i][j] = gcd(d[i - 1][j], d[i - 1][j + (1 << (i - 1))]);
		
		for (i = 1; i < n; i++) {
			int l = lower(1, i, i + 1, GCD(i, i + 1));
			int r = upper(i, n, i, GCD(i, i + 1));
			ans = max(ans, GCD(l, r) * (r - l + 1));
		}
		printf("%I64d\n", ans);
	}
	
	
	return 0;
}
