/**
 * Created by Jayce on 2021/6/29.
 * 题目：04-树5 Root of AVL Tree (25 分)
 * 知识点：AVL
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
struct AVLTree {
    int data, height;
    AVLTree *left, *right;
    AVLTree(int x, int h):data(x), height(h), left(nullptr), right(nullptr){}
};

int GetHeight(AVLTree* root) {
    if(!root) return 0;
    return root->height;
}

AVLTree* LL(AVLTree* root) {
    AVLTree* tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    root->height = max(GetHeight(root->left), GetHeight(root->right)) + 1;
    tmp->height = max(GetHeight(tmp->left), root->height) + 1;
    return tmp;
}
AVLTree* RR(AVLTree* root) {
    AVLTree* tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    root->height = max(GetHeight(root->left), GetHeight(root->right)) + 1;
    tmp->height = max(GetHeight(root->right), root->height) + 1;
    return tmp;
}
AVLTree* LR(AVLTree* root) {
    root->left = RR(root->left);
    return LL(root);
}
AVLTree* RL(AVLTree* root) {
    root->right = LL(root->right);
    return RR(root);
}

AVLTree* Insert(AVLTree* root, int x) {
    if(!root) root = new AVLTree(x, 0);
    else if(x < root->data) {
        root->left = Insert(root->left, x);
        if(GetHeight(root->left) - GetHeight(root->right) == 2)
            root = x < root->left->data ? LL(root) : LR(root);
    } else if(x > root->data) {
        root->right = Insert(root->right, x);
        if(GetHeight(root->right) - GetHeight(root->left) == 2)
            root = x < root->right->data ? RL(root) : RR(root);
    }
    root->height = max(GetHeight(root->left), GetHeight(root->right)) + 1;
    return root;
}
int main() {
    int n, num;
    cin >> n;
    AVLTree *root = nullptr;
    for_(i, 0, n) {
        cin >> num;
        root = Insert(root, num);
    }
    cout << root->data;
    return 0;
}