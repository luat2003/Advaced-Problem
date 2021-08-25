#include <iostream>

using namespace std;
int x[100];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, i;
    cin >> n >> m;
    for( i = 1; i <= m; i++){
        x[i] = i; // Bộ m số đầu tiên luôn là 1, 2, ..., m
    }
    while( i > 0 ){
        for( int j = 1; j <= m; j++){
            cout << x[j] << " "; // in ra một cách chọn
        }
        cout << "\n";
        i = m;
        while( i > 0 && x[i] == n-m+i){ // số được chọn ở vị trí i sẽ ko vượt quá n-m+i
            i--; // Nếu x[i] đã đạt max thì giảm i
        }
        if( i > 0 ){
            x[i]++; // số cuối cùng chưa đạt giới hạn thì ++
            for( int j = i+1; j <= m; j++){
                x[j] = x[j-1]+1; // Các số từ vị trí tăng sẽ lần lượt hơn số trước đó 1
            }
        }
    }
    return 0;
}
