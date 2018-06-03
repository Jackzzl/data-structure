#include "stdio.h"
#include "string.h"

#define MAX 50 // 最大顶点个数
#define QUEUESIZE 50
typedef struct {
    int matrix[MAX][MAX]; // 邻接矩阵
    int vertex[MAX]; // 顶点信息
    int visited[MAX]; // 用于遍历时判断是否被访问过，0表示未被访问过
    int numOfVertex; // 顶点数
} MGraph;

typedef struct {
    int items[QUEUESIZE];
    int front, rear;
    int count;
} SqQueue;
SqQueue sqQueue;
int initQueue(SqQueue *sqQueue) {
    sqQueue->front = 0;
    sqQueue->rear = 0;
    sqQueue->count = 0;
    return 1;
}

/** judge whether the sqQueue is empty or not
 *
 * @param sqQueue
 * @return {@code 0} if SqQueue is not empty
 *   while {@code 1} if SqQueue is empty
 */
int isQueueEmpty(SqQueue sqQueue) {
    if (sqQueue.count == 0) {
        return 1;
    }
    return 0;
}

/** enqueue
 *
 * @param sqQueue
 * @param newItem
 * @return {@code 0} if enqueue operation fail
 *   while {@code 1} if enqueue operation success
 */
int enQueue(SqQueue *sqQueue, int newItem) {
    if (sqQueue->rear == sqQueue->front && sqQueue->count == QUEUESIZE) {
        printf("the queue is full");
        return 0;
    }
    sqQueue->items[sqQueue->rear] = newItem;
    sqQueue->rear = (sqQueue->rear + 1) % QUEUESIZE;
    sqQueue->count++;
    return 1;
}

/** deQueue
 *
 * @param sqQueue
 * @param deQueueItem
 * @return {@code 0} if delete operation fail
 *   while {@code 1} if delete operation success
 */
int deQueue(SqQueue *sqQueue) {
    if (sqQueue->count == 0) {
        printf("fail to deQueue because the queue is empty");
        return 0;
    }
    int deleteItem;
    deleteItem = sqQueue->items[sqQueue->front];
    sqQueue->front = (sqQueue->front + 1) % QUEUESIZE;
    sqQueue->count--;
    return deleteItem;
}

/**
 * 初始化邻接矩阵
 * @param adjMatrix
 */
void initGraph(MGraph *g) {
    g->numOfVertex = 0;
    memset(g->visited, 0, sizeof(g->visited));
}

/**
 * 深度优先遍历
 * @param adjMatrix
 * @param row
 */
void DFS(MGraph *g, int row) {
    for (int i = 0; i < g->numOfVertex; i++) {
        if (g->matrix[row][i] == 1 && g->visited[i] == 0) {
            printf("%d ", g->vertex[i]);
            g->visited[i] = 1;
            DFS(g, i);
        }
    }
}

// 假设没有孤立的点，从第一行开始
void BFS(MGraph *g) {
    enQueue(&sqQueue, 0);
    while (!isQueueEmpty(sqQueue)) {
        int index = deQueue(&sqQueue);
        printf("%d ", g->vertex[index]);
        g->visited[index] = 1;
        for (int i = 0; i < g->numOfVertex; i++) {
            if (g->matrix[index][i] == 1 && g->visited[i] == 0) {
                g->visited[i] = 1;
                enQueue(&sqQueue, i);
            }
        }
    }
}

void menu(MGraph *g) {
    printf("可以进行以下选择\n");
    while (1) {
        printf("\n");
        printf("1.创建邻接矩阵 2.深度遍历 3.广度遍历 4.退出\n");
        printf("请选择：");
        int option; // 选项
        int temp;
        // 当输入是字符或字符串时，会出现无限循环的现象，并未查明具体原因
        scanf("%d", &option); // NOLINT
        getchar();
        switch (option) {
            case 1:
                if (g->numOfVertex != 0) {
                    printf("已创建邻接矩阵");
                    break;
                }
                printf("请输入顶点数目: ");
                scanf("%d", &g->numOfVertex); // NOLINT
                printf("请输入顶点元素值：");
                for (int i = 0; i < g->numOfVertex; i++) {
                    scanf("%d", &temp); // NOLINT
                    g->vertex[i] = temp;
                }
                printf("请输入顶点之间的关系：\n");
                for (int i = 0; i < g->numOfVertex; i++) {
                    for (int j = 0; j < g->numOfVertex; j++) {
                        scanf("%d", &temp); // NOLINT
                        g->matrix[i][j] = temp;
                    }
                }
                break;
            case 2:
                if (g->numOfVertex == 0) {
                    printf("请先创建邻接矩阵\n");
                    break;
                }
                // 从第一个开始深度遍历
                DFS(g, 0);
                printf("\n");
                memset(g->visited, 0, sizeof(g->visited));
                break;
            case 3:
                if (g->numOfVertex == 0) {
                    printf("请先创建邻接矩阵\n");
                    break;
                }
                BFS(g);
                printf("\n");
                memset(g->visited, 0, sizeof(g->visited));
                break;
            case 4:
                return;
            default:
                printf("请正确输入选项\n");
                break;
        }
    }
}

int main() {
    initQueue(&sqQueue);
    MGraph g;
    initGraph(&g);
    menu(&g);
}