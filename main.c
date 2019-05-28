/*
 * Autorius: Paulius Anužas
 * Užduotis: 3
 * Sąlyga:   2
 */
#include <stdio.h>
#include "funkcijos.c"
#include "stack.c"
#include "skaitymasIsFailo.c"
//#include "adsIlgas_func.c"
/*
 * PAKEITIMAI:
 *      +Iterpti komentarus i duomenu faila
 *      +Geriau panaudoti ilga sveika skaiciu
 *      +Kai baigsis lekstes zmogus laukia lekstes
 *      +Statistikoj isvesti kiek zmones lauke leksciu (min, max, vidurki)
 */
int main(){
    srand(time(NULL));

    int leksciuSkaicius, valgymoLaikas, plovimoLaikas, laikas, visasLaukimoLaikas = 0;
    int lekstesSulauke = 0, minLaukimoLaikas = 0, maxLaukimoLaikas = 0, klientaiEileje = 0;
    ilgasSveikas *apsilankiusiuKlientuSkaicius = NULL;
    char *sk = "0";
    inicijuoti(&apsilankiusiuKlientuSkaicius, sk);

    double atvykimoTikimybe;
    //char * str[12];
    FILE *duomFile = AtidarytiDuom();
    if(duomFile == NULL){
        return 0;   //Nepavyko atidaryti duomenu failo
    }
    NuskaitytiSkaicius(duomFile, &leksciuSkaicius, &valgymoLaikas, &plovimoLaikas, &atvykimoTikimybe, &laikas);
    if(laikas <= 0){
        printf("Klaidingi parametrai!\n");
        return 1;
    }
    /*
     * Nustatome indaplove
     */
    indaplove indaplove;
    indaplove.leksciuSkaicius = 0;
    indaplove.arPlauna = 0;
    indaplove.likesPlovimoLaikas = 0;
    indaplove.lekstesLaukia = 0;
    /*
     * Sudedame stirta
     */
    Stack stirta = stackCreate();
    sudetiStirta(stirta, leksciuSkaicius);

    int LeksciuSkaiciusStirtoje[laikas], bendrasLeksciuSkaicius = leksciuSkaicius;
    int i = 0;
    Queue *valgymoEile = newQueue();
    Queue *klientuEile = newQueue();
    Queue *laukimoLaikai = newQueue();
    valueType pop;
    /*
     * SIMULIACIJA
     */
    for (i; i < laikas; i++){
        /*
         * Ar atejo klientas.
         */
        LeksciuSkaiciusStirtoje[i] = leksciuSkaicius;
        printf ("%d.", i+1);
        printf("Leksciu stirtoje skaicius: %d. ", leksciuSkaicius);
        if (arAtejoKlientas(atvykimoTikimybe) == 1){ // ATEJO KLIENTAS.
            inkrementuotiIlgaSveika(&apsilankiusiuKlientuSkaicius);
            if(stackIsEmpty(stirta) != 1){
                stackPop(stirta, &pop);
                leksciuSkaicius--;
                if(Enqueue(valgymoEile, (i + valgymoLaikas)) == 1){ // Pridedam i valgymo eile.
                    printf("No memory left\n");
                    return 1;
                }
            }
            else {
                Enqueue(klientuEile, i);
                klientaiEileje++;
                printf("Klientas pradejo laukti lekstes. ");
            }
        }
        /*
         * Indaplove.
         */
        if(IsQueueEmpty(valgymoEile) != 1) {
            if (FirstElement(valgymoEile) == i) { // Tikrinam ar kuris nors is klientu pavalge
                /*
                 * Klientas pavalge
                 */
                Dequeue(valgymoEile);
                if (indaplove.arPlauna == 0) {
                    indaplove.leksciuSkaicius++;
                } else {
                    indaplove.lekstesLaukia++;
                }
            }
        }
            /*
             *  Ijungta indaplove.
             */
        if(indaplove.likesPlovimoLaikas == 0 && indaplove.arPlauna == 1){
            printf("Indaplove isjungiama! ");
            indaplove.arPlauna = 0;
            sudetiStirta(stirta, indaplove.leksciuSkaicius);
            leksciuSkaicius += indaplove.leksciuSkaicius;
            indaplove.leksciuSkaicius = indaplove.lekstesLaukia;
            indaplove.lekstesLaukia = 0;
            //KLIENTAI EILEJE
            //
            //
            while(stackIsEmpty(stirta) != 1 && IsQueueEmpty(klientuEile) != 1){
                visasLaukimoLaikas += (i - FirstElement(klientuEile));
                Enqueue(laukimoLaikai, (i - FirstElement(klientuEile)));
                Dequeue(klientuEile);
                lekstesSulauke++;
                stackPop(stirta, &pop);
                leksciuSkaicius--;
            }
        }
        if(indaplove.likesPlovimoLaikas != 0 && indaplove.arPlauna == 1){
            indaplove.likesPlovimoLaikas--;
        }

        if(indaplove.leksciuSkaicius >= bendrasLeksciuSkaicius / 2 && indaplove.arPlauna == 0 && indaplove.leksciuSkaicius > 1){
            indaplove.arPlauna = 1;
            indaplove.likesPlovimoLaikas = plovimoLaikas;
            printf("Indaplove nustatoma plauti %d laikui. ", plovimoLaikas);
        }
        printf("\n");
    }
    double vidutinisLaukimoLaikas;
    if(lekstesSulauke == 0){
        vidutinisLaukimoLaikas = 0;
    }
    else{
        vidutinisLaukimoLaikas = (double)visasLaukimoLaikas / (double)lekstesSulauke;
    }
    printf("Simuliacija baigta! \n");
    minMaxEileje(laukimoLaikai, &minLaukimoLaikas, &maxLaukimoLaikas);
    printf("----------------------------\n");
    printf("STATISTIKA:\n");
    //printf("Galutinis leksciu skaicius: %d\n", leksciuSkaicius);
    printf("Leksciu stirtoje vidurkis: %.2f\n", (double)masyvoSuma(LeksciuSkaiciusStirtoje, laikas)/(double)laikas);
    printf("Apsilankiusiu klientu skaicius: ");
    spausdintiSkaiciu(apsilankiusiuKlientuSkaicius);
    printf("Eileje lauke %d klientai\n", klientaiEileje);
    printf("Vidutinis laukimo laikas: %.2f\n", vidutinisLaukimoLaikas);
    printf("Trumpiausias laukimo eileje laikas: %d\n", minLaukimoLaikas);
    printf("Ilgiausias laukimo eileje laikas: %d\n", maxLaukimoLaikas);

    return 0;
}
