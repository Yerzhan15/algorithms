// hackerrank problem "PLaying with numbers"

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define N 1000000

long long pos, sum[N], a[N];
long long l1, l2, i, n, q, l, x, r, add = 0;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    cin >> n;
    for (i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    
    sort (a + 1, a + n + 1);
    
    for (i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    
    cin >> q;
    for (i = 1; i <= q; i++)  {
        scanf("%lld", &x);
        add += x;
        l = 1;  r = n;
        
        //binary search
        while (r - l >= 0) {
            int m = (l + r) / 2;
            if (a[m] + add >= 0) {
                pos = m;
                r = m - 1;
            }
            else
                l = m + 1;		
        }
        
        //cout << add << " pos is "<< pos << endl;
        
        long long ans1 = abs((sum[n] - sum[pos - 1]) + add * (n - pos + 1));
        long long ans2 = abs(sum[pos - 1] + add * (pos - 1));
        
        printf("%lld\n", ans1 + ans2);
    }
    
    
    return 0;
}
