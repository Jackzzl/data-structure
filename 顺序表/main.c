#include <stdio.h>
#include <stdlib.h>
//顺序表的插如，删除 与输出
#define LISTSIZE 100

typedef struct{
    int *elem;
    int items[LISTSIZE];
    int length;
}SqList;//定义线性表

int initList(SqList *L)
{
    //L.elem=(SqList)malloc(LISTSIZE*sizeof(SqList));
    L->length==0;
    return 1;
}//初始化

int ListInsert(SqList *L,int pos, int element)
{//*L为指针，POS为插入位置
    int i;
    if(L->length>=LISTSIZE){
        printf("顺序表已满，无法插入！");
        return 0;
    }
    if(pos<=0||pos>L->length+1){
        printf("插入的位置不合法\n");
        return 0;
    }
    else
    {
        for(i=L->length-1;i>=pos-1;i--){
            L->items[i+1]=L->items[i];
        }
        L->items[pos-1]=element;
        (L->length)++;
        return 1;
    }
}

int ListDelete(SqList *L,int pos, int *element)
{
    int i;
    if(L->length==0)
    {
        printf("此时为空表，无法进行删除");
        return 0;
    }
    if(pos<1||pos>L->length)
    {
        printf("删除位置错误\n");
        return 0;
    }
    else
    {*element =L->items[pos-1];
        for(i=pos;i<L->length;i++)
        {
            L->items[i-1]=L->items[i];
        }
        (L->length)--;
        return 1;
    }
}

int GetElem(SqList *L,int pos, int *element)
{
    if(L->length==0){
        printf("表为空,查找错误\n");
        return 0;
    }
    if(pos<=0||pos>L->length)
    {
        printf("查找位置不合法\n");
        return 0;
    }
    else
    {
        *element = L->items[pos-1];
        printf("%d",*element );
        printf("\n");
        return 1;
    }

}
void TraverseList(SqList *L)
{
    int i;
    for(i=0;i<L->length;i++){
        printf("%d\t",L->items[i]);
    }
    printf("\n");
    //return 1;1
}



void main()
{
    SqList L;
    initList(&L);
    int pos,item;
    int select =1;
    while(select)
    {
        printf("***********\n");
        printf("请选择你想进行的操作\n");
        printf("[1]插入  [2]删除  [3]查找  [4]输出  [5]初始化\n");
        printf("***********\n");
        printf("输入想进行功能的数字:");
        scanf("%d",&select);
        switch(select)
        {
            case 1:
                printf("请输入想插入的位置：");
                scanf("%d",&pos);
                printf("输入想插入的数字:");
                scanf("%d",&item);
                ListInsert(&L,pos,item);
                break;

                case 2:
                printf("想删除的位置：");
                scanf("%d",&pos);
                ListDelete(&L,pos,&item);
                break;

            case 3:
                printf("输入想查找的位置：");
                scanf("%d",&pos);
                GetElem(&L,pos,&item);
                break;

            case 4:
                TraverseList(&L);
                break;

            case 5:
                initList(&L);
                break;

            default:
                break;
        }
    }
    //return 0;
}
