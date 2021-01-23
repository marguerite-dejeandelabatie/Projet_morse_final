/*
Dans ce fichier :
void decodage(std::string chemin, int F_ECH, double DUREE):
    A partir d'un audio en morse, affiche à l'écran le message codé.
    Cette fonction utilise des fonctions auxiliaires (cf suivantes)

bool sequence0(int8_t audio[], int i, int longueur) :
    Un sous-tableau commençant à l'indice i et de longueur "longueur" est-il composé uniquement de zéros ?

void affichage(std::string chaine01) :
    Affiche à l'écran la traduction en clair d'une chaîne de 0 et 1 correspondant à du morse.
*/

bool sequence0(int8_t audio[], int i, int longueur){
    for(int k = 0; k < longueur; k++){
        if (audio[i+k] != 0){
            return false;
        }
    }
    return true;
}


void affichage(std::string chaine01){
    int taille = chaine01.length();
    int i = 0;
    while (i< taille){
        if (chaine01.substr(i, 4)== "0000"){
            std::cout<<' ';
            i = i+4;
        }
        else{

            int j = 0;
            while ((i+j< taille)&& (chaine01.substr(i+j,3) != "000")){ // On n'est pas encore arrivé à la fin du code du caractère
                j = j+1;
            }
            std::cout<<morse_to_char[chaine01.substr(i,j+3)];
            i = i+j+3;
        }
    };
    std::cout<<' '<<std::endl;
};


void decodage(std::string chemin, int F_ECH, double DUREE){
    std::ifstream audio(chemin, std::ios::binary);

    // On lit les 44 premiers octets (= l'en-tête) dont on n'a rien à faire
    int8_t p;
    audio.read(reinterpret_cast<char *>(&p), 44);

    int8_t tab[F_ECH];
    std::string chaine01 = "";

    while (!audio.eof()){
        audio.read(reinterpret_cast<char *>(&tab), DUREE*F_ECH);
        if (sequence0(tab, DUREE*F_ECH/4, DUREE*F_ECH/2)){ //Si la moitié du tableau vaut 0, cela suffit à dire qu'un 0 était codé !
            chaine01.append(1,'0');
        }
        else{
            chaine01.append(1,'1');
        }
    }
    affichage(chaine01);
}

