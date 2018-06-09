#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#define MAXSIZE 20
using namespace  std;
typedef struct
{
    int key;
    char *otherinfor;
}ElemType;
typedef struct
{
    ElemType *r;
    int length;
}SqList;
void BubbleSort(SqList &L)//冒泡排序
{
    int c,i,m=L.length;
    ElemType t;
    while(m>0)
    {
        for(c=0,i=1;i<m;i++)
        {
            if(L.r[i].key>L.r[i+1].key)
            {
                t=L.r[i];
                L.r[i]=L.r[i+1];
                L.r[i+1]=t;
                c=i;
            }
        }
        m=c;
    }
}
void CreatSqList(SqList &L)
{
    int i,n;
    printf("请输入数据个数(<MAXSIZE)\n");
    scanf("%d",&n);
    printf("请输入待排序的序列\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&L.r[i].key);
        L.length++;
    }
}
void ShowSqList(SqList L)
{
    int i;
    cout<<"排序后的序列为："<<endl;
    for(i=1;i<=L.length;i++)
    {
        cout<<L.r[i].key<<" ";
    }
    printf("\n");
}
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode, *LinkList;
void InitList(LinkList &L)
{
    L=(LNode*)malloc(sizeof(LNode));
    L->next=NULL;
}
void IntPut(LinkList &L,int m)
{
    int i;
    LinkList r,p;
    r=L;
    printf("请输入需要排列的数据：");
    for(i=0;i<m;i++)
    {
        p=(LNode*)malloc(sizeof(LNode));
        cin>>p->data;
        p->next=NULL;
        r->next=p;
        r=p;
    }
}
void OutPut(LinkList &L)//简单排列的输出
{
    LinkList p;
    p=(LNode*)malloc(sizeof(LNode));
    p=L->next;
    cout<<"排序后的序列为"<<endl;
    while(p)
    {
        cout<<p->data;
        p=p->next;
    }
    cout<<endl;
}
void SelectSort(LinkList &L)//简单选择排序
{
    LinkList r,q,p=L->next;
    int t;
    while(p)
    {
        q=p->next;
        r=p;
        while(q)
        {
            if(q->data<r->data)
                r=q;
            q=q->next;
        }
        if(r!=p)
        {
            t=r->data;
            r->data=p->data;
            p->data=t;
        }
        p=p->next;
    }
}
int main()
{
    int select=1;
    int m;
    SqList L;
    LinkList Q;
    while(select){
        cout<<"欢迎来到查找操作界面"<<endl;
        cout<<"[1]直接插入排序 [2]简单选择排序 [3]退出"<<endl;
        cout<<"请输入您想要进行的操作"<<endl;
        scanf("%d",&select);
        switch(select){
            case 1:
                L.r = (ElemType *) malloc(sizeof(ElemType));
                L.length = 0;
                CreatSqList(L);
                BubbleSort(L);
                ShowSqList(L);
                break;
            case 2:
                printf("请输入需要排序的数据个数\n");
                scanf("%d", &m);
                InitList(Q);
                IntPut(Q, m);
                SelectSort(Q);
                OutPut(Q);
                break;
            case 3:
                return 0;
            default:
                break;
        }
    }
}