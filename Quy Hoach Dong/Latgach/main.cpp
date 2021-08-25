#include <iostream>
#include <string.h>
using namespace std;
int stringToNum(char c)
{
    return c - '0';
}

char numToString(int n)
{
    return (char)(n+48);
}

void chuanHoa(string &a, string &b)
{
    int l1 = a.length(), l2 = b.length();
    if (l1 >= l2)
    {
        b.insert(0, l1-l2, '0');
    }
    else
    {
        a.insert(0, l2-l1, '0');
    }
}

string sum(string a, string b)
{
    string s = "";
    chuanHoa(a,b);
    int l = a.length();

    int temp = 0;
    for (int i=l-1; i>=0; i--)
    {
        temp = stringToNum(a[i]) + stringToNum(b[i]) + temp;
        s.insert(0,1,numToString(temp%10));
        temp = temp/10;
    }
    if (temp>0)
    {
        s.insert(0,1,numToString(temp));
    }
    return s;
}

int t, n;
string dp[105];
void soCachLat(){
    dp[1] = "1", dp[2] = "2";
    for( int i = 3; i <= 100; i++){
        dp[i] = sum(dp[i-1], dp[i-2]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    soCachLat();
    for( int i = 1; i <= t; i++){
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}
