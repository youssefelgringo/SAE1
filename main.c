#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*typedef struct Client{
    char prenom[256];
    char nom[256];
    char age[256];
    char jour_vacances[256];
    char nb_personnes[256];
    char pays[256];
    char codedep[256];
}client;*/

void recherche(char *nom_a_rechercher) {//fonction recherche
    char AjoutSuppr;
    FILE *fichier = fopen("BD_INFOOKEA.csv", "r"); //ouvre le fichier en read-only
    char ligne[255];
    char delim[] = ",";//lors de l'affichage, ça enlève les ',' et le remplace par un espace
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
        if ((strcmp(nom, nom_a_rechercher) == 0) || (strcmp(nom_a_rechercher, "all")) == 0) {//affiche soit une personne recherchée soit toute la base
            printf("\n %d %s %s %s %s %s %s %s", colonne, prenom, nom, pays, codedep, jour_vacances, age, nb_personnes);
        }
        colonne += 1 ;
    }

}

void AjouterClient(){//fonction pour ajouter un client

    char AjoutSuppr;
    FILE *fichier = fopen("BD_INFOOKEA.csv", "a"); //ouvre le fichier
    char ligne[256];
    char delim[] = ",";
    int c = 0;
    int colonne = 0;
    char prenom[256], nom[256], age[256], jour_vacances[256], nb_personnes[256], pays[256], codedep[256];
    char all[]="all";

    printf("Entrez les informations du nouveau client dans l'ordre: prenom, nom, age, pays, code de departement, jours au club, nombre de personnes dans la famille\n\n");
    scanf("%s %s %s %s %s %s %s", prenom, nom, age, pays, codedep, jour_vacances, nb_personnes);//l'user rentre les données qu'il veut injecter dans la base de donnée

    fprintf(fichier,"\n%s,%s,%s,%s,%s,%s,%s", prenom, nom, age, pays, codedep, jour_vacances, nb_personnes);//les données sont injectées dans la bd
    fclose(fichier);
    recherche(all);//affiche la bd
}

void SupprClient(int IDChoisi){//fonction pour supprimer un client
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

    printf("Que voulez-vous faire ?\n\n");
    //menu choix
    printf("0. Afficher toute la base de donnee\n");
    printf("1. Ajouter un client\n");
    printf("2. Supprimer un client\n");
    printf("3. Rechercher un client\n");

    scanf("%d", &choix);

    if(choix==0){
        recherche(all);
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
        recherche(nom);
    }
    printf("\n") ;
    return 0;
}