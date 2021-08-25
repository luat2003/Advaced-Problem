#include <iostream>

using namespace std;

int xung_dot[35][35] = {0}, a[35][35], m, n, k, soLop[15] = {0}, minn = 99999999, x[35];

void chiaLop( int Lop, int n){
if( Lop > n ){
int maxx = 0;
for( int j = 1; j <= m; j++){
    maxx = max(maxx, soLop[j]);// Tìm giáo viên dạy nhiều lớp nhất
}
minn = min(minn, maxx); // Tìm min trong các lần xét
}else{
for( int i = 1; i <= m; i++){
    int kt = 0;
    if( a[i][Lop] ){ // Nếu gv i có thể dạy Lop thì bắt đầu kiêm tra
        for( int v = 1; v < Lop; v++){
            if( xung_dot[v][Lop] && x[v] == i){ // kiểm tra các lớp xung đột nhỏ hơn Lop
            // Nếu lớp xung đột này đã được giáo viên i dạy thì thoát ra
                kt = 1;
                break;
            }
        }
        if( kt == 1 ){
            continue; // do gv i đã dạy một lớp nhỏ hơn và xung đột với lớp Lop nên sẽ ko dạy lớp i nữa
        }else{
            x[Lop] = i; // Nếu gv i chưa dạy lớp nào xung đột với Lop thì cho i dạy Lop
            soLop[i]++; // khi đó gv i sẽ thêm 1 lớp dạy
            if(soLop[i] < minn){ // nếu mà số lớp dạy của i vẫn nhỏ hơn minn
                chiaLop(Lop + 1, n); // thì chay lớp + 1  kế tiếp
                soLop[i]--; // Sau khi chạy hết một vòng thì reset lại số lớp mà gv i dạy
            }else{
                soLop[i]--; // Nếu số lớp mà gv[i] dạy đã >= minn thì sẽ ko cho gv i dạy lớp này và tiếp tục
            }
        }
    }
}
}
}

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> m >> n; // Nhập vào m là số gv, n là số lớp
for( int i = 1; i <= m; i++){
int soClass;
cin >> soClass; // nhập vào số lớp mà gv i có thể dạy
for( int j = 1; j <= soClass; j++){
    int Class;
    cin >> Class;
    a[i][Class] = 1; // gv i có thể dạy lớp Class
}
}
cin >> k; // Nhập vào số cặp lớp xung đột
for( int i = 1; i <= k; i++){
int x, y;
cin >> x >> y;
xung_dot[x][y] = 1;
xung_dot[y][x] = 1;
}
chiaLop(1, n);
cout << minn;
return 0;
}
