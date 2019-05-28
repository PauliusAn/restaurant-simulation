//QUEUE Paulius Anužas II grupė I pogrupis PS
#include <stdio.h>
#include <stdlib.h>
#include "queueFunc.h"

LinkedList* addData(type x){
    LinkedList *newList = (LinkedList*)malloc(sizeof(LinkedList));
    newList->data = x;
    newList->next = NULL;
    return newList;
}

Queue *newQueue(){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

int IsQueueEmpty (Queue *name){
    if (name->head == NULL)
        return 1;
    else
        return 0;
}

int Enqueue(Queue *queueName, type x){
    LinkedList *temp = addData(x);
    if (temp == NULL){
        return 2;
    }

    if (queueName == NULL){
        return 1;                       //Queue doesn't exust
    }

    if (queueName->head == NULL){
       queueName->head = temp;
       queueName->tail = temp;
       return 0;
    }
    queueName->tail->next = temp;
    queueName->tail = temp;
    return 10;
}

type FirstElement(Queue *queueName){
    if(queueName->head->data == NULL){
        return NULL;
    }
    return queueName->head->data;
}

type Dequeue(Queue *queueName){

    if(queueName == NULL){
        //printf("Queue doesn't exist!\n");
        return NULL;
    }
    if(queueName->head == NULL){
        //printf("Queue is already empty!\n");
        return NULL;
    }
    type temp = queueName->head->data;
    LinkedList *tempList = queueName->head->next;
    free(queueName->head);
    queueName->head = tempList;

    if(queueName->head == NULL){
        queueName->tail == NULL;
    }
    return temp;
}

int DeleteQueue(Queue *queueName){
    LinkedList *temp;
    if (queueName->head == NULL){
        return 1;
    }
    while (queueName->head != NULL){
        temp = queueName->head->next;
        free(queueName->head);
        queueName->head = temp;
    }
    //printf("Queue has been deleted!\n");
    return 0;
}
