#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;



int main(){
    char AjoutSuppr;
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

    if((AjoutSuppr=='A' || AjoutSuppr=='a'){
        fichier.fprint("oui");
    }

    return 0;
}
