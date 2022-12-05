#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ClientMax 200

typedef struct Client{
    char prenom[20];
    char nom[20];
    char pays[20];
    char code_dep[20];
    char jour_vacances[20];
    char age[20];
    char nb_personnes[20];
} Client;

int taille;

void afficheStruct(Client tableClient[ClientMax]) {
    for (int i = 0; i <= taille - 1; i++) {
        printf("\nPrenom : %s, Nom : %s, Age : %s, Jours de vacances : %s, Nb de personnes : %s, Pays : %s, Departement : %s",
        tableClient[i].prenom, tableClient[i].nom, tableClient[i].age, tableClient[i].jour_vacances, tableClient[i].nb_personnes,
        tableClient[i].pays, tableClient[i].code_dep);
    }    
}

void tableauCSV(Client tableauClient[ClientMax], int *taille){
    char delim[] = ",";
    FILE *fichier = fopen("BD_INFOOKEA.csv", "r");
    int c = 0, row = 0;
    char ligne[255];

    while(fgets(ligne, 254, fichier) != NULL){
        char *temp = strtok(ligne, delim);
        while(temp != NULL) {
            if(c == 0) {
                strcpy(tableauClient[row].prenom, temp);
            }
            if (c == 1) {
                strcpy(tableauClient[row].nom, temp);
            }
            if (c == 2) {
                strcpy(tableauClient[row].pays, temp);
            }
            if (c == 3) {
                strcpy(tableauClient[row].code_dep, temp);
            }
            if (c == 4) {
                strcpy(tableauClient[row].jour_vacances, temp);
            }
            if (c == 5) {
                strcpy(tableauClient[row].age, temp);
            }
            if (c == 6) {
                strcpy(tableauClient[row].nb_personnes, temp);
            }
            temp = strtok(NULL, delim);
            c++;
        }
        c = 0, row++;
    }

    *taille = row;
}

void recherche(Client table[ClientMax], char *nomSearch) {//fonction recherche
    for (int i = 0; i <= taille - 1; i++) {
        if(strcmp(table[i].nom, nomSearch) == 0) {
        printf("\nPrenom : %s, Nom : %s, Age : %s, Jours de vacances : %s, Nb de personnes : %s, Pays : %s, Departement : %s",
        table[i].prenom, table[i].nom, table[i].pays, table[i].jour_vacances, table[i].nb_personnes,
        table[i].age, table[i].code_dep);
        }
    }  
}

void AjouterClient(){//fonction pour ajouter un Client

    char AjoutSuppr;
    FILE *fichier = fopen("BD_INFOOKEA.csv", "a"); //ouvre le fichier
    char ligne[256];
    char delim[] = ",";
    int c = 0;
    int colonne = 0;
    char prenom[256], nom[256], age[256], jour_vacances[256], nb_personnes[256], pays[256], codedep[256];
    char all[]="all";

    printf("Entrez les informations du nouveau Client dans l'ordre: prenom, nom, age, pays, code de departement, jours au club, nombre de personnes dans la famille\n\n");
    scanf("%s %s %s %s %s %s %s", prenom, nom, age, pays, codedep, jour_vacances, nb_personnes);//l'user rentre les données qu'il veut injecter dans la base de donnée

    fprintf(fichier,"\n%s,%s,%s,%s,%s,%s,%s", prenom, nom, age, pays, codedep, jour_vacances, nb_personnes);//les données sont injectées dans la bd
    fclose(fichier);
}

void SupprClient(int IDChoisi){//fonction pour supprimer un Client
    FILE* fichier = fopen("BD_INFOOKEA.csv", "r");
    FILE* temp = fopen("temp.csv", "w");//créer un nouveau fichier temp
    int count = 1;
    char ligne[256];

    while (fgets(ligne, 255, fichier)) {
        if (count != IDChoisi) fputs(ligne, temp);//copie la ligne tant que celle qui doit etre supprimée n'est pas rencontrée
        count++;
    }

    fclose(fichier);
    fclose(temp);
    //ecrase le fichier bd de base et le renomme
    remove("BD_INFOOKEA.csv");
    rename("temp.csv", "BD_INFOOKEA.csv");

}


int main(){
    int choix;
    int IDChoisi;
    char all[]="all";

    Client tableauClient[ClientMax];

    tableauCSV(tableauClient, &taille);

    //afficheStruct(tableauClient);

    //recherche(tableauClient, "Mastu");

    printf("Que voulez-vous faire ?\n\n");
    //menu choix
    printf("0. Afficher toute la base de donnee\n");
    printf("1. Ajouter un Client\n");
    printf("2. Supprimer un Client\n");
    printf("3. Rechercher un Client\n");

    scanf("%d", &choix);

    if(choix==0){
        afficheStruct(tableauClient);
    }

    if(choix==1){
        AjouterClient();
    }

    if(choix==2){
        printf("Qui voulez-vous supprimer ?");
        scanf("%d", &IDChoisi);
        SupprClient(IDChoisi);
    }

    if(choix==3){
        char nom[30];
        printf("Nom:\t");
        scanf("%s", nom);
        recherche(tableauClient, nom);
    }
    printf("\n") ;
    return 0;
}