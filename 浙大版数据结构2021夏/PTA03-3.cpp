/**
 * Created by Jayce on 2021/6/29.
 * 题目：03-树3 Tree Traversals Again (25 分)
 * 知识点：树
 */
#include <bits/stdc++.h>

using namespace std;
#define for_(i, a, b) for(int i=(a);i<(b);++i)
#define rep_(i, a, b) for(int i=(a);i<=(b);++i)

static const auto io_sync_off = []() {
    // 关闭同步
    ios::sync_with_stdio(false);
    // 关闭cin和cout流的绑定
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

struct BTree {
    int data;
    BTree *left, *right, *parent;
    BTree(int n) : data(n), left(nullptr), right(nullptr), parent(nullptr) {}
};
int f = 0;
void postorder(BTree *root) {
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    if (!f) cout << root->data, f = 1;
    else cout << ' ' << root->data;
}

int main() {
    int n, num, flag = 0;
    string s;
    cin >> n;
    n <<= 1;
    cin >> s >> num;
    BTree *root = new BTree(num);
    BTree *tmp = root;
    while (--n) {
        cin >> s;
        if(s[1] == 'u') {
            cin >> num;
            if(!flag) {
                tmp->left = new BTree(num);
                tmp->left->parent = tmp;
                tmp = tmp->left;
            }
            else {
                tmp->right = new BTree(num);
                tmp->right->parent = tmp;
                tmp = tmp->right;
                flag = 0;
            }
        } else {
            if(!flag) flag = 1;
            else {
                do tmp = tmp->parent; while (tmp->right);
                flag = 1;
            }
        }
    }
    postorder(root);
    return 0;
}