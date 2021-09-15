/**
 * Created by Jayce on 2021/7/4.
 * 题目：05-树9 Huffman Codes (30 分)
 * 知识点：哈夫曼编码的正确性判断
 */
#include <bits/stdc++.h>
using namespace std;
#define for_(i, a, b) for(int i=(a);i<(b);++i)
#define rep_(i, a, b) for(int i=(a);i<=(b);++i)

int f[128];

bool check(vector<string> &arr) {
    sort(arr.begin(), arr.end(), [](string &a, string &b){return a.size() < b.size();});
    int len, n = arr.size();
    string str;
    for_(i, 0, n) {
        len = arr[i].length();
        for_(j, i + 1, n) {
            str = arr[j].substr(0, len);
            if(str == arr[i]) return false;
        }
    }
    return true;
}

int main() {
    priority_queue<int,vector<int>,greater<int> > q;
    vector<string> arr;
    string code;
    char c;
    int n, m, num, a, b, ans = 0;
    cin >> n;
    for_(i, 0, n) {
        cin >> c >> num;
        f[int(c)] = num;
        q.push(num);
    }
    while (q.size() >= 2) {
        a = q.top(); q.pop();
        b = q.top(); q.pop();
        q.push(a + b);
        ans += a + b;
    }
    cin >> m;
    while (m--) {
        num = 0;
        arr.clear();
        for_(i, 0, n) {
            cin >> c >> code;
            arr.push_back(code);
            num += f[int(c)] * code.length();
        }
        if(num == ans && check(arr)) printf("Yes");
        else printf("No");
        if(m) printf("\n");
    }
    return 0;
}