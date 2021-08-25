#include <bits/stdc++.h>

#define N 50005

using namespace std;

int n;
int xs[N], ys[N]; // Mảng toạ độ các quân tốt

int p[N], px[N], pp[N], pm[N]; // Mảng sort theo hàng - cột - chéo phải - chéo trái
int nextL[N], nextR[N], nextU[N];
int dp[N], maxL[N], maxR[N];

// sort theo cột tăng dần nếu 2 quân tốt cùng cột sẽ sort hàng tăng dần
bool cmp_x(int i, int j) {
    return xs[i] < xs[j] || (xs[i] == xs[j] && ys[i] < ys[j]); 
}

// sort theo hàng tăng dần nếu 2 quân tốt cùng hàng thì cột tăng dần
bool cmp_y(int i, int j) {
    return ys[i] < ys[j] || (ys[i] == ys[j] && xs[i] < xs[j]);
}

// sort theo chéo phải, theo tổng toạ dộ tăng dần, nếu cùng tổng thì sort theo hàng tăng dần
bool cmp_x_plus_y(int i, int j) {
    int ti = xs[i] + ys[i];
    int tj = xs[j] + ys[j];
    return ti < tj || (ti == tj && ys[i] < ys[j]);
}

// sort theo chéo trái, theo hiệu toạ độ tăng dần, nếu cùng hiệu thì sort theo hàng tăng dần
bool cmp_x_minus_y(int i, int j) {
    int ti = xs[i] - ys[i];
    int tj = xs[j] - ys[j];
    return ti < tj || (ti == tj && ys[i] < ys[j]);
}

int main() {
    // freopen("queen.inp", "r", stdin);
    // freopen("queen.out", "w", stdout);
    cin >> n;

    // gán cho các mảng p, pp, pm, px ban đầu từ 1 - > n
    for (int i = 1; i <= n; i++) {
        cin >> xs[i] >> ys[i];
        p[i] = pp[i] = pm[i] = px[i] = i;
    }

    // p sẽ là thứ tự các quân tốt theo sort hàng tăng dần
    sort(p, p + n + 1, cmp_y);

    // px sẽ là thứ tự các quân tốt theo sort cột tăng dần
    sort(px, px + n + 1, cmp_x);

    // pp sẽ là thứ tự các quân tốt theo sort tổng toạ độ tăng dần
    sort(pp, pp + n + 1, cmp_x_plus_y);

    // pm sẽ là thứ tự các quân tốt theo sort hiệu toạ độ tăng dần
    sort(pm, pm + n + 1, cmp_x_minus_y);

    // Với mỗi quân tốt i sẽ tìm quân tốt gần nhất ở trên, chéo trái, chéo phải
    for (int i = 0; i < n; i++) {

    	// tìm quân tốt gần nhất nằm trên chéo trái ( nếu có )
        int j = pp[i];
        int nx = pp[i + 1];
        if (xs[j] + ys[j] == xs[nx] + ys[nx]) {
            nextL[j] = nx;
        }

        // tìm quân tốt gần nhất nằm trên chéo phải ( nếu có )
        j = pm[i];
        nx = pm[i + 1];
        if (xs[j] - ys[j] == xs[nx] - ys[nx]) {
            nextR[j] = nx;
        }

        // tìm quân tốt gần nhất nằm trên đường thẳng lên trên ( nếu có )
        j = px[i];
        nx = px[i + 1];
        if (xs[j] == xs[nx]) {
            nextU[j] = nx;
        }
    }

    // Chạy quy hoạch động
    dp[0] = 1;

    // chạy từng hàng
    for (int i = 0, j = 0; i <= n; i = j) {

    	// Tìm quân tốt nằm ở hàng trên gần nhất với quân tốt p[i] ( chạy lần lượt theo sort hàng )
        int y = ys[p[i]];
        while (j <= n && y == ys[p[j]]) {
            j++;
        }

        maxL[i - 1] = maxR[j] = 0;

        // xét trong hàng của quân tốt i

        // Với mỗi hàng thì luôn có cách ăn hết quân tốt nằm ở một trong 2 phía của quân i

        // mảng cộng dồn nếu chạy lên phía bên trái của quân i thì trước đó đã ăn được nhiều nhất bao nhiêu quân
        for (int k = i; k < j; k++) {
            maxL[k] = max(maxL[k - 1], dp[p[k]]);
        }

        // mảng cộng dồn nếu chạy lên phía bên phải của quân p[i] thì trước đó đã ăn được nhiều nhất bao nhiêu quân
        for (int k = j - 1; k >= i; k--) {
            maxR[k] = max(maxR[k + 1], dp[p[k]]);
        }

        // chạy hết quân tốt trên hàng quân tốt p[i]
        for (int k = i; k < j; k++) {

        	// Nếu có đường đi từ quân khác đến quân p[k] tức là trc p[k] đã ăn một số quân tốt rồi thì ta sẽ +1 vào ( ăn thêm quân tốt p[k])
            if (dp[p[k]] > 0) {
                dp[p[k]]++;
            }

            // Nếu chạy lên phía trái của quân tốt p[k] thì sẽ cộng thêm số quân tốt nằm bên trái quân tốt p[k] ( từ p[i] ), tính cả p[k]
            if (maxL[k - 1] > 0) {
                dp[p[k]] = max(dp[p[k]], maxL[k - 1] + k - i + 1);
            }

            // Nếu chạy lên phía phải của quân tốt p[k] thì sẽ cộng thêm số quân tốt nằm bên phải quân tốt p[k] ( từ p[i] ), tính cả p[k]
            if (maxR[k + 1] > 0) {
                dp[p[k]] = max(dp[p[k]], maxR[k + 1] + j - k);
            }

            // Nếu có quân phía chéo trái thì dp của chéo trái sẽ = max( dp[p[k]], dp[chéo trái])
            if (nextL[p[k]]) {
                dp[nextL[p[k]]] = max(dp[nextL[p[k]]], dp[p[k]]);
            } 

            // tương tự với chéo phải
            if (nextR[p[k]]) {
                dp[nextR[p[k]]] = max(dp[nextR[p[k]]], dp[p[k]]);
            }

            // tương tự với thẳng
            if (nextU[p[k]]) {
                dp[nextU[p[k]]] = max(dp[nextU[p[k]]], dp[p[k]]);
            }
        }
    }
    int res = *max_element(dp, dp + n + 1); // tìm cách đi ăn được nhiều quân tốt nhất khi kết thúc tại quân tốt i
    cout << (res - 2);
}