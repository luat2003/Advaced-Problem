#include <bits/stdc++.h>

#define N 50005

using namespace std;

int n;
int xs[N], ys[N];

int p[N], px[N], pp[N], pm[N];
int nextL[N], nextR[N], nextU[N];
int dp[N], maxL[N], maxR[N];

bool cmp_x(int i, int j) {
    return xs[i] < xs[j] || (xs[i] == xs[j] && ys[i] < ys[j]);
}

bool cmp_y(int i, int j) {
    return ys[i] < ys[j] || (ys[i] == ys[j] && xs[i] < xs[j]);
}

bool cmp_x_plus_y(int i, int j) {
    int ti = xs[i] + ys[i];
    int tj = xs[j] + ys[j];
    return ti < tj || (ti == tj && ys[i] < ys[j]);
}

bool cmp_x_minus_y(int i, int j) {
    int ti = xs[i] - ys[i];
    int tj = xs[j] - ys[j];
    return ti < tj || (ti == tj && ys[i] < ys[j]);
}

int main() {
    // freopen("queen.inp", "r", stdin);
    // freopen("queen.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> xs[i] >> ys[i];
        p[i] = pp[i] = pm[i] = px[i] = i;
    }
    sort(p, p + n + 1, cmp_y);
    sort(px, px + n + 1, cmp_x);
    sort(pp, pp + n + 1, cmp_x_plus_y);
    sort(pm, pm + n + 1, cmp_x_minus_y);
    for (int i = 0; i < n; i++) {
        int j = pp[i];
        int nx = pp[i + 1];
        if (xs[j] + ys[j] == xs[nx] + ys[nx]) {
            nextL[j] = nx;
        }
        j = pm[i];
        nx = pm[i + 1];
        if (xs[j] - ys[j] == xs[nx] - ys[nx]) {
            nextR[j] = nx;
        }
        j = px[i];
        nx = px[i + 1];
        if (xs[j] == xs[nx]) {
            nextU[j] = nx;
        }
    }
    dp[0] = 1;
    for (int i = 0, j = 0; i <= n; i = j) {
        int y = ys[p[i]];
        while (j <= n && y == ys[p[j]]) {
            j++;
        }
        maxL[i - 1] = maxR[j] = 0;
        for (int k = i; k < j; k++) {
            maxL[k] = max(maxL[k - 1], dp[p[k]]);
        }
        for (int k = j - 1; k >= i; k--) {
            maxR[k] = max(maxR[k + 1], dp[p[k]]);
        }
        for (int k = i; k < j; k++) {
            if (dp[p[k]] > 0) {
                dp[p[k]]++;
            }
            if (maxL[k - 1] > 0) {
                dp[p[k]] = max(dp[p[k]], maxL[k - 1] + k - i + 1);
            }
            if (maxR[k + 1] > 0) {
                dp[p[k]] = max(dp[p[k]], maxR[k + 1] + j - k);
            }
            if (nextL[p[k]]) {
                dp[nextL[p[k]]] = max(dp[nextL[p[k]]], dp[p[k]]);
            } 
            if (nextR[p[k]]) {
                dp[nextR[p[k]]] = max(dp[nextR[p[k]]], dp[p[k]]);
            }
            if (nextU[p[k]]) {
                dp[nextU[p[k]]] = max(dp[nextU[p[k]]], dp[p[k]]);
            }
        }
    }
    int res = *max_element(dp, dp + n + 1);
    cout << (res - 2);
}