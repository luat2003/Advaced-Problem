#include <iostream>
#define N 301
long long A[N][N], B[N][N], D[N], E[N] = {0}, miE[N] = {0}, csmin[N] = {0}; // khai báo các mảng A nhập, B mảng cộng dồn từng hàng ( hàng i từ vt 1 đến vt j)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long T, i;
    cin >> T; // Nhập vào số Test case
    long long R, C, L; // row, column, lend la số hàng, số cột, số tiền mỗi ô đất cho mỗi test case
    for( int i = 0; i < T; i++){
        cin >> R >> C >> L;
        long long ma = 0, countt = 999999999999; // ma sẽ là tổng lợi nhuận lớn nhất, countt sẽ là số tiền bỏ ra nhỏ nhất với lợi nhuận ma
        B[0][0] = 0;
        for( int j = 1; j <= R; j++){
            B[j][0] = 0;
            for( int k = 1; k <= C; k++){
                cin >> A[j][k]; // nhập vào lợi nhuận sau tính toán  5 năm
                A[j][k] -= L; // Trừ đi giá tiền mỗi ô
                B[j][k] = B[j][k-1]+A[j][k]; // Cộng dồn B[j][k] là tổng các số trên hàng j từ vị trí 1 đến vị trí k
            }
        }
        for( int j = 1; j <= C; j++){
            for( int k = j; k <= C; k++){
                E[0] = 0, miE[0] = 0, csmin[0] = 0;
                for( int u = 1; u <= R; u++){
                    D[u] = B[u][k] - B[u][j-1]; // D[u] là tổng các số trên hàng u từ vị trí j đến vị trí k
                    E[u] = E[u-1] + D[u]; // E[u] là mảng cộng dồn của D[u] từ 1 đến u;
                    if( miE[u-1] < E[u-1]){
                        csmin[u] = csmin[u-1]; // nếu min (E[1],E[2],...,E[u-2]) < E[u-1] thì chỉ số min sẽ bằng csmin[u-1]
                    }else{
                        csmin[u] = u-1; // còn nếu min (E[1],E[2],...,E[u-2]) < E[u-1] thì chỉ số min sẽ là u-1
                    }
                    miE[u] = min( miE[u-1], E[u-1]); // miE[u] là min E[1],E[2],...,E[u-1]

                    if( ma == E[u] - miE[u]){
                        countt = min(countt, (u-csmin[u])*(k-j+1)*L ); // nếu profit ko đổi thì sẽ lấy cost phải trả nhỏ hơn
                    }else if( ma < E[u] - miE[u] ){
                        countt = (u-csmin[u])*(k-j+1)*L; // nếu profit tăng thì sẽ lấy cost mới bằng số tiền phải trả của cost đó
                    }
                    ma = max( ma, E[u] - miE[u]); // tìm profit lớn nhất trong các tổng hcn con lớn nhất.
                }
            }
        }
        if( countt == 999999999999){
            countt = 0;
        }
        cout << "#" << i+1 << " " << ma << " " << countt << endl;
    }
    return 0;
}
