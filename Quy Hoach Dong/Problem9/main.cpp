#include <iostream>
#define N 105
using namespace std;
int s = 0, a[N], n, dp[10005] = {0}, kt[10005] = {0};

void chenhLechNhoNhat(){
    dp[0] = 1;
    for( int i = 1; i <= n; i++){
        for( int j = s; j >= a[i]; j--){
            if( dp[j] == 0 && dp[j-a[i]] == 1){
                dp[j] = 1;
                kt[j] = 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for( int i = 1; i <= n; i++){
        cin >> a[i];
        s += a[i];
    }
    chenhLechNhoNhat();
    for( int k = s/2; k >= 0; k--){
        if( dp[k] > 0 && kt[k] > 0){
            cout << s - 2*k;
            return 0;
        }
    }
    return 0;
}
