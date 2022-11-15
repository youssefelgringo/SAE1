#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recherche(char *nom_a_recherche) {
    char AjoutSuppr;
    FILE *fichier = fopen("BD_INFOOKEA.csv", "r"); //ouvre le fichier en read-only
    char ligne[255];
    char delim[] = ",";
    int c = 0;
    int colonne = 0 ;
    char prenom[256], nom[256], age[256], jour_vacances[256], nb_personnes[256], pays[256], codedep[256];

    if(fichier==NULL){
        exit(1);
    }

    while(fgets(ligne, 254, fichier) != NULL) { //affiche le fichier dans la console
        char *ptr = strtok(ligne, delim);
        while(ptr != NULL) {
            if(c == 0) {
                strcpy(prenom, ptr);
            }
            if (c == 1) {
                strcpy(nom, ptr);
            }
            if (c == 2) {
                strcpy(pays, ptr);
            }
            if (c == 3) {
                strcpy(codedep, ptr);
            }
            if (c == 4) {
                strcpy(jour_vacances, ptr);
            }
            if (c == 5) {
                strcpy(age, ptr);
            }
            if (c == 6) {
                strcpy(nb_personnes, ptr);
            }
            ptr = strtok(NULL, delim);
            c++;
        }

        c = 0 ;
        if (strcmp(nom, nom_a_recherche) == 0) {
            printf("\n %d %s %s %s %s %s %s %s", colonne, prenom, nom, pays, codedep, jour_vacances, age, nb_personnes);
        } else if (strcmp(nom_a_recherche, "all") == 0) {
            printf("\n %d %s %s %s %s %s %s %s", colonne, prenom, nom, pays, codedep, jour_vacances, age, nb_personnes);
        }
        colonne += 1 ;
    }

}

void AjouterClient(){

    char AjoutSuppr;
    FILE *fichier = fopen("BD_INFOOKEA.csv", "a"); //ouvre le fichier
    char ligne[256];
    char delim[] = ",";
    int c = 0;
    int colonne = 0;
    char prenom[256], nom[256], age[256], jour_vacances[256], nb_personnes[256], pays[256], codedep[256];

    printf("Entrez les informations du nouveau client dans l'ordre: prenom, nom, age, pays, code de departement, jours au club, nombre de personnes dans la famille\n\n");
    scanf("%s %s %s %s %s %s %s", prenom, nom, age, pays, codedep, jour_vacances, nb_personnes);

    fprintf(fichier,"\n%s,%s,%s,%s,%s,%s,%s", prenom, nom, age, pays, codedep, jour_vacances, nb_personnes);
    fclose(fichier) ;
    recherche("all");
}

void SupprClient(){

    char AjoutSuppr;
    FILE *fichier = fopen("BD_INFOOKEA.csv", "a"); //ouvre le fichier
    char ligne[256];
    char delim[] = ",";
    int c = 0;
    int colonne = 0;
    char prenom[256], nom[256], age[256], jour_vacances[256], nb_personnes[256], pays[256], codedep[256];



}

int main(){

    int choix;

    printf("Que voulez-vous faire ?\n\n");

    printf("0. Afficher toute la base de donnee\n");
    printf("1. Ajouter un client\n");
    printf("2. Supprimer un client\n");
    printf("3. Rechercher un client\n");

    scanf("%d", &choix);

    if(choix==0){
        recherche("all");
    }

    if(choix==1){
        AjouterClient();
    }

    /*char *recherche
    printf("Nom: ");
    scanf*/

    //recherche("0");
    printf("\n") ;
    return 0;
}
