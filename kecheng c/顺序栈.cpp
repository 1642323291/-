#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
//顺序栈的数据结构
typedef int ElemType; 
const int M = 100;
struct SeqStack{
   ElemType data[M];//数据元素的存储空间 
   int top;//栈顶元素的位置 
}; 
//初始化
void InitStack(SeqStack &st){//在栈上申请空间 
   st.top=-1;
}
void InitStack1(SeqStack *&st){//在堆上申请空间 
   st = new SeqStack;
   st->top=-1;
}

//是否空
bool Empty(SeqStack st){
   return st.top==-1;
}
bool Empty1(SeqStack *st){
   return st->top==-1;
}
//是否满
bool Full(SeqStack st){
   return st.top==M-1;
}
bool Full1(SeqStack *st){
   return st->top==M-1;
}
//进栈 ,进栈失败返回0，否则返回1 
bool  push(SeqStack &st,ElemType e){
   if(Full(st))return 0;
   st.data[++st.top]=e;
   return 1;
}
bool  push1(SeqStack *&st,ElemType e){
   if(Full1(st))return 0;
   st->data[++st->top]=e;
   return 1;
}
//出栈
bool pop(SeqStack &st,ElemType &e){
   if(Empty(st))return 0;
   e = st.data[st.top--];
   return 1;
}
bool pop1(SeqStack *&st,ElemType &e){
   if(Empty1(st))return 0;
   e = st->data[st->top--];
   return 1;
}
//取栈顶元素 
bool getTop(SeqStack st,ElemType &e){
   if(Empty(st))return 0;
   e = st.data[st.top--];
   return 1;
}
bool getTop1(SeqStack *st,ElemType &e){
   if(Empty1(st))return 0;
   e = st->data[st->top--];
   return 1;
}
//判断一个字符串是否对称
bool IsMatch(string s){
   SeqStack st;
   ElemType e;
   InitStack(st);//初始化
   for(int i=0;s[i]!='\0';i++){
      push(st,s[i]);//把第i个字符进栈 
   } 
   int k=0;//原始串的位置
   while(!Empty(st)){
      //取栈顶元素
      pop(st,e) ;
      if(e!=s[k]){
         return 0;
      }
      k++;
   }
   return 1; 
} 
bool IsMatch1(string s){
   SeqStack *st;
   ElemType e;
   InitStack1(st);//初始化
   for(int i=0;s[i]!='\0';i++){
      push1(st,s[i]);//把第i个字符进栈 
   } 
   int k=0;//原始串的位置
   while(!Empty1(st)){
      //取栈顶元素
      pop1(st,e) ;
      if(e!=s[k]){
         return 0;
      }
      k++;
   }
   return 1; 
} 
void D2B(int n){
   SeqStack st;
   InitStack(st);
   ElemType e;
   //进栈
   while(n!=0){
      push(st,n%2);
      n/=2;
   } 
   //出栈的同时输出
   while(!Empty(st)){
      pop(st,e);
      cout<<e;
   } 
}
//判断是否合法出栈
bool IsRight(int a[],int n){
   SeqStack st;
   InitStack(st);
   ElemType e;
   //从1~n进行循坏，先进栈，看栈顶元素是否需要出栈
   for(int i=1,k=0;i<=n;i++){
      push(st,i);
      //查看栈顶元素与a[k]是否相同，如果相同 ，则出栈
      getTop(st,e);
      while(e==a[k]) {
         pop(st,e);
         k++;
         getTop(st,e);
      }
   } 
   return Empty(st); 
} 

int main(){
// string s="abcdcba";
// IsMatch(s)==1?cout<<"对称":cout<<"不对称";
// int n=10;
// D2B(n);
   int a[5]={5,1,3,2,4};
   IsRight(a,5)==1?cout<<"合法":cout<<"不合法";
   system("pause");
   return 0;
}