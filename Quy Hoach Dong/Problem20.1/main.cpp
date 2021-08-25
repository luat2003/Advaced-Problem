#include <bits/stdc++.h>

using namespace std;

int n , m , l , r , a[310] , dp[310][310][310] , optl[310][310] , optr[310][310];

int main() {
    freopen("PIANO.inp","r",stdin);
    freopen("PIANO.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> l >> r;
    a[0] = -1e9;
    for (int i = 1 ; i <= m ; ++i) cin >> a[i];
    memset(dp , 0x3f , sizeof(dp));
    memset(optl , 0x3f , sizeof(optl));
    memset(optr , 0x3f , sizeof(optr));
    dp[0][0][0] = optl[0][0] = optr[0][0] = 0;
    int res = 1e9;
    for (int i = 1 ; i <= m ; ++i) {
        for (int lef = 0 ; lef <= m ; ++lef)
        for (int rig = 0 ; rig <= m ; ++rig)
        if ((a[lef] + l - 1 >= a[i] && a[lef] <= a[i]) || (a[rig] + r - 1 >= a[i] && a[rig] <= a[i])) {
            dp[i][lef][rig] = dp[i - 1][lef][rig];
            dp[i][lef][rig] = min(dp[i][lef][rig] , optl[i - 1][lef] + 1);
            dp[i][lef][rig] = min(dp[i][lef][rig] , optr[i - 1][rig] + 1);
        }
        for (int lef = 0 ; lef <= m ; ++lef)
        for (int rig = 0 ; rig <= m ; ++rig) {
            optl[i][lef] = min(optl[i][lef] , dp[i][lef][rig]);
            optr[i][rig] = min(optr[i][rig] , dp[i][lef][rig]);
            if (i == m) res = min(res , dp[i][lef][rig]);
        }
    }
    cout << res;
}
