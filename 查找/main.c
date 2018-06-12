#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}BTNode,*BiTreeLink;

/*
 * 向二叉树中插入元素
 * */
void insert(BiTreeLink *biTreeLink, int data) {
    BTNode *p;
    BTNode *pre = NULL; // 指向p前面一个节点
    p = *biTreeLink;
    // 先查找是否有该元素
    while (p!=NULL) {
        pre = p;
        if (p->data == data) {
            return;
        }
        if (p->data < data) {
            p = p->right;
        } else {
            p = p->left;
        }
    }
    // 未找到，则插入
    p = (BTNode *) malloc(sizeof(BTNode));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    if (pre == NULL) {
        *biTreeLink = p;
        return;
    }
    if (pre->data > data) {
        pre->left = p;
    } else {
        pre->right = p;
    }
}
/*
 * 删除节点
 * */
void BSTDelete(BiTreeLink *biTreeLink,int x){
    BTNode *p,*pre=NULL,*s;//p指向被删除的节点，pre指向双亲,s指向p的孩子
    p=*biTreeLink;
    while(p!=NULL&&p->data!=x){
        pre=p;
        if(p->data<x)
            p=p->right;
        else
            p=p->left;
    }
    if(p==NULL){
        printf("未找到该节点");
        printf("\n");
        return;
    }
    //左右都有孩子
    s=p;
    //寻找被删节点的中序前驱节点,并用P指向它
    if(s->left&&s->right){
        pre=s;
        p=s->left;
        //如果从左子树中选择，选择左子树中最右边的叶子节点
        while(p->right!=NULL){
            pre=p;
            p=p->right;
        }
        if(p!=s)
            s->data=p->data;
    }
    s=(p->left)?p->left:p->right;
    if(!pre){
        *biTreeLink=s;
    }
    else{
        if(pre->left==p){
            pre->left=s;
        }
        else{
            pre->right=s;
        }
    }
    free(p);
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
BTNode *BSTSearch(BiTreeLink biTreeLink,int x){
    BTNode *p;
    p=biTreeLink;
    if(biTreeLink==NULL)
        return NULL;
    while(p!=NULL){
        if(p->data==x){
            return p;
        }
        //找右子树
        if(p->data<x){
            p=p->right;
        }
        else{
            p=p->left;
        }
    }
    return NULL;
}
void main() {
    int select=1;
    BiTreeLink biTreeLink;
    BTNode *searchNode;
    int n;
    printf("二叉树操作界面 \n");
    while(select){
        printf("\n");
        printf("[1]插入元素 [2]删除元素 [3]先序遍历 [4]中序遍历 [5]后序遍历 [6]查找 [7]退出 \n");
        scanf("%d",&select);
        getchar();
        switch (select){
            case 1:
               printf("请输入要插入的元素:");
               scanf("%d",&n);
               insert(&biTreeLink,n);
               break;
            case 2:
                printf("要删除的元素:");
                scanf("%d",&n);
                BSTDelete(&biTreeLink,n);
                break;
            case 3:
                if(biTreeLink==NULL){
                    printf("二叉树为空 \n");
                    break;
                }
                PreOrder(biTreeLink);
                printf("\n");
                break;
            case 4:
                if(biTreeLink==NULL){
                    printf("二叉树为空");
                    break;
                }
                InOrder(biTreeLink);
                printf("\n");
                break;
            case 5:
                if(biTreeLink==NULL){
                    printf("二叉树为空 \n");
                    break;
                }
                PostOrder(biTreeLink);
                printf("\n");
                break;
            case 6:
                printf("请输入要查找的数字");
                scanf("%d",&n);
                searchNode=BSTSearch(biTreeLink,n);
                if(searchNode!=NULL){
                    printf("元素存在");
                }
                else{
                    printf("元素不存在");
                }
                printf("\n");
                break;
            case 7:
                return;
            default:
                break;
        }
    }
}