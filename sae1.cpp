#include <iostream>
#include <fstream>

using namespace std;

int main(){
    FILE *fichier = fopen("BD_INFOOKEA.csv", "r");
    char *ligne;
    if(fichier==NULL){
        exit(1);
    }

    while(fgets(ligne, 255, fichier) != NULL) {
        printf("\n%s", ligne);
    }

    return 0;
}
