#include <iostream>
#define N 10005
// Dãy con tăng chặt dài nhất
using namespace std;
int n, a[N], maxx = 0, dp[N], kt[N] = {0};

int dayConTangDaiNhat( int k){
    if( kt[k] == 1){
        return dp[k];
    }
    int x = 1;
    for( int i = k+1; i <= n; i++){
        if( a[i] > a[k] ){
            x = max(x, dayConTangDaiNhat(i)+1);
        }
    }
    dp[k] = x;
    kt[k] = 1;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for( int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for( int i = n; i >= 1; i--){
        maxx = max(maxx, dayConTangDaiNhat(i));
    }
    cout << maxx;
    return 0;
}
