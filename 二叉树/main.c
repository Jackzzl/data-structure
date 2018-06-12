#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode{
    int data;
    struct Node *left,*right;//左孩子,右孩子
}BTNode,*PBTNode,*BiTreeLink;
BiTreeLink CreateBiTree(char *nodes,int pos,int num){
    PBTNode p;
    if(nodes[pos]==' ' || pos>num)  return NULL; /*递归结束条件*/
    p=(PBTNode)malloc(sizeof(BTNode));/*建立根结点*/
    if(!p){printf("初始化链表错误！\n");return 0;}
    p->data=nodes[pos];
    p->left=CreateBiTree(nodes,2*pos,num);	/* 递归建立左子树*/
    p->right=CreateBiTree(nodes,2*pos+1,num);/* 递归建立右子树*/
    return p;
}

PBTNode InsertRight(PBTNode r, int x){//插入右孩子
    PBTNode  p;
    if(!r){
        return NULL;}
    else{
        p=(PBTNode)malloc(sizeof(BTNode));//生成新节点
        p->data=x;
        p->left=NULL;
        p->right=r->right;
        r->right=p;
        return p;
    }
}
PBTNode InsertLeft(PBTNode r, int x){//插入左孩子
    PBTNode  p;
    if(!r)
        return NULL;
    else{
        p=(PBTNode)malloc(sizeof(BTNode));//生成新节点
        p->data=x;
        p->right=NULL;
        p->left=r->left;
        r->left=p;
        return p;
    }
}

void PreOrder(BiTreeLink r){//先序
    if(r!=NULL){
        printf("%c",r->data);
        PreOrder(r->left);
        PreOrder(r->right);
        printf("\n");
    }
    else{
        printf("\n");
    }
}

void InOrder(BiTreeLink r){//中序
    if(r!=NULL){
        InOrder(r->left);
        printf("%c",r->data);
        InOrder(r->right);
        printf("\n");
    }
}

void PostOrder(BiTreeLink r){//后序
    if(r!=NULL){
        PostOrder(r->left);
        PostOrder(r->right);
        printf("%c ",r->data);
        printf("\n");

    }

}

void main() {
    BiTreeLink r;
    int item,pos;
    int select=1;
    char *a;
    while (select){
        printf("***********\n");
        printf("二叉树的功能如下\n");
        printf("[1]插入左孩子  [2]插入右孩子  [3]先序输出  [4]中序输出 [5]后序输出  [6]创建二叉树\n");
        printf("***********\n");
        printf("请选择需要的功能:");
        scanf("%d",&select);
        switch(select){
            case 1:
                printf("请输入要插入的数字");
                scanf("%d",&item);
                InsertLeft(r,item);
                break;

            case 2:
                printf("请输入要插入的数字:");
                scanf("%d",&item);
                InsertRight(r,item);
                break;
            case 3:
                PreOrder(r);
                break;
            case 4:
                InOrder(r);
                break;
            case 5:
                PostOrder(r);
                break;
            case 6:
                //CreateBiTree(*a,pos,item);
                printf("请输入要输入根的数字: ");
                scanf("%d",&item);
                CreateBiTree(a,pos,item);
            default:
                break;
        }
    }
}