#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}BTNode,*PBTNode,*BiTreeLink;
BiTreeLink  CreateBiTree(int *nodes,int pos,int num){
    PBTNode  p;
    if(pos>=num){
        return NULL;
    }
    p=(PBTNode)malloc(sizeof(BTNode));
    if(!p){
        printf("初始化错误 ! \n");
        return 0;
    }
    p->data=nodes[pos];
    p->left=CreateBiTree(nodes,2*pos,num);
    p->right=CreateBiTree(nodes,2*pos+1,num);
    return p;
}
void ReleaseTree(PBTNode *r){
    if(*r){
        ReleaseTree(&(*r)->left);
        ReleaseTree(&(*r)->right);
        free(*r);
    }
}

void PreOrder(BiTreeLink biTreeLink){//先序
    if(biTreeLink!=NULL){
        printf("%d",biTreeLink->data);
        PreOrder(biTreeLink->left);
        PreOrder(biTreeLink->right);
    }
}
void InOrder(BiTreeLink biTreeLink){//中序
    if(biTreeLink!=NULL){
        InOrder(biTreeLink->left);
        printf("%d",biTreeLink->data);
        InOrder(biTreeLink->right);
    }
}
void PostOrder(BiTreeLink biTreeLink){//后序
    if(biTreeLink!=NULL){
        PostOrder(biTreeLink->left);
        PostOrder(biTreeLink->right);
        printf("%d",biTreeLink->data);
    }
}
/*根据递归求节点数
 *
 * */
int BiTreeCount(BiTreeLink biTreeLink){
    if(biTreeLink==NULL){
        return 0;
    }
    else{
        return BiTreeCount(biTreeLink->left)+BiTreeCount(biTreeLink->right)+1;
    }
}
/*求二叉树的深度
 *
 * */
int BiTreeDepth(BiTreeLink biTreeLink){
    int ld,rd;
    if(biTreeLink=NULL)
        return 0;
    else{
        ld=BiTreeDepth(biTreeLink->left);
        rd=BiTreeDepth(biTreeLink->right);
        return ld>rd?ld+1:rd+1;
    }
}
BiTreeLink biTreeLink;
void main() {
    int select=1;
    int nodes[100];
    int n;
    printf("二叉树操作界面 \n");
    while(select){
        printf("\n");
        printf("[1]创建二叉树 [2]先序遍历 [3]中序遍历 [4]后序遍历 [5]退出 \n");
        scanf("%d",&select);
        getchar();
        switch (select){
            case 1:
                if(biTreeLink!=NULL){
                    printf("已建立二叉树");
                    break;
                }
                printf("请输入节点数：");
                scanf("%d",&n);
                int length=n;
                printf("从左向右，从上到下，依次请输入：(例如 1 3 4)");
                for(int i=1;i<=length;i++){
                    scanf("%d",&n);
                    nodes[i]=n;
                }
                biTreeLink=CreateBiTree(nodes,1,length+1);
                break;
            case 2:
                if(biTreeLink==NULL){
                    printf("二叉树为空 \n");
                    break;
                }
                PreOrder(biTreeLink);
                printf("\n");
                break;
            case 3:
                if(biTreeLink==NULL){
                    printf("二叉树为空 \n");
                    break;
                }
                InOrder(biTreeLink);
                printf("\n");
                break;
            case 4:
                if(biTreeLink==NULL){
                    printf("二叉树为空 \n");
                    break;
                }
                PostOrder(biTreeLink);
                printf("\n");
                break;
            case 5:
                return;
            default:
                break;
        }
    }
}