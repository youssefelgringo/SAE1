#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

typedef struct client{
    string prenom;
    string nom;
    string age;
    string pays;
    string Code_dep;
    string j_au_club;
    string nb_personne_F;
};

int main(){
    char AjoutSuppr;
    client personne;
    FILE *fichier = fopen("BD_INFOOKEA.csv", "r"); //ouvre le fichier en read-only
    char *ligne;

    if(fichier==NULL){
        exit(1);
    }

    while(fgets(ligne, 255, fichier) != NULL) { //affiche le fichier dans la console
        cout<<ligne<<endl;
    }

    do{ //demande à l'utilisateur s'il veut ajouter ou supprimer un client
        cout<<"Voulez-vous ajouter ou supprimer un client ? [A/S]"<<"\t";
        cin>>AjoutSuppr;
    }while((AjoutSuppr != 'S') && (AjoutSuppr != 's') && (AjoutSuppr != 'A') && (AjoutSuppr != 'a')); //il faut que le user saisisse soit S/s soit A/s

    if((AjoutSuppr=='A' || AjoutSuppr=='a')){ //Entre toutes les données à saisir dans le csv à propos du client
        cout<<"Quel est le prénom du client ?"<<endl;
        cin>>personne.prenom;
        cout<<"Quel est le nom du client ?"<<endl;
        cin>>personne.nom;
        cout<<"De quel pays provient-il ?"<<endl;
        cin>>personne.pays;
        cout<<"Quel est son code de département ?"<<endl;
        cin>>personne.Code_dep;
        cout<<"Depuis combien de temps est-il au club ?"<<endl;
        cin>>personne.j_au_club;
        cout<<"Quel est son age ?"<<endl;
        cin>>personne.age;
        cout<<"Combien de personnes a-t-il dans sa famille ?"<<endl;
        cin>>personne.nb_personne_F;

        string eee = {/*ID,",",*/personne.prenom,",",personne.nom,",",personne.pays,",",personne.Code_dep,",",personne.j_au_club,",",personne.age,",",personne.nb_personne_F}
    }
    return 0;
}
