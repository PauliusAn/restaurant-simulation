#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "stack.h"
#include "queueFunc.h"
#include "queueFunc.c"
//#include "adsIlgas_h.h"
#include "adsIlgas_func.c"

typedef struct indaplove{
    int leksciuSkaicius;
    int likesPlovimoLaikas;
    int arPlauna;
    int lekstesLaukia;
} indaplove;

int pridetiKlienta(int* i, int laikas, int Klientai[]);
int arAtejoKlientas(double atvykimoTikimybe);
void waitFor (unsigned int secs);
void sudetiStirta(Stack stack, int leksciuSkaicius);
int pridetiValgantiKlienta(Queue *queueName, int *valgymoLaikas);
int masyvoSuma(int Masyvas[], int n);
int inkrementuotiIlgaSveika(ilgasSveikas **inkrementuojamasSkaicius);
int minMaxEileje(Queue *queueName, int *min, int*max);

int pridetiKlienta(int* i, int laikas, int Klientai[]){
    Klientai[*i + 1] = laikas;
    *i++;
    return 0;
}

int arAtejoKlientas(double atvykimoTikimybe){

    double tikimybe = atvykimoTikimybe * 100;
    int r = rand();
    r = r % 100;

    if (tikimybe > r)
        return 1;
    else
        return 0;
}

void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;
    while (time(0) < retTime);
}

void sudetiStirta(Stack stack, int leksciuSkaicius){
    int i = 0;
    for(i; i < leksciuSkaicius; i++){
        stackPush(stack, 1);
    }
}

int masyvoSuma(int Masyvas[], int n){
    int i = 0, suma = 0;
    for(i; i < n; i++){
        suma += Masyvas[i];
    }
    return suma;
}

int inkrementuotiIlgaSveika(ilgasSveikas **inkrementuojamasSkaicius){

    ilgasSveikas *vienetas = NULL, *papildomas = NULL;
    char *sk[1];
    *sk = '1';
    inicijuoti(&vienetas, sk);
    sudetis(*inkrementuojamasSkaicius, vienetas, &papildomas);
    **inkrementuojamasSkaicius = *papildomas;
    return 0;
}

int minMaxEileje(Queue *queueName, int *min, int *max){
    int isimtas, minPapildomas, maxPapildomas;
    if(IsQueueEmpty(queueName) != 1){
        *min = FirstElement(queueName);
        *max = Dequeue(queueName);
        while(IsQueueEmpty(queueName) != 1){
            isimtas = 0;
            if(*min >= FirstElement(queueName)){
                *min = Dequeue(queueName);
                isimtas = 1;
                continue;
            }
            if(*max <= FirstElement(queueName) && IsQueueEmpty(queueName) != 1){
               *max = Dequeue(queueName);
                isimtas = 1;
                continue;
            }
            else if(IsQueueEmpty(queueName) != 1){
                isimtas = Dequeue(queueName);
            }
        }
        return 0;
    }
    else return 1;
}