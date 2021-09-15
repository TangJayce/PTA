/**
 * Created by Jayce on 2021/8/6.
 * 题目：11-散列2 Hashing (25 分)
 * 知识点：正向平方探测法散列
 */
#include <bits/stdc++.h>

using namespace std;
#define for_(i, a, b) for(int i=(a);i<(b);++i)
#define rep_(i, a, b) for(int i=(a);i<=(b);++i)
#define endl '\n'
typedef long long ll;
const int maxn = 1e4 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

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
bool is_prime(int x) {
    if(x < 2) return false;
    for (int i = 2; i <= x / i; i++)
        if(x % i == 0) return false;
    return true;
}
int table[maxn], size, n;
int insert(int key) {
    for (int step = 0; step < size; step++) {
        int index = (key + step * step) % size;
        if(table[index] == -1) {
            table[index] = key;
            return index;
        }
    }
    return -1;
}
int main() {
    size = read(), n = read();
    while (!is_prime(size)) size++;
    memset(table, -1, sizeof(table));
    while (n--) {
        int num = read();
        int ans = insert(num % size);
        if(~ans) cout << ans;
        else putchar('-');
        if(n) putchar(' ');
    }
    return 0;
}