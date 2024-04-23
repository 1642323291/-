#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
typedef int ElemType;
struct Node {
	ElemType data;
	Node* next;
};
//建立单链表：头插法
void CreateL(Node*& L, ElemType a[], int n) {
	Node* s;
	L = new Node;
	L->next = NULL;
	for (int i = 0; i < n; i++) {
		s = new Node;
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}
//建立单链表：尾插法
void CreateR(Node*& L, ElemType a[], int n) {
	Node* s, * r;
	L = new Node;
	L->next = NULL;
	r = L;
	for (int i = 0; i < n; i++) {
		s = new Node;
		s->data = a[i];
		s->next = NULL;
		r->next = s;
		r = s;
	}
}
//查找：根据位置查找
Node* GetElem(Node* L, int i) {
	int cnt = 0;
	Node* p = L;
	while (p->next) {
		p = p->next;
		cnt++;
		if (cnt == i) return p;
	}
	return L;
}
//计算节点个数
int GetLength(Node* L) {
	int cnt = 0;
	Node* p = L;
	while (p->next) {
		p = p->next;
		cnt++;
	}
	return cnt;
}
//插入一个新节点
bool InsertList(Node*& L, int i, ElemType e) {
	if (i<1 || i>GetLength(L) + 1)return 0;
	Node* s = new Node;
	s->data = e;
	Node* p = GetElem(L, i - 1);
	s->next = p->next;
	p->next = s;
	return 1;
}
//删除一个节点
bool DeleteList(Node*& L, int i, ElemType& e) {
	if (i<1 || i>GetLength(L))return 0;
	Node* p = GetElem(L, i - 1), * q;
	if (p || p->next) {
		e = p->next->data;
		q = p->next;//删除q 
		p->next = p->next->next;
		free(q);
		return 1;
	}
	else {
		return 0;
	}
}

//输出单链表
void print(Node* L) {
	Node* p = L->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
//将单链表L中的元素逆置
void Reverse(Node*& L) {
	//讲表头与数据分离
	Node* p = L->next, * q;
	L->next = NULL;
	//采用头插法，将数据节点逐个插入L中
	while (p) {
		q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;
	}
}
void split(Node*& L, Node*& L1, Node*& L2) {
	//设置头结点
	L1 = L;//使用尾插法
	Node* r = L1;
	L2 = new Node;//使用头插法 
	L2->next = NULL;
	Node* p = L->next, * q;
	//设置数据部分 
	while (p) {
		//尾插法建立L1
		r->next = p;
		r = p;
		//头插法建立L2
		p = p->next;
		if (p) {
			q = p->next;
			p->next = L2->next;
			L2->next = p;
			//恢复
			p = q;
		}
	}
	r->next = NULL;
}


int main() {
	int a[] = { 1,2,3,4,5,6,7,8,9 };
	int n = sizeof(a) / sizeof(int);
	Node* L;
	CreateR(L, a, n);
	print(L);
	//	Reverse(L);
	//	print(L); 
	Node* L1, * L2;
	split(L, L1, L2);
	print(L1);
	print(L2);
    system("pause");
}