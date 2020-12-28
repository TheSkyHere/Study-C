#include<stdio.h>
typedef struct NODE
{
    int data;
    struct Node *next;
}Node,*LinkList;
   
LinkList LLCreate(const int n)
{
    int i;
    LinkList head;
    Node *p;
    head = NULL;
    for(;i<n;i++)
    {
        p = (Node*)malloc(sizeof(Node));
        if(NULL==p)
            printf("err");
        printf("next link date \n");
        scanf("%d",&p->data);
        p->next = head;//向头插入节点。
        head = p;
    }
    printf("iput date over\n");
    return head;
}
void Printf_Link(LinkList head)
{
    LinkList P;
    P=head;
    printf("link date: \n");
    for(;P;P=P->next)
        printf("%d",P->data);
    printf("\n");
}

void main()
{

    LinkList Head;
    int num;
    printf("please input link count\n");
    scanf("%d",&num);
    Head = LLCreate(num);
    Printf_Link(Head);

}