/*
Dans ce fichier :
Tableau contenant les écritures en morse de différents caractères.

int indice(int ascii):
    Associe au code ASCII d'un caractère son indice dans le tableau précédent.

std::pair<bool, int> contient(std::vector<int> tab, int x):
    Retourne si l'élément x appartient à tab et, si oui, également son indice (utilisé dans la fonction indice)
*/

std::pair<bool, int> contient(std::vector<int> tab, int x){
    int indice = 0;
    for(int elmt : tab){
        if (elmt == x){
            return (std::pair<bool, int> (true, indice));
        }
        indice++;
    }
    return (std::pair<bool, int> (false, 0));
}

int indice(int ascii){
    int i;
    std::vector<int> carac_spec = {32,33,34,39,40,41,43,44,45,46,58,59,61,63}; // [' ', !,", ' , ( , ) , + , ',' , -, ., :, ; , =, ?]
    std::pair<bool, int> couple = contient(carac_spec,ascii);

    if (couple.first){
        int tab_indices[14] = {36,37,38,39,40,41,42,43,44,45,46,47,48,49};
        i = tab_indices[couple.second];
    }

    else if ((ascii >= 48) && (ascii <= 57)){
        i = ascii - 48; // chiffres : 10 1ères cases du tableau
    }
    else if ((ascii >= 65) && (ascii <= 90)){
        i = ascii - 65 + 10; // majuscules après les chiffres (et ascii(A)=65)
    }
    else if ((ascii >= 97) && (ascii <= 122)){
        i = ascii - 97 + 10; // minuscules codées comme majuscules
    }
    else{
        char c = ascii;
        std::cout << "Erreur ! Caractère '"<<c<< "' ne possède pas d'équivalent en morse."<<std::endl;
        std::cout << "Il sera codé par '?'."<<std::endl;
        i = 49;
    }

    return i;
};


    // Tableau de conversion des lettres en "morse" wav

std::string nb_to_morse[50] = {

    // Chiffres de 0 à 9
    "1110111011101110111000", //0
    "10111011101110111000",
    "101011101110111000",
    "1010101110111000",
    "10101010111000",
    "101010101000",
    "11101010101000",
    "1110111010101000",
    "111011101110101000",
    "11101110111011101000", //9

    // Lettres
    "10111000", //A
    "111010101000", //B
    "11101011101000", //C
    "1110101000", //D
    "1000", //E
    "101011101000", //F
    "111011101000", //G
    "1010101000", //H
    "101000", //I
    "1011101110111000", //J
    "111010111000", //K
    "101110101000", //L
    "1110111000", //M
    "11101000", //N
    "11101110111000", //O
    "10111011101000", //P
    "1110111010111000", //Q
    "1011101000", //R
    "10101000", //S
    "111000", //T
    "1010111000", //U
    "101010111000", //V
    "101110111000", //W
    "11101010111000", //X
    "1110101110111000", //Y
    "11101110101000", //Z


    //Caractères spéciaux et ponctuation
    "0000", //Espace
    "1110101110101110111000",//Point d'exclamation
    "101110101011101000", //Guillement
    "1011101110111011101000",//Apostrophe
    "111010111011101000", //Parenthèse ouvrante
    "1110101110111010111000",//Parenthèse fermante
    "1011101011101000", //Plus
    "1110111010101110111000", //Virgule
    "111010101010111000",//Tiret
    "10111010111010111000", //Point
    "11101110111010101000",//Deux points
    "11101011101011101000",//Point virgule
    "1110101010111000",//Egal
    "101011101110101000" //Point d'interrogation
};