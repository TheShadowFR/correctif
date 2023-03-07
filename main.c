#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void copyArray(int tab[9][9], int copy[9][9]){
    for(int i = 0;i < 9; i++){
        for(int j = 0;j < 9; j++){
            copy[j][i] = tab[j][i];
        }
    }
}
// Ce lien vous sera utile : https://www.geeksforgeeks.org/pass-2d-array-parameter-c/
void afficher(int tab[9][9]){
    
    printf("| Y\\X ");
    for(int i = 0; i<9; i++){
        printf("| %d ", i);
    }
    printf("\n");
    for(int i = 0; i < 10; i++){
        printf("----");
    }
    for(int i = 0; i < 9; i++){
        printf("\n");
        printf("| %d > ", i);
        for(int j= 0; j < 9; j++)  {
            printf("| %d ", tab[i][j]);
        }

        printf("|\n");
    }
    printf("\n");
}

/*
Écrire la fonction verifierLigneColonne() qui prend en paramètre un numéro et un sens (HORIZ ou VERT)
qui vérifie que la ligne ou la colonne (suivant les cas) numéro est bien remplie.
On pourra utiliser un tableau intermédiaire pour vérifier cela. La fonction retournera 1 si tout s’est bien passé, 0 sinon.
 Les constantes HORIZ de valeur 0 et VERT de valeur 1 sont à définir.
*/
int verifierLigneColonne(int tab[9][9], int ligne, int ligneOrCol){
    int result = 0;
    int choices[9]= {0,0,0, 0,0,0, 0,0,0};

    if(ligneOrCol){
        for(int i = 0; i <9; i++){
            int numero = tab[ligne][i];
            if(numero){
                choices[numero - 1] = choices[numero -1 ] + 1;
            }
        }
    } else {
        for(int i = 0; i <9; i++){
            int numero = tab[i][ligne];
            if(numero){
                choices[numero - 1] = choices[numero -1 ] + 1;
            }
        }
    }
    for(int i = 0; i< 9; i++){
        if(choices[i] > 1 ){
            result = 1;
        }
    }
    return result;
}

int verifRegion(int tab[9][9]){
    //A TERMINER
}

//Écrire la fonction verifierGrille() qui renvoie 1 si la grille est correctement remplie et 0 sinon

int verifierGrille(int tab[9][9]){
    int isCorrect = 1;
    for(int i = 0; i < 9; i++){
        int verifCol = verifierLigneColonne(tab, i, 0);
        int verifLigne = verifierLigneColonne(tab, i, 1);
        int verifRegion = verifRegion(tab, i);
        if(verifCol || verifLigne){
            printf("\n\nAhrf, il semblerait que votre solution ne corresponde pas aux regles, reessayez !\n\n");
        isCorrect = 0;
        }
    }

    //faire la fonction  Verifier Region et l'implémenter ici

    return isCorrect;
}
// Ecrire la fonction generer(), elle prend en paramètre la grille et renvoie le nombre d'éléments non nuls
int generer(int tab[9][9], int copy[9][9]){
    int nbToFind = 0;
    for(int i = 0; i <9; i++){
        for(int j = 0; j <9; j++){
            if((rand() % 2)){
                nbToFind++;
                copy[i][j] = tab[i][j];
            }
        }
    }
    return nbToFind;
}

/*Écrire une fonction saisir() qui demande à l’utilisateur de saisir au clavier les indices i et j et la valeur v à placer à l’emplacement (i,j).
La fonction doit vérifier la validité des indices et de la valeur.
Si la case n’est pas occupée, la valeur doit être placée dans la grille. remplissage est alors incrémentée*/
int saisir(int tab[9][9]){
    int result = 0;
    
    while(result != 1){
        int saisie = 0;

        int tabeauTemporaire[9][9] = {
            {0,0,0, 0,0,0, 0,0,0},
            {0,0,0, 0,0,0, 0,0,0},
            {0,0,0, 0,0,0, 0,0,0},
            
            {0,0,0, 0,0,0, 0,0,0},
            {0,0,0, 0,0,0, 0,0,0},
            {0,0,0, 0,0,0, 0,0,0},
            
            {0,0,0, 0,0,0, 0,0,0},
            {0,0,0, 0,0,0, 0,0,0},
            {0,0,0, 0,0,0, 0,0,0}

        };
        copyArray(tab, tabeauTemporaire);

        printf("Veuillez saisir un Y");
        scanf("%d", &saisie);
        int saisieX = saisie;
        printf("Veuillez saisir un X");
        scanf("%d", &saisie);
        int saisieY = saisie;


        if(tab[saisieX][saisieY]){
            printf("Cette case est deja remplie Reessayez\n");
        } else {
            printf("Quelle valeur souhaitez vous inserer ?\n");
            scanf("%d", &saisie);
            int saisieVal = saisie;
            tabeauTemporaire[saisieX][saisieY] = saisieVal;
            result = verifierGrille(tabeauTemporaire);
            if(result){
                tab[saisieX][saisieY] = saisieVal;
            }
        }
    }
    return result;
}

int verifGagnant(int tab[9][9]){
    int inconnu = 0;
    for(int i = 0; i < 9; i++){
        for(int j= 0; j < 9; j++){
            if (tab[i][j] == 0){
                inconnu++;
            }
        }
    }
    if (inconnu > 0){
        return 1;
    }else{
        return 0;
    }
}
/*
Écrire la fonction verifierRegion() qui prend en paramètre deux indices k et l qui correspondent à la région (k,l)
et qui renvoie 1 si la région est correctement remplie, 0 sinon.
*/


//Écrire le programme principal, en supposant que la seule condition d’arrêt est la réussite du sudoku (ce test ne devra être fait que si nécessaire)

int main(){
// Ne pas toucher le code entre les commentaires
    srand( time( NULL ) );


    int i, j, k;
    int solution[9][9];
    printf("SOLUTION");  
    printf("\n");  
    printf("---------------------------------");  
    printf("\n");  
    for(j=0;j<9; ++j) 
    {
    for(i=0; i<9; ++i)
        solution[j][i] = (i + j*3 +j /3) %9 +1 ; 
    }
    
    for(i=0;i<9; ++i) 
    {
    for(j=0; j<9; ++j)
        printf("%d ", solution[i][j]);
    printf("\n");  
    }
    printf("---------------------------------");  
    printf("\n");  
    //toucher le code entre les commentaires
    int tableauJoueur[9][9] = {
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},
        
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},
        
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0}

    };

    int isTurning = 0;
    generer(solution,tableauJoueur);
    do{
    saisir(tableauJoueur);
    afficher(tableauJoueur);
    isTurning = verifGagnant(tableauJoueur);// Retour d'une fonction qui renvoi 1 si tableau joueur 
    //Comporte un ou des 0
    } while(isTurning);
    //Ne pas toucher au code ci dessous
    system("pause");
    return 0;
    }