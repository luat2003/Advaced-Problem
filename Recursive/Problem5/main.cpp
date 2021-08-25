#include <iostream>
#define N 400

using namespace std;
int a[21][21] = {0}, x[N], y[N], c[N], cost = 99999999, n, m, kt[21] = {0}, minn = 99999999;

void hanhTrinh( int n, int e, int k, int d){// e là vị trí hiện tại, k là làng đã đi
    if( k == n+1 ){ // đã đi qua n+1 làng ( làng 1 tính 2 lần)
        if( a[e][1] != 0){
            d += a[e][1];
            cost = min(cost, d);// tìm giá trị tối thiểu cho một hành trình đầy đủ
        }
    }else{
        for( int i = 2; i <= n; i++){
            if( kt[i] == 0 && a[e][i] != 0 && (minn*(n-k)+a[e][i]+d) < cost){ // Nếu làng i chưa đi và có đường từ vt hiện tại đến i và giá chưa vượt qua giá trị min thì đi tiếp
                kt[i] = 1;
                hanhTrinh(n, i, k+1, d + a[e][i]); // đệ quy đến vt mơi sau khi đã đi đến i.
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
    cin >> n >> m;
    for( int i = 0; i < m; i++){
        cin >> x[i] >> y[i] >> c[i];
        a[x[i]][y[i]] = c[i];
        minn = min( minn, c[i]);
    }
    hanhTrinh(n,1,2,0);
    cout << cost;
    return 0;
}
