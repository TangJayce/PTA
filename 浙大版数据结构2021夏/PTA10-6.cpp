/**
 * Created by Jayce on 2021/8/6.
 * 题目：10-排序6 Sort with Swap(0, i) (25 分)
 * 知识点：简单模拟
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
int nums[maxn];
bool vis[maxn];
int solve(int x) {
    int index = x, cnt = 0;
    do {
        vis[index] = true;
        cnt++;
        index = nums[index];
    } while (index != x);
    return cnt;
}
int main() {
    int n = read(), ans = 0;
    for_(i, 0, n) nums[i] = read();
    ans += solve(0) - 1;
    for_(i, 1, n) {
        if(!vis[i] && nums[i] != i)
            ans += solve(i) + 1;
    }
    cout << ans;
    return 0;
}
/*
浙大数据结构的说法：若N个元素的序列中包含S个单元环、K个多元环，则交换次数为：N-S+K-2
上述内容存在错误，应为：
 若N个元素的序列中包含S个非零单元环以及剩下K个环，则交换次数为：N-S+K-2
 */