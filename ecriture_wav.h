/*
Dans ce fichier :
Définition de l'en-tête d'un fichier .wav;

int ecriture_wav(int F_ECH):
  A partir d'un fichier binaire dans lequel est codé le son que l'on souhaite écouter, écriture d'un fichier .wav (ajout de l'en-tête)

*/

typedef struct WAV_HEADER {
    char RIFF[4] = {'R','I','F','F'};
    uint32_t size = fsize + 36;
    char WAVE[4] = {'W','A','V','E'};
    char fmt[4] = {'f','m','t',' '};
    uint32_t s1 = 16;
    uint16_t format = 1;
    int16_t mono = 1;
    uint32_t frequence;
    uint32_t bit_par_sec;
    uint16_t s2 = 2;
    uint16_t bit_par_echantillon = 8;
    char data[4] = {'d', 'a', 't', 'a'};
    uint32_t fsize;
} wav_hdr;

int ecriture_wav(int F_ECH){
  uint32_t frequence = F_ECH;

  std::ifstream binaire("binaire.bin", std::ifstream::binary);

  // Taille du fichier binaire
  uint32_t fsize = binaire.tellg();
  binaire.seekg(0, std::ios::end);
  fsize = (uint32_t)binaire.tellg() - fsize;
  binaire.seekg(0, std::ios::beg);


  wav_hdr wav;
  wav.frequence = frequence;
  wav.bit_par_sec = frequence;

  std::ofstream audio("audio.wav", std::ios::binary);
  audio.write(reinterpret_cast<const char *>(&wav), sizeof(wav));

  // On recopie les données du fichier binaire dans le fichier .wav
  int16_t p;
  for (int i = 0; i < fsize; ++i) {
    binaire.read(reinterpret_cast<char *>(&p), 1);
    audio.write(reinterpret_cast<char *>(&p), 1);
  }

  return 0;}