//QUEUE Paulius Anužas II grupė I pogrupis PS
#ifndef queueFunc
#define queueFunc

typedef int type;                      // Eiles elementu tipas

typedef struct LinkedList{              //Eiles elemento struktura
    type data;                          //Elemento reiksme
    struct LinkedList *next;            //Rodykle i kita elementa
} LinkedList;

typedef struct Queue{                   //Eiles struktura
    LinkedList *head, *tail;            //head - eiles pradzia || tail - eiles pabaiga
} Queue;

Queue *newQueue();                      // Sukuria nauja eile. Pvz Queue *eile = newQueue();

/// return 1 - Queue is empty | 0 - Queue is not empty
int IsQueueEmpty (Queue *name);         // Patikrina ar eile yra tuscia. Jei tuscia grazina 1, jei ne - 0.

/// return 1 - Queue doesn't exist | 2 - No memory left
int Enqueue(Queue *queueName, type x);  // Ideda i eile nauja elementa x. Iskvietimui reikalinga nurodyti eiles pavadinima ir norima i eile ideti elementa.

/// return 1 - Queue doesn't exist | 2 - Queue is already empty
type Dequeue(Queue *queueName);         // Is eiles isima elementa. Iskvietimui reikalinga nurodyti eiles pavadinia.

/// return 1 - Queue doesn't exist
int DeleteQueue(Queue *queueName);      // Sunaikina nurodyta eile. Iskvietimui reikalinga nurodyti eiles varda.

/// return NULL - Queue is empty or doesn't exist
type FirstElement(Queue *queueName);    // Grazina pirma elementa jo neisimant is eiles

#endif
