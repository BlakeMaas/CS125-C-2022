/*
 * File:    hw12.c
 * Project: Homework 12
 * Author:  blake maas
 * Date: Nov 19, 2022
 * Source of Help:
 *      Cannon, Sawyer
 */

#include <stdio.h>  /* for printf */
#include <stdlib.h> /* for malloc, free, NULL */
#include "link.h"

typedef struct {
    Link* head;
} LinkedList;

/* helper functions */
Link* getNewLink(int value, Link* next);
void tailRecursivePrint(const Link* l);

/* functions on a LinkedList */
void listInit(LinkedList* list);
void listAddValue(LinkedList* list, int value);
void listAddArray(LinkedList* list, const int array[], int arrayLen);
void listPrint(const LinkedList* list);
void listPrintReverse(const LinkedList* list);
int  listGetSum(const LinkedList* list);
void listFree(LinkedList* list);

/* initialize the variable(s) in the LinkedList */
void listInit(LinkedList* list) {
    if (list != NULL)
        list->head = NULL;
        
}

/* list function that uses tail recursive helper function */
void listPrintReverse(const LinkedList* list) {
    tailRecursivePrint(list->head);
    printf("\n");
}

int main() {
    LinkedList myList;
    int array[6] = {7, 1, -4, 16, 0, 3};
    int arrLen = 6;
    listInit(&myList);
    listAddValue(&myList, -2);
    listPrint(&myList);
    listAddArray(&myList, array, arrLen);
    listPrint(&myList);
    listPrintReverse(&myList);
    printf("The sum is: %d\n", listGetSum(&myList));
    listFree(&myList);
    if (myList.head == NULL)
        printf("Good work!\n");
    else
        printf("Problem with listFree(): myList isn't empty!\n");
    return EXIT_SUCCESS;
}

Link* getNewLink(int value, Link* next){
  Link* newLink = (Link*)malloc(sizeof(Link));
  newLink->value = value;
  newLink->next = next;
  return newLink;
}

void tailRecursivePrint(const Link* l){
  if(l != NULL) {
    if(l->next != NULL){
      tailRecursivePrint(l->next);
    }
    printf("%3d",l->value);
  }
}

void listAddValue(LinkedList* list, int value){
  if (list != NULL)
    list->head = getNewLink(value, list->head);
}

void listAddArray(LinkedList* list, const int array[], int arrayLen){
  if(list != NULL) {
    int i = 0;
    for(i = 0; i < arrayLen; i++) {
      list->head = getNewLink(array[i], list->head);
    }
  }
}

void listPrint(const LinkedList* list){
  if(list != NULL) {
    Link* cursor = list->head;
    while(cursor != NULL) {
      printf("%3d", cursor->value);
      cursor = cursor->next;
    }
    printf("\n");
  }  
}

int  listGetSum(const LinkedList* list){
  if(list != NULL) {
    int sum = 0;
    Link* cursor = list->head;
    while(cursor != NULL) {
      sum += cursor->value;
      cursor = cursor->next;
    }
    return sum;
  }
  return 0;
}

void listFree(LinkedList* list){
  if(list != NULL) {
    Link* tmp;
    while(list->head != NULL) {
      tmp = list->head;
      list->head = list->head->next;
      free(tmp);
    }
  }
}