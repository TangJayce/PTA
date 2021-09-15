/**
 * Created by Jayce on 2021/8/5.
 * 题目：09-排序3 Insertion or Heap Sort (25 分)
 * 知识点：模拟
 */
#include <bits/stdc++.h>

using namespace std;
#define for_(i, a, b) for(int i=(a);i<(b);++i)
#define rep_(i, a, b) for(int i=(a);i<=(b);++i)
#define endl '\n'
typedef long long ll;
const int maxn = 1e2 + 5, inf = 0x3f3f3f3f, mod = 1e9 + 7;

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

int n, nums[maxn], ck[maxn];
int is_insert() {
    int index;
    for (index = 1; index < n; index++)
        if(ck[index] < ck[index - 1])
            break;
    for (int i = index; i < n; i++)
        if(nums[i] != ck[i])
            return -1;
    return index;
}

int heap[maxn], sz;
void down(int x) {
    int t = x;
    if(x << 1 <= sz && heap[x << 1] > heap[t]) t = x << 1;
    if((x << 1) + 1 <= sz && heap[(x << 1) + 1] > heap[t]) t = (x << 1) + 1;
    if(t != x) swap(heap[t], heap[x]), down(t);
}
void pop() {
    swap(heap[1], heap[sz--]);
    down(1);
}

int main() {
    n = read();
    for_(i, 0, n) nums[i] = read();
    for_(i, 0, n) ck[i] = read();
    int ans = is_insert();
    if(~ans) {
        puts("Insertion Sort");
        int tmp = ck[ans], i;
        for (i = ans - 1; ~i; i--) {
            if(ck[i] > tmp) ck[i + 1] = ck[i];
            else break;
        }
        ck[i + 1] = tmp;
        for (i = 0; i < n - 1; i++) cout << ck[i] << ' ';
        cout << ck[n - 1];
    } else {
        puts("Heap Sort");
        for_(i, 0, n) heap[i + 1] = ck[i];
        sz = n;
        while (heap[1] < heap[sz]) sz--;
        pop();
        for_(i, 1, n) cout << heap[i] << ' ';
        cout << heap[n];
    }
    return 0;
}