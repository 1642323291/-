#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
struct DBLNode {
	ElemType data;
	DBLNode* prior, * next;
};
//头插法
void CreateDBL(DBLNode*& L, ElemType a[], int n) {
	L = new DBLNode;
	L->prior = L->next = NULL;
	for (int i = 0; i < n; i++) {
		DBLNode* s = new DBLNode;
		s->data = a[i];
		s->next = L->next;
		if (L->next != NULL)
			L->next->prior = s;
		s->prior = L;
		L->next = s;
	}
}
//输出链表
void print(DBLNode* L) {
	DBLNode* p = L;
	while (p->next) {
		p = p->next;
		printf("%d ", p->data);
	}
	printf("\n");
}
int main() {
	ElemType a[] = { 1,2,3,4,5,6,7,8,9 };
	DBLNode* h;
	CreateDBL(h, a, 9);
	print(h);
    system("pause");
}

