#include <stdio.h>
#include <stdlib.h>

typedef struct QNode{
    int data;
    struct QNode *next;
}LQNode,*PQNode;
typedef struct{
    PQNode front,rear;
}LinkQueue;

int InitQueue(LinkQueue *Q){
    Q->front=Q->rear=(PQNode)malloc(sizeof(LQNode));
    if(!Q->front){
        printf("初始化失败 \n");
        return 0;
    }
    Q->front->next=NULL;
    return 1;
};//初始化
int QueueEmpty(LinkQueue Q){
    if(Q.front==Q.rear){
        printf("空队列 \n");
        return 1;}

    else{
        printf("非空队列 \n");
        return 0;
    }
        //return 0;
}//判断为空
int EnQueue(LinkQueue *Q,int element){
    PQNode p;
    p=(PQNode)malloc(sizeof(LQNode));
    if(!p){
        printf("内存分配失败，不能完成操作 \n");
        return 0;
    }
    p->data=element;
    p->next=NULL;
    Q->rear->next=p;
    Q->rear=p;
    return 1;
}//入队
int DeQueue(LinkQueue *Q,int *element){
    PQNode p;
    if(Q->front==Q->rear){
        printf("空队列，错误操作 \n");
        return 0;
    }
    p=Q->front->next;
    *element=p->data;
    //printf(&element);
    Q->front->next=p->next;
    free(p);
    if(Q->rear==p){
        Q->rear=Q->front;
    }
    return 1;
}//出队操作

void main() {
    LinkQueue p;
    int item,n;
    int select=1;
    while (select){
        printf("***********\n");
        printf("链栈的功能如下\n");
        printf("[1]入队  [2]出队  [3]是否为空  [4]初始化\n");
        printf("***********\n");
        printf("请选择需要的功能:");
        scanf("%d",&select);
        switch(select){
            case 1:
                printf("请输入要插入的数字");
                scanf("%d",&item);
                EnQueue(&p,item);
                break;

            case 2:
                DeQueue(&p,&item);
                printf("输出的为：%d \n",item );
                break;
            case 3:
                QueueEmpty(p);
                break;
            case 4:
                InitQueue(&p);
                //printf("栈顶的数据为：%d\n",item);
                break;
            default:
                break;
        }
    }

}