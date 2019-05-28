#include <stdio.h>
#include <stdlib.h>

FILE *AtidarytiDuom();
int NuskaitytiSkaicius(FILE *duomFile, int *leksciuSkaicius, int *valgymoLaikas, int *plovimoLaikas, double *atvykimoTikimybe, int *laikas);

FILE *AtidarytiDuom(){

    FILE *duomFile = NULL;

    duomFile = fopen("duom.txt", "r");

    if (duomFile == NULL){
        printf("NEPAVYKO ATIDARYTI DUOMENU FAILO\n");
        return NULL;
    }
    return duomFile;
}

int NuskaitytiSkaicius(FILE *duomFile, int *leksciuSkaicius, int *valgymoLaikas, int *plovimoLaikas, double *atvykimoTikimybe, int *laikas){
    int error;
    char line[256];
    FILE *komentarai = NULL;

    komentarai = fopen("duom.txt", "r");
    if (komentarai == NULL){
        printf("NEPAVYKO ATIDARYTI DUOMENU FAILO\n");
        return NULL;
    }
    line[0] = '#';
    while(line[0] == '#'){
        fgets(line, 255, komentarai);
        if(line[0] != '#'){
            error = fscanf(duomFile, "%d", leksciuSkaicius);
            fgets(line, 255, duomFile);
        }
        else fgets(line, 255, duomFile);
    }
    line[0] = '#';
    while(line[0] == '#'){
        fgets(line, 255, komentarai);
        if(line[0] != '#'){
            error = fscanf(duomFile, "%d", valgymoLaikas);
            fgets(line, 255, duomFile);
        }
        else fgets(line, 255, duomFile);
    }
    line[0] = '#';
    while(line[0] == '#'){
        fgets(line, 255, komentarai);
        if(line[0] != '#'){
            error = fscanf(duomFile, "%d", plovimoLaikas);
            fgets(line, 255, duomFile);
        }
        else fgets(line, 255, duomFile);
    }
    line[0] = '#';
    while(line[0] == '#'){
        fgets(line, 255, komentarai);
        if(line[0] != '#'){
            error = fscanf(duomFile, "%lf", atvykimoTikimybe);
            fgets(line, 255, duomFile);
        }
        else fgets(line, 255, duomFile);
    }
    line[0] = '#';
    while(line[0] == '#'){
        fgets(line, 255, komentarai);
        if(line[0] != '#'){
            error = fscanf(duomFile, "%d", laikas);
            fgets(line, 255, duomFile);
        }
        else fgets(line, 255, duomFile);
    }
    fclose(duomFile);
    fclose(komentarai);
    return 0;
}
