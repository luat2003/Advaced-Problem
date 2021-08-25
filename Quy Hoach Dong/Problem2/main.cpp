#include <iostream>
#define N 100005
using namespace std;
long long n, s, t, L[4] = {0}, C[4] = {0}, a[N], ga[4], minn[N];
void chiPhiNhoNhat(long long s, long long t){
    for( int i = s+1; i <= t; i++){
        minn[i] = 99999999;
        for( int j = 3; j >= 1; j--){
            while( a[i] - a[ga[j]] > L[j] ){
                ga[j]++;
            }
            for( int k = 1; k <= j; k++){
                if( a[i] - a[ga[j]] <= L[k] ){
                    minn[i] = min(minn[i], minn[ga[j]]+ C[j]);
                    break;
                }
            }
            ga[j-1] = ga[j];
        }
    }
    cout << minn[t];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for( int i = 1; i <= 3; i++){
        cin >> L[i];
    }
    for( int i = 1; i <= 3; i++){
        cin >> C[i];
    }
    cin >> n;
    cin >> s >> t;
    for( int i = 1; i <= 3; i++){
        ga[i] = min(s,t);
    }
    for( int i = 2; i <= n; i++){
        cin >> a[i];
    }
    chiPhiNhoNhat(min(s,t), max(s,t));
    return 0;
}
