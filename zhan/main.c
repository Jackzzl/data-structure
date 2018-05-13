#include <stdio.h>
#include <stdlib.h>
#include <w32api/rpc.h>

#define SIZE 100

typedef struct SNode{
    int data;
    struct SNode* next;
}SNode,*LinkStack;

int InitStack(LinkStack *top){
   *top=(LinkStack)malloc(sizeof(SNode));
   if(*top==NULL){
       printf("初始化链栈错误! \n");
       return 0;
   }
   else{
       (*top)->next=NULL;
       return 1;
   }
}//初始化
void Push(LinkStack top,int element){
    SNode *p;
    p=(SNode*)malloc(sizeof(SNode));//创建新节点
    if(!p){
        printf("入栈错误!\n");
    }
    else{
        p->data=element;
        p->next=top->next;
        top->next=p;
    }
}//入栈
void Pop(LinkStack top,int *element){
    SNode *p;
    if(!top->next){
        printf("空栈，无法进行操作 \n");
    }
    else{
        p=top->next;
        top->next=p->next;
        *element=p->data;
        free(p);
    }
}//出栈
void TravelStack(LinkStack top){
    SNode *p;
    if(!top->next){
        printf("是空栈，无法进行操作 \n");
    }
    else{
        while(!(p->next==NULL)){
            p=top->next;
            //*element =p->data;
            printf("%d",p->data);
            p=p->next;
        }
    }
    printf("\n");
}//输出
void GetTop(LinkStack top ,int *element){
    SNode *p;
    if(!top->next){
        printf("空栈，无法操作 \n");
    }
    else{
        p=p->next;
        *element=p->data;
    }
}
void main()
{
    LinkStack top;
    int item,n;
    int select=1;
    while (select){
        printf("***********\n");
        printf("链栈的功能如下\n");
        printf("[1]入栈  [2]出栈  [3]输出  [4]初始化  [5]取栈顶元素\n");
        printf("***********\n");
        printf("请选择需要的功能:");
        scanf("%d",&select);
        switch(select){
            case 1:
                printf("请输入要插入的数字");
                scanf("%d",&item);
                Push(top,item);
                break;

            case 2:
                Pop(top,&item);
                break;

            case 3:
                TravelStack(top);
                break;
            case 4:
                InitStack(&top);
                break;
            case 5:
                GetTop(top,&item);
                printf("栈顶的数据为：%d\n",item);
                break;
            default:
                break;
        }
    }

}