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
}

int saisir(int tab[4]){
    printf("\nEcriver 4 lettre (parmis: P B M Y O G): ");
    scanf("%s %s %s %s", tab[1], tab[2], tab[3], tab[4]);
}

int afficherLettre(int tab[4]){
    for (int i = 0; i<4; i++){
        if (tab[i] == 1){
            printf("    P");
        }
        else if (tab[i] == 2){
            printf("    B");
        }
        else if (tab[i] == 3){
            printf("    M");
        }
        else if (tab[i] == 4){
            printf("    Y");
        }
        else if (tab[i] == 5){
            printf("     O");
        }
        else if (tab[i] == 6){
            printf("     G");
        }
    };
}
int verifRep(int tabRep[4], int secret[4]){
    for (int i = 0; i < 4; i++){
        if (tabRep[i] == secret[]){
            
        }
        if (tabRep[i] == secret[j]){

        }
    }
}

int afficherChiffre(int tab[4]){
    for (int i = 0; i<4; i++){
        if (tab[i] == "P"){
            printf("1");
        }
        else if (tab[i] == "B"){
            printf("2");
        }
        else if (tab[i] == "M"){
            printf("3");
        }
        else if (tab[i] == "Y"){
            printf("4");
        }
        else if (tab[i] == "O"){
            printf("5");
        }
        else if (tab[i] == "G"){
            printf("6");
        }
    };
}

int ecran(int tabRep[4], int tabMelange[4]){
    printf("--------------------------------|##|\n");
    printf("                                |%s%s|", tabMelange[1],tabMelange[2]);
    afficherLettre(tabRep);
    printf("|%s%s|", tabMelange[3],tabMelange[4]);
}

int rangementator(int tabRep[4]){
    int tabMelange[4];
    srand(time(NULL));
    for (int i = 0; i<4; i++){
        int hazard = rand() %4;
        if (tabMelange[hazard]){
            tabMelange[hazard] = tabRep[i];
        }else{
            i--;
        }
    };
    printf("%d", tabMelange);

}
// int verifier(int tab1[4], int tab2[4]){
//     for (int i = 0; i<4; i++){
//         if (tab1[i] != tab2[i]){
//             return 1;
//         }
//     };
// }


int main(){
    int secret[4];
    int reponse[4];

    generer(secret);
    saisir(reponse);
    afficherChiffre(reponse);
    verifRep();
    rangementator()
    afficherLettre(tableau1);
    saisir(tableau2);
    
    rangementator(tableau2);
    // saisir(tableau2);
    // afficher(tableau2);
    // if (verifier(tableau1, tableau2)){
    //     printf("code secret faux");
    // }else{
    //     printf("ok");
    // }

    system("pause");
    return 0;

}