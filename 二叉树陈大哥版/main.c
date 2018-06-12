#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} BTNode, *PBTNode, *BiTreeLink;

/**
 * to create a new binary tree
 * @param nodes
 * @param position
 * @param num
 * @return a binary tree
 */
BiTreeLink createBiTree(int *nodes, int position, int num) {
    PBTNode p;
    if (position >= num) {
        return NULL;
    }
    p = (PBTNode) malloc(sizeof(BTNode));
    if (!p) {
        printf("fail to initialize the binary tree.");
        return 0;
    }
    p->data = nodes[position];
    p->left = createBiTree(nodes, 2 * position, num);
    p->right = createBiTree(nodes, 2 * position + 1, num);
    return p;
}

/**
 * release the binary tree
 * @param r
 */
void releaseTree(PBTNode *r) {
    if (*r) {
        releaseTree(&(*r)->left);
        releaseTree(&(*r)->right);
        free(*r);
    }
}

/**
 * 先序遍历
 * @param biTreeLink
 */
void preOrder(BiTreeLink biTreeLink) {
    if (biTreeLink != NULL) {
        printf("%d ", biTreeLink->data);
        preOrder(biTreeLink->left);
        preOrder(biTreeLink->right);
    }
}

/**
 * 中序遍历
 * @param biTreeLink
 */
void inOrder(BiTreeLink biTreeLink) {
    if (biTreeLink != NULL) {
        inOrder(biTreeLink->left);
        printf("%d ", biTreeLink->data);
        inOrder(biTreeLink->right);
    }
}

/**
 * 后序遍历
 * @param biTreeLink
 */
void postOrder(BiTreeLink biTreeLink) {
    if (biTreeLink != NULL) {
        postOrder(biTreeLink->left);
        postOrder(biTreeLink->right);
        printf("%d ", biTreeLink->data);
    }
}

/**
 * 通过递归求得二叉树的节点数量
 * @param r
 * @return the quantity of the nodes in binary tree
 */
int BiTreeCount1(BiTreeLink r) {
    if (r == NULL) {
        return 0;
    } else {
        return BiTreeCount1(r->left) + BiTreeCount1(r->right) + 1;
    }
}

int count = 0;

/**
 * 通过前中后序遍历的方法求二叉树的节点数
 * @param r
 * @return the quantity of the nodes in binary tree
 */
int BiTreeCount2(BiTreeLink r) {
    if (r != NULL) {
        BiTreeCount2(r->left);
        BiTreeCount2(r->right);
        count++;
    }
}

/**
 * 求得二叉树的深度
 * @param biTreeLink
 * @return the depth of the binary tree
 */
int biTreeDepth(BiTreeLink biTreeLink) {
    int ld, rd;
    if (biTreeLink == NULL) {
        return 0;
    } else {
        ld = biTreeDepth(biTreeLink->left);
        rd = biTreeDepth(biTreeLink->right);
        return ld > rd ? ld + 1 : rd + 1;
    }
}

BiTreeLink biTreeLink;

void menu() {
    printf("欢迎光临 二叉树操作界面!\n");
    printf("您可以进行以下选择\n");
    while (1) {
        printf("\n");
        printf("1.创建二叉树 2.先序遍历 3.中序遍历 4.后序遍历 5.退出系统\n");
        printf("请选择：");
        int option; // 选项
        int nodes[50]; // 新建节点数组
        int num; // 节点数目
        // 当输入是字符或字符串时，会出现无限循环的现象，并未查明具体原因
        scanf("%d", &option); // NOLINT
        getchar();
        switch (option) {
            case 1:
                if (biTreeLink != NULL) {
                    printf("已创建二叉树");
                    break;
                }
                printf("请输入节点数目: ");
                scanf("%d", &num); // NOLINT
                int length = num;
                printf("请按左至右，上至下顺序输入值: ");
                for (int i = 1; i <= length; i++) {
                    scanf("%d", &num); // NOLINT
                    nodes[i] = num;
                }
                biTreeLink = createBiTree(nodes, 1, length + 1);
                break;
            case 2:
                if (biTreeLink == NULL) {
                    printf("请先创建二叉树\n");
                    break;
                }
                preOrder(biTreeLink);
                printf("\n");
                break;
            case 3:
                if (biTreeLink == NULL) {
                    printf("请先创建二叉树\n");
                    break;
                }
                inOrder(biTreeLink);
                printf("\n");
                break;
            case 4:
                if (biTreeLink == NULL) {
                    printf("请先创建二叉树\n");
                    break;
                }
                postOrder(biTreeLink);
                printf("\n");
                break;
            case 5:
                return;
            default:
                printf("请正确输入选项\n");
                break;
        }
    }
}

int main() {
    menu();
}