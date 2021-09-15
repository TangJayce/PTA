/**
 * Created by Jayce on 2021/6/29.
 * 题目：04-树6 Complete Binary Search Tree (30 分)
 * 知识点：树
 */
#include <bits/stdc++.h>

using namespace std;
#define for_(i, a, b) for(int i=(a);i<(b);++i)
#define rep_(i, a, b) for(int i=(a);i<=(b);++i)
#define endl '\n'
typedef long long ll;
const int maxn = 1e3 + 5, inf = 0x3f3f3f3f, mod = 1e9 + 7;

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

int nums[maxn], flag = 0, ans[maxn * 4];
int h[15] = {0, 1, 3, 7, 15, 31, 63, 127, 255, 511, 1023};
void solve(int k, int l, int r) {
    if(l > r) return;
    int cnt = r - l + 1;
    int index = lower_bound(h, h + 11, cnt) - h;
    int mid = (h[index-1] - 1) / 2 + min((1 << (index - 1)) / 2, cnt - h[index-1]) + l;
    ans[k] = nums[mid];
    solve(k * 2, l, mid - 1);
    solve(k * 2 + 1, mid + 1, r);
}

int main() {
    int n = read();
    for_(i, 0, n) nums[i] = read();
    sort(nums, nums + n);
    solve(1, 0, n - 1);
    for_(i, 1, n) cout << ans[i] << ' ';
    cout << ans[n];
    return 0;
}