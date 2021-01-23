Exécuter le main (g++ main.cpp puis ./a/out), sans argument
Suivez les instructions

Pour coder un message :
Le message texte peut être fourni sous forme de chaîne de caractère ou lu dans un fichier texte (ASCII)
L'audio renvoyé s'appelle "audio.wav" et est enregistré dans le dossier courant.
Il est possible de changer la fréquence d'échantillonnage et la durée d'un "symbole" morse dans les variables globales au début du fichier "main.cpp".
Chaque amplitude est codée sur 1 octet.

Les caractères pris en charges sont :
- les chiffres de 1 à 9
- les minuscules et majuscules non accentuées
- les caractères de ponctuation suivants :
        - Espace
        - Point d'exclamation
        - Guillement
        - Apostrophe
        - Parenthèse ouvrante
        - Parenthèse fermante
        - Plus
        - Virgule
        - Tiret
        - Point
        - Deux points
        - Point virgule
        - Egal
        - Point d'interrogation


Pour décoder un message :
La fréquence d'échantillonnage et le durée d'un "symbole" morse sont définies dans le fichier main (hypothèse de décodage de fichiers codés avec mon algorithme ou modification possible de ces constantes dans le code. Possibilité de les demander sinon à l'utilisateur...)