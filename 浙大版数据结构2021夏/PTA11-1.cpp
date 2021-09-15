/**
 * Created by Jayce on 2021/7/22.
 * 题目：7-14 电话聊天狂人 (25 分)
 * 知识点：散列
 */
#include <bits/stdc++.h>

using namespace std;
#define for_(i, a, b) for(int i=(a);i<(b);++i)
#define rep_(i, a, b) for(int i=(a);i<=(b);++i)
#define endl '\n'
typedef long long ll;
const int maxn = 1e5 + 5, inf = 0x3f3f3f3f, mod = 1e9 + 7;

inline long long read() {
    char ch = getchar();
    long long f = 1, x = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
    return f * x;
}

map<ll, int> m;
int cnt;

int main() {
    int ans = 0, n = read();
    n <<= 1;
    while (n--) {
        ll a = read();
        m[a]++;
        if(m[a] > ans) {
            ans = m[a];
            cnt = 0;
        }
        if(m[a] == ans) cnt++;
    }
    for(auto item : m) {
        if(ans == item.second) {
            cout << item.first << ' ' << ans;
            if (cnt > 1) cout << ' ' << cnt;
            break;
        }
    }
    return 0;
}