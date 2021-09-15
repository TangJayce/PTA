/**
 * Created by Jayce on 2021/6/29.
 * 题目：05-树7	堆中的路径
 * 知识点：堆
 */
#include <bits/stdc++.h>

using namespace std;
#define for_(i, a, b) for(int i=(a);i<(b);++i)
#define rep_(i, a, b) for(int i=(a);i<=(b);++i)
#define endl '\n'
typedef long long ll;
const int maxn = 1e3 + 50, inf = 0x3f3f3f3f, mod = 1e9 + 7;

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

int heap[maxn], k = 1;
void insert(int x) {
    int i = k++;
    for (; x < heap[i / 2] ; i >>= 1)
        heap[i] = heap[i / 2];
    heap[i] = x;
}

void print(int x) {
    cout << heap[x];
    for (x >>= 1; x; x >>= 1)
        cout << ' ' << heap[x];
}

int main() {
    int n = read(), m = read(), tmp;
    heap[0] = -inf;
    for_(i, 0, n) {
        tmp = read();
        insert(tmp);
    }
    for_(i, 0, m) {
        tmp = read();
        if(i) cout << '\n';
        print(tmp);
    }
    return 0;
}