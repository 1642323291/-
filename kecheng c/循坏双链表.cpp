#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef int ElemType;
struct DBLNode{
	ElemType data;
	DBLNode *prior,*next;
}; 
//头插法
void CreateDBL(DBLNode *&L,ElemType a[],int n){
	L = new DBLNode;
	L->prior=L->next=L;
	DBLNode *s = new DBLNode;
	s->data = a[0];
	s->next = L->next;
	//if(L->next!=NULL)
	L->next->prior = s;
	s->prior = L;
	L->next = s;
	L->prior = s ;
	for(int i=1;i<n;i++){
		s = new DBLNode;
		s->data = a[i];
		s->next = L->next;
		//if(L->next!=NULL)
		L->next->prior = s;
		s->prior = L;
		L->next = s;
	}
	
} 
//尾插法
void CreateDBR(DBLNode *&L,ElemType a[],int n){
	L = new DBLNode;
	L->prior=L->next=L;
	DBLNode *r = L;
	for(int i=0;i<n;i++){
		DBLNode *s = new DBLNode;
		s->data = a[i];
		s->next =r->next;
		s->prior = r;
		r->next = s;
		r = s;
	}
	L->prior = r;
} 
//输出链表
void print(DBLNode *L){
	DBLNode *p = L;
	while(p->next!=L){
		p = p->next;
		printf("%d ",p->data);
	}
	printf("\n");
} 
//找出第i个位置上的节点p 
bool FindNode(DBLNode *&L,int i,DBLNode *&p){
	int cnt=0,f=0;
	p = L;
	while(p->next){
		p = p->next;
		cnt++;
		if(cnt==i){
			f=1;
			break;
		}
	}
	if(f==0) return false;
	else return 1;
}
//插入：在双链表的第i个位置插入元素e
bool InsertList(DBLNode *&L,int i,ElemType e) {
	//找出第i-1个位置的节点p
	DBLNode *p;
	if(FindNode(L,i-1,p)==0)return 0;	 
	//建立一个新的节点插到p节点之后 
	DBLNode *s = new DBLNode;
	s->data = e;
	s->next = p->next;
	if(p->next)
		p->next->prior = s;
	s->prior=p;
	p->next=s;
	return true;
}

bool DeleteList(DBLNode *&L,int i,ElemType &e){
	//找出第i-1各节点p
	DBLNode *p,*q;
	if(FindNode(L,i-1,p)==0)return 0;
	//将p后面的节点元素值返回，并删除p后面的节点 
	q = p->next;//将被删除
	if(q==NULL)return 0;//q不存在
	p->next = q->next; 
	if(q->next){
		q->next->prior = p;
	}
	//free(q);
	delete q;
	return 1;
}
void Reverse(DBLNode *&L){
	//分离：头结点与数据节点
	DBLNode *p = L->next,*q;
	L->next = NULL;
	//遍历数据节点
	while(p){
		q = p->next;
		p->next = L->next;
		if(L->next){
			L->next->prior = p;
		}
		p->prior = L;
		L->next = p;
		p = q;
	} 
}
int main(){
	ElemType a[]={1,2,3,4,5,6,7,8,9};
	DBLNode *h;
	CreateDBL(h,a,9);
	print(h);
//	InsertList(h,5,56);
//	print(h);
//	ElemType e;
//	DeleteList(h,5,e);
//	print(h);
//	Reverse(h);
//	print(h);
    system("pause");
}

