#include <iostream>
#include <stdlib.h>
using namespace std;
#define  MAXLEN  100            /*定义常量MAXLEN为100表示存储空间总量*/
typedef  int  Elem;           /*定义DataType为int类型*/
struct SeqList                  /*顺序表存储类型*/
{
    Elem   data[MAXLEN];     /*存放线性表的数组*/
    int  Length;                           /*Length是顺序表的长度*/
};
//操作结果：构造一个线性表L。
SeqList L;//静态表 
//销毁线性表L,释放存储空间,静态表的空间由操作系统自动回收        

//将线性表L置为空表 
void ClearList(SeqList& L) {
    L.Length = 0;
}
//如果表L为空返回true,否则返回false           
bool ListEmpty(SeqList L) {
    return L.Length == 0;
}
//返回L中元素的个数
int ListLength(SeqList L) {
    return L.Length;
}
//返回线性表L中位置i处的元素
Elem GetElem(SeqList L, int i) {
    return L.data[i];
}
//如果e不在L中，返回0，否则返回元素e在线性表L中的位置 
int Locate(SeqList L, Elem e) {
    for (int i = 1; i <= L.Length; i++) {
        if (L.data[i] == e)return i;
    }
    return 0;
}
//在线性中的位置i处插入新元素e,表L的长度增加1    
bool InsertLinst(SeqList& L, int i, Elem e) {
    if (i > L.Length + 1 || i < 1)return 0;
    for (int j = L.Length + 1; j > i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i] = e;
    L.Length++;
    return 1;
}
//将L中位置i处的元素删除，表L的长度减1           
bool DeleteList(SeqList& L, int i, Elem& e) {
    if (i > L.Length || i < 1)return 0;
    e = L.data[i];
    for (int j = i; j < L.Length; j++) {
        L.data[j] = L.data[j + 1];
    }
    L.Length--;
    return 1;
}
//若e在L中存在且不是第1个元素, 返回true,将前驱结果保存到prior中,否则返回false
bool PriorElem(SeqList L, Elem e, Elem& prior) {
    int pos = Locate(L, e);
    if (pos <= 1)return 0;
    prior = L.data[pos - 1];
    return true;
}
//将线性表中元素输出
void print(SeqList L) {
    for (int i = 1; i <= L.Length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}
int main() {
    //将一组数添加到线性表 22,55,88,74,66,99,45
    InsertLinst(L, 1, 22);
    InsertLinst(L, 2, 55);
    InsertLinst(L, 3, 88);
    print(L);
    //将一组数添加到线性表
    InsertLinst(L, 4, 74);
    InsertLinst(L, 5, 66);
    InsertLinst(L, 6, 99);
    InsertLinst(L, 7, 45);
    print(L);
    //线性表中元素的个数
    printf("len:%d\n", L.Length);
    //删除一个元素
    Elem e;
    DeleteList(L, 2, e);
    print(L);
    printf("被删除的元素：%d\n", e);
    //在位置2上插入元素88
    InsertLinst(L, 2, 88);
    print(L);
    printf("被插入的元素：%d\n", 88);

    // 找到元素66的前驱元素  
    Elem prior;   
    bool found = PriorElem(L, 66, prior);
        printf("元素66的前驱元素是：%d\n", prior);
    // 删除66的前驱元素
    int pa = Locate(L, 66);
    int priorPa = pa - 1; 
    Elem deletedElem;
    DeleteList(L, priorPa, deletedElem);
    printf("删除了元素：%d\n", deletedElem);
    printf("删除后的线性表长度为：%d\n", ListLength(L));
    // 找到倒数第2个元素
    int length = ListLength(L);
    int pa1 = length - 1;  
    Elem end;
    end= GetElem(L, pa1);
    printf("倒数第2个元素为：%d\n", end);
    system("pause");
}
