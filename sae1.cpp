#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

char* AjoutSuppr;

int main(){
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
        cout<<"Voulez-vous ajouter ou supprimer un client ? [A/S]"<<endl;
        cout<<&AjoutSuppr;
        cin>> *AjoutSuppr;
        cout<<&AjoutSuppr;
    }while((strcmp(AjoutSuppr, "S") == 0) || (strcmp(AjoutSuppr, "s") == 0) || (strcmp(AjoutSuppr, "A") == 0) || (strcmp(AjoutSuppr, "a") == 0));
    //while((AjoutSuppr != 'S') || (AjoutSuppr != 's') ||(AjoutSuppr != 'A') ||(AjoutSuppr != 'a'));
    /*cout<<"Voulez-vous ajouter ou supprimer un client ? [A/S]"<<endl;
    cin>>AjoutSuppr;
    cout<<AjoutSuppr;*/


    return 0;
}
