/**
 * Created by Jayce on 2021/8/5.
 * 题目：09-排序2 Insert or Merge (25 分)
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

int n, nums[maxn], ck[maxn], cy[maxn];
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
bool check(int len) {
    int index = len;
    len <<= 1;
    for (; index < n; index += len)
        if(ck[index] < ck[index - 1])
            return false;
    return true;
}
int solve() {
    int l;
    for (l = 2; l <= n; l <<= 1)
        if(!check(l)) break;
    return l;
}
void _merge(int l, int mid, int r) {
    int p1 = l, p2 = mid + 1;
    for (int i = l; i <= r; ++i) {
        if((p1 <= mid) && ((p2 > r) || (ck[p1] <= ck[p2]))) {
            cy[i] = ck[p1];
            p1++;
        } else {
            cy[i] = ck[p2];
            p2++;
        }
    }
    for (int i = l; i <= r; ++i) {
        ck[i] = cy[i];
    }
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
        puts("Merge Sort");
        ans = solve();
        int i;
        for (i = 0; i + (ans << 1) < n; i += ans << 1)
            _merge(i, i + ans - 1, i + (ans << 1) - 1);
        if(i + ans < n) _merge(i, i + ans - 1, n - 1);
        for (i = 0; i < n - 1; i++) cout << ck[i] << ' ';
        cout << ck[n - 1];
    }
    return 0;
}