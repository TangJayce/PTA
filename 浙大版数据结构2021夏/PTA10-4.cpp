/**
 * Created by Jayce on 2021/7/22.
 * 题目：10-排序4 统计工龄 (20 分)
 * 知识点：桶排序
 */
#include <bits/stdc++.h>

using namespace std;
#define for_(i, a, b) for(int i=(a);i<(b);++i)
#define rep_(i, a, b) for(int i=(a);i<=(b);++i)
#define endl '\n'
typedef long long ll;
const int maxn = 1e5 + 5, inf = 0x3f3f3f3f, mod = 1e9 + 7;

inline int read() {
    char ch = getchar();
    int f = 1, x = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f * x;
}

int cnt[55];
int main() {
    int n = read();
    while (n--) {
        int num = read();
        cnt[num]++;
    }
    rep_(i, 0, 50) if(cnt[i]) printf("%d:%d\n", i, cnt[i]);
    return 0;
}