/**
 * Created by Jayce on 2021/5/17.
 * 题目：02-线性结构2 一元多项式的乘法与加法运算
 * 知识点：链表
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node{
    ElementType num, index;
    struct Node *next;
}Node, *poly;

Node* CreateNode(ElementType c, ElementType e) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->num = c;
    p->index = e;
    return p;
}

poly ReadPoly() {
    int len, c, e;
    scanf("%d", &len);
    poly root = (poly)malloc(sizeof(Node));
    Node* rear = root;
    while (len--) {
        scanf("%d%d", &c, &e);
        Node* p = CreateNode(c, e);
        rear->next = p;
        rear = p;
    }
    rear->next = NULL;
    Node* tmp = root;
    root = root->next;
    free(tmp);
    return root;
}

void PrintPoly(poly p) {
    if(!p) {
        printf("0 0\n");
        return;
    }
    while (p) {
        if(p->next)
            printf("%d %d ", p->num, p->index);
        else
            printf("%d %d", p->num, p->index);
        p = p->next;
    }
    printf("\n");
}

poly Mul(poly p1, poly p2) {
    if(!p1 || !p2) return NULL;
    poly t1 = p1, t2 = p2;
    poly root = (poly)malloc(sizeof(Node));
    root->next = NULL;
    Node* rear = root;
    while (t2) {
        rear->next = CreateNode(t1->num * t2->num, t1->index + t2->index);
        rear = rear->next;
        t2 = t2->next;
    }
    rear->next = NULL;
    t1 = t1->next;
    ElementType c, e;
    while (t1) {
        t2 = p2;
        rear = root;
        while (t2) {
            c = t1->num * t2->num;
            e = t1->index + t2->index;
            while (rear->next && rear->next->index > e) rear = rear->next;
            if(rear->next && rear->next->index == e) {
                if(rear->next->num + c == 0) {
                    Node* tmp = rear->next;
                    rear->next = tmp->next;
                    free(tmp);
                }
                else
                    rear->next->num += c;
            }
            else {
                Node* p = CreateNode(c, e);
                p->next = rear->next;
                rear->next = p;
                rear = rear->next;
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    Node* tmp = root;
    root = root->next;
    free(tmp);
    return root;
}

poly Add(poly p1, poly p2) {
    poly root = (poly)malloc(sizeof(Node));
    Node* rear = root;
    while (p1 && p2) {
        Node* p;
        if(p1->index == p2->index) {
            p = CreateNode(p1->num + p2->num, p1->index);
            p1 = p1->next;
            p2 = p2->next;
        } else if(p1->index > p2->index) {
            p = CreateNode(p1->num, p1->index);
            p1 = p1->next;
        } else {
            p = CreateNode(p2->num, p2->index);
            p2 = p2->next;
        }
        if(p->num == 0) {
            free(p);
            continue;
        }
        rear->next = p;
        rear = p;
    }
    while (p1) rear->next = CreateNode(p1->num, p1->index), rear = rear->next, p1 = p1->next;
    while (p2) rear->next = CreateNode(p2->num, p2->index), rear = rear->next, p2 = p2->next;
    rear->next = NULL;
    Node* tmp = root;
    root = root->next;
    free(tmp);
    return root;
}

int main() {
    poly p1, p2, pp, ps;
    p1 = ReadPoly();
    p2 = ReadPoly();
    pp = Mul(p1, p2);
    PrintPoly(pp);
    ps = Add(p1, p2);
    PrintPoly(ps);
    return 0;
}