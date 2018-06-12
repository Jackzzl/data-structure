#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE=100;

typedef struct Node{
    int data;
    int Length;
    struct Node*next;
}LNode,*PNode,*LinkList;

int InitList(LinkList*h){//?????
    *h=(LinkList)malloc(sizeof(LNode));
    if(!h){
        printf("无法正确创建链表\n");
        return 0;
    }
    (*h)->next =NULL;
    //(*L)->length =0;
    return 1;
}

int ListLength(LinkList h,int *total){
    *total=0;
    PNode p=h->next;
    while(p){
        (*total)++;
        p=p->next;
    }
    //printf("长度为\n",*total);
    return 1;
}//??????????

int LinkListInsert(LinkList h, int pos, int element){
    PNode p =h,q;
    int i=0;
    while(p&&i<pos-1){
        p=p->next;
        i++;
    }
    if(!p||i>pos-1){
        printf("插入位置错误\n");
        return 0;
    }
    q=(PNode)malloc(sizeof(LNode));//????????
    if(!q){
        printf("无法创建节点\n");
        return 0;
    }

    q->data=element;
    q->next=p->next;
    p->next=q;
    //(*L)->length++;
    return 1;
}

int LinkListDelete(LinkList h,int pos, int *item){
    PNode p =h,q;
    int i=0;
    while(p->next&&i<pos-1){
        p=p->next;
        i++;
    }
    if(!p->next||i>pos-1){
        printf("删除位置错误\n");
        return 0;
    }
    q=p->next;
    p->next=q->next;
    *item=q->data;
    free(q);
    return 1;
}

int GetElem(LinkList h,int pos,int *item){
    int i=0;
    PNode p =h->next;
    while(p&&i<pos-1){
        i++;
        p=p->next;
    }
    if(!p||i>pos-1){
        printf("查找位置错误\n");
        return 0;
    }
        //*item = p->data;
    else{
        *item = p->data;
        //printf("要查找的元素为：\n",*item);
        return 1;
    }

    //return 1;
}

void TraverseList(LinkList h){
    PNode p=h->next;
    while(p!=NULL){
       printf("%d\t,",p->data);
        p=p->next;
    }
    printf("\n");
    //return 1;
}

void main()
{
    LinkList L;
    InitList(&L);
    int pos,item,total;
    int select=1;
    while (select){
        printf("***********\n");
        printf("链表的功能如下\n");
        printf("[1]插入  [2]删除  [3]查找  [4]输出  [5]长度  [6]初始化\n");
        printf("***********\n");
        printf("请选择需要的功能:");
        scanf("%d",&select);
        switch(select){
            case 1:
                printf("请输入要插入的位置");
                scanf("%d",&pos);
                printf("请输入要插入的数字");
                scanf("%d",&item);
                LinkListInsert(L,pos,item);
                break;

            case 2:
                printf("请输入要删除的位置：");
                scanf("%d",&pos);
                LinkListDelete(L,pos,&item);
                break;

            case 3:
                printf("请输入要查找的位置：");
                scanf("%d",&pos);
                GetElem(L,pos,&item);
                printf("在此位置上的元素为：%d\n",item);
                break;
            case 4:
                TraverseList(L);
                break;
            case 5:
                ListLength(L,&total);
                printf("链表的长度为：%d\n",total);
                break;
            case 6:
                InitList(L);
                break;
            default:
                break;
        }
    }

}