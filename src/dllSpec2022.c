#include <stdlib.h>
#include "dllSpec2022.h"
#define NULL ((void *)0)



dllNode_t * DLL_init() //建構一個空的 list
{
    // dllNode_t* new_node = (struct node*) malloc(sizeof(struct node));
    dllNode_t* new_node = (dllNode_t*)malloc(sizeof(dllNode_t));
    if(!new_node) // 呼叫malloc()失敗時，回傳空的指標。
        return new_node;

    new_node->prev = NULL;
    new_node->next = NULL;


  //  return new_node;
}

int DLL_isEmpty(const dllNode_t *head) // head 是否為空的list
{
    if(head->prev == NULL && head->next == NULL)
        return 1;
    else
        return 0;
}
dllNode_t * DLL_next_node(const dllNode_t * node) //(下一個節點)
{
    return node->next;
}
dllNode_t * DLL_prev_node(const dllNode_t * node) //(上一個節點)
{
    return node->prev;
}
unsigned int DLL_num_nodes(const dllNode_t *head) //計算List中有幾個node
{
    /*
    // if傳進來的是list的頭
    int len = 0;
    dllNode_t* cur;
    while(cur != NULL)
    {
        len++;
        cur = cur->next;
    }
    return len;
    */

    // if傳進來的不是list的頭
    int len = 1;
    dllNode_t* cur;
    cur = head->next;
    while(cur != NULL)
    {
        len++;
        cur = cur->next;
    }
    cur = head->prev;
    while(cur != NULL)
    {
        len++;
        cur = cur->prev;
    }
    return len;

}
void DLL_add_first(dllNode_t * new_node, dllNode_t * head) //(將新new_node加入到head List 的第一個)
{
    new_node->prev = head->prev;
    new_node->next = head;
    /*
    if(head->prev)
    {
        head->prev->next = new_node;
    }
    */
    head->prev = new_node;
}
void DLL_add_tail(dllNode_t * new_node, dllNode_t *head) //(將新new_node加入到head List 的最後一個)
{
    new_node->prev = head;
    new_node->next = head->next;
    /*
    if(head->next)
    {
        head->next->prev = new_node;
    }
    */
    head->next = new_node;
}
void DLL_addto_prev(dllNode_t *new_node, dllNode_t *node) // (將新new_node加入到node的前一個)
{
    new_node->next = node;
    new_node->prev = node->prev;
    node->prev->next = new_node;
    node->prev = new_node;
}
void DLL_addto_next(dllNode_t *new_node, dllNode_t *node) // (將新new_node加入到node的後一個)
{
    new_node->prev = node;
    new_node->next = node->next;
    node->next->prev = new_node;
    node->next = new_node;
}
void DLL_delete(dllNode_t * node) //(從node所在的 Linked List 中刪除此點)
{
    if(!node->next && !node->prev) // 只有他
        return;
    if(node->next && !node->prev) // 在頭
    {
        node->next->prev = NULL;
    }
    else if(!node->next && node->prev) // 在尾
    {
        node->prev->next = NULL;
    }
    else // 在中間
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
}
dllNode_t * DLL_concate(dllNode_t *srcList, dllNode_t * dstList) //(將srcList 串在dstList之後)
{
    if(!srcList && dstList)
        return dstList;
    if(srcList && !dstList)
        return srcList;
    if(!srcList && !dstList)
        return NULL;

    // 要讓他在srcList的頭
    dllNode_t* cur_src = srcList;
    while(cur_src->prev != NULL)
        cur_src = cur_src->prev;

    // 要讓他在dstList的尾
    dllNode_t* cur_dst= dstList;
    while(cur_dst->next != NULL)
        cur_dst = cur_dst->next;

    cur_src->prev = cur_dst;
    cur_dst->next = cur_src;

    free(cur_src);
    free(cur_dst);
    return (dstList);
}
