/**
 * Created by Jayce on 2021/5/18.
 * 题目：02-线性结构3 Reversing Linked List
 * 知识点：链表
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node *List;
struct Node {
    int add_cur, value, add_next;
    List next;
};

int data[100005], address[100005], add_begin, next, k;

List ReadList() {
    List root = (List)malloc(sizeof(List));
    root->next = NULL;
    List rear = root;
    scanf("%d%d%d", &add_begin, &next, &k);
    int a, b, c;
    for (int i = 0; i < next; i++) {
        scanf("%d%d%d", &a, &b, &c);
        data[a] = b;
        address[a] = c;
    }
    next = 0;
    for (int index = add_begin; ~index; index = address[index]) {
        next++;
        List p = (List)malloc(sizeof(struct Node));
        p->value = data[index];
        p->add_cur = index;
        p->add_next = address[index];
        p->next = NULL;
        rear->next = p;
        rear = rear->next;
    }
    return root;
}

void PrintList(List L) {
    if(!L->next) return;
    L = L->next;
    while (L) {
        if(~L->add_next)
            printf("%05d %d %05d\n", L->add_cur, L->value, L->add_next);
        else
            printf("%05d %d -1\n", L->add_cur, L->value);
        L = L->next;
    }
}

List ReverseList(List L, int len) {
    if(len == 1) return L->next;
    List cur = L->next, re = NULL, prev = L->next;
    while (len--) {
        List tmp = cur->next;
        cur->next = re;
        re = cur;
        cur = tmp;
    }
    prev->next = cur;
    L->next = re;
    return prev;
}

int main() {
    List root = ReadList();
    List rear = root;
    for (int i = 0; i < next / k; i++) {
        rear = ReverseList(rear, k);
    }
    rear = root->next;
    while (rear) {
        if(rear->next)
            rear->add_next = rear->next->add_cur;
        else
            rear->add_next = -1;
        rear = rear->next;
    }
    PrintList(root);
    return 0;
}