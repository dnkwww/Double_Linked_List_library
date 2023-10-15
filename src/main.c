#include <stdio.h>
#include <stdlib.h>
#include "dllSpec2022.h"

typedef struct data_node{
    dllNode_t *node;
    int data;
} data_t;

int main()
{
    data_t* str = (data_t*)malloc(sizeof(data_t));
    str->node = DLL_init();

    data_t* a = (data_t *)malloc(sizeof(data_t));
    data_t* b = (data_t *)malloc(sizeof(data_t));
    data_t* c = (data_t *)malloc(sizeof(data_t));
    data_t* d = (data_t *)malloc(sizeof(data_t));
    data_t* e = (data_t *)malloc(sizeof(data_t));
    data_t* f = (data_t *)malloc(sizeof(data_t));

    a->node = DLL_init();
    b->node = DLL_init();
    c->node = DLL_init();
    d->node = DLL_init();
    e->node = DLL_init();
    f->node = DLL_init();

    a->data = 8;
    b->data = 6;
    c->data = 10;
    d->data = 9;
    e->data = 3;
    f->data = 7;

    DLL_add_tail(a->node, str->node);
    DLL_add_tail(b->node, str->node);
    DLL_add_tail(c->node, str->node);
    DLL_add_tail(d->node, str->node);
    DLL_add_tail(e->node, str->node);
    DLL_add_tail(f->node, str->node);
    //printf("%d\n",(data_t*) d->data);

    printf("total %d nodes\n",DLL_num_nodes(str->node)-1);

    dllNode_t *cur = str->node->next;
    while(cur)
    {
        if(cur == a->node)
            printf("%d ", a->data);
        else if(cur == b->node)
            printf("%d ", b->data);
        else if(cur == c->node)
            printf("%d ", c->data);
        else if(cur == d->node)
            printf("%d ", d->data);
        else if(cur == e->node)
            printf("%d ", e->data);
        else if(cur == f->node)
            printf("%d ", f->data);
        cur = cur->next;
    }
    printf("\n");

    free(a);
    free(b);
    free(c);
    free(d);
    free(e);
    free(f);
    free(str);

    system("PAUSE");
}
