/*
Dans ce fichier :
void codage(std::string message, int F_ECH, double DUREE):
    A partir d'une chaîne de caractères, écrit un audio contenant ce message en morse.
    Cette fonction utilise des fonctions auxiliaires (cf suivantes)

void generer_signal(double duree, double frequence, double F_ECH, FILE* binaire) :
    Ecrit dans un fichier une onde sinusoïdale de fréquence "fréquence", sur duree*F_ECH valeurs

void ecrire_bin_char(std::string* morse, FILE* binaire, int F_ECH, double DUREE) :
    Transformation d'un signal morse (chaîne de 0 et de 1) en signal sonore correspondant.
*/

void generer_signal(double duree, double frequence, double F_ECH, FILE* binaire){
    double dt = 1/F_ECH;
    for(int i = 0; i< duree*F_ECH; i++){
        uint8_t amplitude = 8*sin(2*M_PI*frequence*i*dt); 
        fwrite(&amplitude, 1,1,binaire);
    }
}

void ecrire_bin_char(std::string* morse, FILE* binaire, int F_ECH, double DUREE){
    int taille = (*morse).length();
    int compteur = 1;
    for(int i=1; i< taille; i++){
        if ((*morse)[i] == (*morse)[i-1]){
            compteur += 1;
        }
        else{
            generer_signal(DUREE*compteur, 440*(*morse)[i-1]-21120, F_ECH, binaire);
            compteur = 1;
        }
    }
    generer_signal(DUREE*compteur, 440*(*morse)[taille-1]-21120, F_ECH, binaire);
}

void codage(std::string message, int F_ECH, double DUREE){
    FILE* binaire = fopen("binaire.bin", "wb");
    

    for(char i : message){
        int ascii = i;
        int ind = indice(ascii);
        ecrire_bin_char(&nb_to_morse[ind], binaire, F_ECH, DUREE); 
    }
    ecriture_wav(F_ECH);
}