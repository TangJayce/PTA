/**
 * Created by Jayce on 2021/6/28.
 * 题目：04-树4 是否同一棵二叉搜索树 (25 分)
 * 知识点：
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

int tree[15], nums[15], n, l;

bool check(int left, int right) {
    if (left >= right) return true;
    int num = 0, f = 0;
    for_(i, 0, n)
        if(left <= tree[i] && tree[i] <= right) {
            num = tree[i];
            break;
        }
    for_(i, 0, n)
        if(left <= nums[i] && nums[i] <= right) {
            f = nums[i];
            break;
        }
    if(num != f) return false;
    return check(left, num - 1) && check(num + 1, right);
}

int main() {
    n = read();
    while (n) {
        l = read();
        for_(i, 0, n) tree[i] = read();
        while (l--) {
            for_(i, 0, n) nums[i] = read();
            if(check(1, n))
                puts("Yes");
            else
                puts("No");
        }
        n = read();
    }
    return 0;
}