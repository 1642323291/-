#include<iostream>
#include<stdlib.h>
using namespace std;
#include<bits/stdc++.h>

#define MaxSize 100
typedef int ElemType;
struct SqStack{ 
    ElemType data[MaxSize];
    int top;
};

void InitStack(SqStack *&s){
    s=(SqStack *)malloc(sizeof(SqStack));
    s->top=-1;
}

void DestroyStack(SqStack *&s){
    free(s);
}

bool StackEmpty(SqStack *&s){
    return (s->top==-1);
}

bool Push(SqStack *&s,ElemType e){
    if(s->top==MaxSize-1)
        return 0;
    s->top++;
    s->data[s->top]=e;
    return 1;
}

bool Pop(SqStack *&s,ElemType e){
    if(s->top==-1)
        return 0;
    e=s->data[s->top];
    s->top--;
    return 1;
}

bool GetTop(SqStack *s,ElemType &e){
    if(s->top==-1)
        return 0;
    e=s->data[s->top];
    return 1;
}
int main(){
    SqStack *s;
    InitStack(s); // 初始化栈
    Push(s, 5);
    Push(s, 6);
    ElemType topElement;
    if (GetTop(s, topElement)) {
        cout << "栈顶元素为: " << topElement << endl;
    } else {
        cout << "栈为空，无法获取栈顶元素。" << endl;
    }
    DestroyStack(s); // 销毁栈
    system("pause");
    return 0;
}