#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    long long i, a[n+1], s[n+1], mic[n+1], ma = -999999, sc[n+1], sl[n+1], j = 1, k =1, mil[n+1];
    s[0] = 0, a[0] = 0, mic[0] = 999999, mil[0] = 999999;
    for( i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i-1] + a[i];
        if( s[i] % 2 == 0){
            sc[j] = s[i];
            mic[j] = min(sc[j-1],mic[j-1]);
            ma = max( ma, sc[j] - mic[j]);
            j++;
        }else{
            sl[k] = s[i];
            mil[k] = min(sl[k-1],mil[k-1]);
            ma = max( ma, sl[k] - mil[k]);
            k++;
        }
    }

    if( ma == -999999){
        cout << "NOT_FOUND";
    }
    cout << ma;

    return 0;
}
