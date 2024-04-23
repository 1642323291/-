#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
typedef int ElemType;
struct Node{
	ElemType data;
	int k;
	Node *next;
};

//建立循环单链表：头插法
void CreateL(Node *&L,ElemType a[],int n){
	Node *s;
	L = new Node;
	L->next = L;
	for(int i=0;i<n;i++){
		s = new Node;
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
} 
//建立循环单链表：尾插法
void CreateR(Node *&L,ElemType a[],int n){
	Node *s,*r;
	L = new Node;
	L->next = L;
	r = L;
	for(int i=0;i<n;i++){
		s = new Node;
		s->data = a[i];
		s->next = L;
		r->next = s;
		r = s;
	}
} 
//查找：根据位置查找
Node * GetElem(Node *L,int i){
	int cnt=0;
	Node *p=L;
	while(p->next){		
		p=p->next;
		cnt++;
		if(cnt==i) return p;		
	}
	return NULL;
} 
//计算节点个数
int GetLength(Node *L){
	int cnt=0;
	Node *p = L;
	while(p->next){
		p=p->next;
		cnt++;
	}
	return cnt;
} 
//插入一个新节点
bool InsertList(Node *&L,int i,ElemType e){
	if(i<1||i>GetLength(L)+1)return 0;
	Node *s = new Node;
	s->data = e;
	Node *p = GetElem(L,i-1);
	s->next = p->next;
	p->next = s;
	return 1;
}
//删除一个节点
bool DeleteList(Node *&L,int i,ElemType &e){
	if(i<1||i>GetLength(L))return 0;
	Node *p = GetElem(L,i-1),*q;
	if(p||p->next){
		e = p->next->data;
		q = p->next;//删除q 
		p->next = p->next->next;
		free(q);
		return 1;
	}else{
		return 0;
	}
} 

//输出单链表
void print(Node *L){
	Node *p = L->next;
	while(p!=L) {
		printf("%d ",p->data);
		p=p->next;
	} 
	printf("\n");
} 
int CountX(Node *&L,ElemType x ){
	int i=0;
	Node *p=L;
	while(p->next!=L){
		p=p->next;
		if(p->data==x)
			i++;
	}
	return i;
}
 
int main(){
	int a[]={1,2,3,3,5,3,7,8,9};
	int n = sizeof(a)/sizeof(int);
	Node *L;
	CreateR(L,a,n);
	print(L); 
	printf("%d\n",CountX(L,8));
	system("pause");
}


