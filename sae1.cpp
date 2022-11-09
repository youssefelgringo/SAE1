#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <string>
#include <bits/stdc++.h>

using namespace std;

const char* conversionPrenomChar(string Prenom){
    //const char* PrenomChar=Prenom.c_str();
    char PrenomChar[Prenom.length()+1];
    strcpy(PrenomChar, Prenom.c_str());

    return PrenomChar;
}

const char* conversionNomChar(string Nom){
    //const char* NomChar=Nom.c_str();
    char NomChar[Nom.length()+1];
    strcpy(NomChar, Nom.c_str());

    return NomChar;
}

const char* conversionPaysChar(string Pays){
    //const char* PaysChar=Pays.c_str();
    char PaysChar[Pays.length()+1];
    strcpy(PaysChar, Pays.c_str());

    return PaysChar;
}

const char* conversionNomChar(int Code_dep){
    char Nomchar;
    sprintf(NomChar, "%d", Code_dep);

    return NomChar;
}

int main(){
    char AjoutSuppr;
    string Nom, Prenom, Pays;
    int Code_dep, j_au_club, age, nb_personnes_famille, ID;
    string infookea="BD_INFOOKEA.csv";
    FILE *fichier = fopen("BD_INFOOKEA.csv", "r");
    char *ligne;

    if(fichier==NULL){
        exit(1);
    }

    while(fgets(ligne, 255, fichier) != NULL) {
        //printf("\n%s", ligne);
        cout<<ligne<<endl;
    }

    do{
        cout<<"Voulez-vous ajouter ou supprimer un client ? [A/S]"<<"\t";
        cin>>AjoutSuppr;
    }while((AjoutSuppr != 'S') && (AjoutSuppr != 's') && (AjoutSuppr != 'A') && (AjoutSuppr != 'a'));

    if((AjoutSuppr=='A' || AjoutSuppr=='a')){
        cout<<"Quel est le prénom du client ?"<<endl;
        cin>>Prenom;
        cout<<"Quel est le nom du client ?"<<endl;
        cin>>Nom;
        cout<<"De quel pays provient-il ?"<<endl;
        cin>>Pays;
        cout<<"Quel est son code de département ?"<<endl;
        cin>>Code_dep;
        cout<<"Depuis combien de temps est-il au club ?"<<endl;
        cin>>j_au_club;
        cout<<"Quel est son age ?"<<endl;
        cin>>age;
        cout<<"Combien de personnes a-t-il dans sa famille ?"<<endl;
        cin>>nb_personnes_famille;

        //ID=

        const char* PrenomCharMain=conversionPrenomChar(Prenom);
        const char* NomCharMain=conversionNomChar(Nom);
        const char* PaysCharMain=conversionPaysChar(Pays);
        
        //conversionStringChar(Nom, Prenom, Pays);

        const char* client[8][300]={PrenomCharMain, NomCharMain, PaysCharMain, Code_dep, j_au_club, age, nb_personnes_famille};
        cout<<client;
        
        //fprintf(fichier, )
        
    }

    return 0;
}
