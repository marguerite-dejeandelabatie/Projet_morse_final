#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <map>

#include "conv_en_morse.h"
#include "ecriture_wav.h"
#include "map_morse_to_char.h"
#include "codage.h"
#include "decodage.h"

double DUREE = 0.2;
int F_ECH = 8000;


int main(){
    std::cout <<"Vous désirez :"<<std::endl;
    std::cout<<"Coder : tapez 1"<<std::endl;
    std::cout <<"Décoder : tapez 2"<<std::endl;
    char action;
    std::cin >> action;
    if (action == '1'){
        std::cout <<"Votre message est :"<<std::endl;
        std::cout<<"Dans un fichier (sur une seule ligne) : tapez 1"<<std::endl;
        std::cout <<"Une chaîne de caractère : tapez 2"<<std::endl;

        char source;
        std::cin >> source;
        
        std::string message;

        if(source == '1'){
            std::cout<<"Entrez le chemin vers ce fichier."<<std::endl;
            std::string chemin;
            std::cin >> chemin;
            std::ifstream fichier_source;
            fichier_source.open(chemin);
        
            getline(fichier_source, message);
        }
        
        else{
            std::cout<<"Tapez votre message."<<std::endl;
            std::cin.ignore( 10, '\n' );
            std::getline(std::cin, message);
        }

        std::cout<<"Codage en cours..."<<std::endl;
        codage(message, F_ECH, DUREE);
    }
    else{
        std::cout<<"Entrez le chemin vers le fichier audio."<<std::endl;
        std::string chemin;
        std::cin>>chemin;
        std::cout<<"Décodage en cours..."<<std::endl;
        decodage(chemin, F_ECH, DUREE);
    }
}