#include <bits/stdc++.h>
#define M 99999999
#define N 20
using namespace std;
int n, K, Q, d[N], c[N][N], minn = M, kt[N] = {0}, Min = M;

void tongNhoNhat( int vitri, int xe, int trongTai, int quangDuong, int soKH){
    if( xe == K+1 && soKH == n){
        minn = min( minn, quangDuong + c[vitri][0]);
    }else{
        for( int i = 1; i <= n; i++){
            if( kt[i] == 0 ){
                if( trongTai + d[i] > Q ){
                    tongNhoNhat(0, xe+1, 0, quangDuong + c[vitri][0], soKH);
                    continue;
                }
                if( trongTai == 0 && ((quangDuong + c[vitri][i] + Min*(K-xe+n-soKH)) < minn) && (K-xe) <= (n-soKH-1) ){
                    kt[i] = 1;
                    tongNhoNhat( i, xe, trongTai + d[i], quangDuong + c[vitri][i], soKH + 1);
                    kt[i] = 0;
                    continue;
                }
                kt[i] = 1;
                if( (quangDuong + c[vitri][i] + Min*(K-xe+n-soKH) ) < minn && (K-xe) <= (n-soKH-1) ){
                    tongNhoNhat( i, xe, trongTai + d[i], quangDuong + c[vitri][i], soKH + 1);
                    tongNhoNhat( i, xe+1, trongTai + d[i], quangDuong + c[vitri][i], soKH + 1);
                }
                kt[i] = 0;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> K >> Q;
    for( int i = 1; i <= n; i++){
        cin >> d[i];
    }
    for( int i = 0; i <= n; i++){
        for( int j = 0; j <= n; j++){
            cin >> c[i][j];
            if( c[i][j] > 0 ){
                Min = min(Min, c[i][j]);
            }
        }
    }
    tongNhoNhat(0, 1, 0 ,0, 0);
    cout << minn;
    return 0;
}
