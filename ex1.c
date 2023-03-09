#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generer(int tab[4]){
    srand(time(NULL));
    for (int i = 0; i<4; i++){
        tab[i] = rand() %6+1;
        printf("%d\n", tab[i]);
    };
    return 0;
}

int saisir(char tab[4]){
    printf("\nEcriver 4 lettre (parmis: P B M Y O G): ");
    scanf("%c %c %c %c", &tab[0], &tab[1], &tab[2], &tab[3]);
    return 0;
}

int afficherLettre(int tab[4]){
    for (int i = 0; i<4; i++){
        if (tab[i] == 0){
            printf("    °");
        }
        else if (tab[i] == 1){
            printf("    P");
        }
        else if (tab[i] == 2){
            printf("    V");
        }
    };
    return 0;
}

int verifRep(int tabRep[4], int secret[4], int tabAide[4]){
    int bonneRep = 0;
    for (int i = 0; i < 4; i++){
        if (tabRep[i] == secret[4]){
            for (int k = 0; k < 4; k++){
                    if (tabAide[k] == "0"){
                        tabAide[k] = "2";
                    }
                }
            bonneRep++;
        }
    }
    if (bonneRep == 4){
        printf("Vous avez gagner !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    }
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (tabRep[i] == secret[j]){
                for (int k = 0; k < 4; k++){
                    if (tabAide[k] == "0"){
                        tabAide[k] = "1";
                    }            
                }
            }
        }
    }
    return 0;
}

int afficherChiffre(char tab[4], int tabChiffre[4]){
    for (int i = 0; i<4; i++){
        if (tab[i] == "P"){
            printf("1");
            tabChiffre[i] = 1;
        }
        else if (tab[i] == "B"){
            printf("2");
            tabChiffre[i] = 2;
        }
        else if (tab[i] == "M"){
            printf("3");
            tabChiffre[i] = 3;
        }
        else if (tab[i] == "Y"){
            printf("4");
            tabChiffre[i] = 4;
        }
        else if (tab[i] == "O"){
            printf("5");
            tabChiffre[i] = 5;
        }
        else if (tab[i] == "G"){
            printf("6");
            tabChiffre[i] = 6;
        }
    };
    return 0;
}

int ecran(char tabRep[4], int aideLettre[4]){
    printf("--------------------------------|##|\n");
    printf("                                |%c%c|", aideLettre[0],aideLettre[1]);
    afficherLettre(tabRep);
    printf("|%c%c|", aideLettre[2],aideLettre[3]);
    return 0;
}

int rangementator(int tabAide[4], int aideLettre[4]){
    srand(time(NULL));
    for (int i = 0; i<4; i++){
        int hazard = rand() %4;
        if (aideLettre[hazard]){
            aideLettre[hazard] = aideLettre[i];
        }else{
            i--;
        }
    };
    printf("%d", aideLettre);
    return 0;
}


int main(){
    int secret[4];
    char reponse[4];
    int reponseChiffre[4];
    int tabAide[4];
    char aideLettre[4];
    int tour = 10;
    

    generer(secret);

    while (tour > 1){
        saisir(reponse);
        for (int i = 0; i <4; i++){
            printf("%c\n", reponse[i]);
        }
    
        afficherChiffre(reponse, reponseChiffre);
        for (int i = 0; i <4; i++){
            printf("%d\n", reponseChiffre[i]);
        }
        verifRep(reponseChiffre, secret, tabAide);
        rangementator(tabAide, aideLettre[4]);
        ecran(reponse, aideLettre[4]);
        tour++;
        printf("il vous reste %d tour(s)", tour);
    }
    if (tour <= 0){
        printf("Vous avez perdu !!!!!!!!!!!!!!");
    }  
    
    system("pause");
    return 0;

}