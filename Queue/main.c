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
};
int QueueEmpty(LinkQueue Q){
    if(Q.front==Q.rear)
        return 1;
    else
        return 0;
}//判断为空
int EnQueue(LinkQueue Q,int element){
    PQNode p;
    p=(PQNode)malloc(sizeof(LQNode));
    if(!p){
        printf("内存分配失败，不能完成操作 \n");
        return 0;
    }
    p->data=element;
    p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
    return 1;
}//入队
int DeQueue(LinkQueue *Q,int *element){
    PQNode p;
    if(Q->front==Q->rear){
        printf("空队列，错误操作 \n");
        return 0;
    }
    p=Q->front->next;
    Q->front->next=p->next;
    free(p);
    if(Q->rear==p){
        Q->rear=Q->front;
    }
    return 1;
}//出队操作

int main() {
    printf("Hello, World!\n");
    return 0;
}