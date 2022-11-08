#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    char *AjoutSuppr;
    FILE *fichier = fopen("BD_INFOOKEA.csv", "r");
    char *ligne;
    if(fichier==NULL){
        exit(1);
    }

    while(fgets(ligne, 255, fichier) != NULL) {
        //printf("\n%s", ligne);
        cout<<ligne<<endl;
    }

    /*do{
        cout<<"Voulez-vous ajouter ou supprimer un client ? [A/S]"<<endl;
        cin>>AjoutSuppr;
    }while((strcmp(AjoutSuppr, "S") != 1) || (strcmp(AjoutSuppr, "s") != 1) || (strcmp(AjoutSuppr, "A") != 1) || (strcmp(AjoutSuppr, "a") != 1));*/

    cout<<"Voulez-vous ajouter ou supprimer un client ? [A/S]"<<endl;
    cin>>*AjoutSuppr;
    cout<<*AjoutSuppr;


    return 0;
}
