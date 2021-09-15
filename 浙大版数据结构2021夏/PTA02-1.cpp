/**
 * Created by Jayce on 2021/5/17.
 * 题目：02-线性结构1 两个有序链表序列的合并
 * 知识点：链表
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read() {
    int len;
    scanf("%d", &len);
    List root = (List)malloc(sizeof(List));
    root->Next = NULL;
    List rear = root;
    while (len--) {
        List p = (List)malloc(sizeof(List));
        scanf("%d", &p->Data);
        p->Next = NULL;
        rear->Next = p;
        rear = rear->Next;
    }
    return root;
}

void Print( List L ) {
    if(!L || !L->Next) printf("NULL");
    while (L->Next) {
        printf("%d ", L->Next->Data);
        L = L->Next;
    }
    printf("\n");
}

List Merge(List L1, List L2) {
    PtrToNode t1 = L1->Next, t2 = L2->Next;
    List L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    PtrToNode rear = L;
    while (t1 && t2) {
        if(t1->Data < t2->Data) {
            rear->Next = t1;
            t1 = t1->Next;
        } else {
            rear->Next = t2;
            t2 = t2->Next;
        }
        rear = rear->Next;
    }
    if(t1) rear->Next = t1;
    if(t2) rear->Next = t2;
    L1->Next = NULL;
    L2->Next = NULL;
    return L;
}

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

