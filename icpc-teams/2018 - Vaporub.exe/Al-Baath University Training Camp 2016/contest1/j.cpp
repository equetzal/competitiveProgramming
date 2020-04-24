//2016 Al-Baath University Training Camp Contest-1
//CF Gym 101028J - X and Beasts
//UPSOLVING

#include <bits/stdc++.h>

using namespace std;
 
int n, a[110], v[110], memo[110][110];
 
int getPower(int x) {
    int s = 0;
    while (x % 2 == 0) {
        s++;
        x /= 2;
    }
    return s;
}
 
int dp(int prev, int idx) {
    if (idx == n + 1) return 0;
    if (memo[prev][idx] != -1) return memo[prev][idx];
    if (a[prev] > a[idx])
        return memo[prev][idx] = dp(prev, idx + 1);
    return memo[prev][idx] = max(dp(prev, idx + 1), dp(idx, idx + 1) + v[idx]);
}
 
int main() {
    int TC;
    
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d", &n);
        a[0] = -1e9;
        v[0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            v[i] = getPower(a[i]);
        }
        
        int ans = -1;
        memset(memo, -1, sizeof(memo));
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp(i, i + 1));
        }
        printf("%d\n", ans);
    }
    return 0;
}
