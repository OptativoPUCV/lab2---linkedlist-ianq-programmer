#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() 
{
  List *lista =  (List *) malloc(sizeof(List));

  lista->head = NULL;
  lista->tail = NULL;
  lista->current = NULL;
    return lista;
}

void * firstList(List * list) 
{
  Node* n = list->head;

  list->current = n;

  if(n == NULL)
    return NULL;
    
  
  return n->data;
}

void * nextList(List * list) 
{
  if(list->current==list->tail || list->current == NULL)
    return NULL;
  list->current = list->current->next;
  
  return list->current->data;
}

void * lastList(List * list) 
{
  if(list->tail == NULL)
    return NULL;
  list->current = list->tail;
  return list->tail->data;
}

void * prevList(List * list) {
  if(list->current == list->head || list->current == NULL)
    return NULL;
  list->current = list->current->prev;
  return list->current->data;
}

void pushFront(List * list, void * data) 
{
  Node* n = createNode(data);
  if(list->head == NULL)
  {
    list->head = n;
    list->tail = n;
  }
  else
  {
    n->next = list->head;
    list->head->prev = n;
    list->head = n;
  }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) 
{
  Node *nuevoDato;
  nuevoDato = createNode(data);
  if(list->current == list->tail)
    {
    list->tail = nuevoDato;
    }
  nuevoDato->next = list->current->next;
  nuevoDato->prev = list->current;
  list->current->next = nuevoDato;
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}