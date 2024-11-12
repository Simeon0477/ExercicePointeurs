#include <string>
#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "../header/array.h"
#include "../header/pendu.h"

using namespace std;

/*
Pour ce jeu de pendu, nous avons décidé de laisser 8 chances aux joueurs 
*/

const char *words[] = {"chien", "manger", "fleur", "voiture", "etoile", "jardin", "papillon", "montagne", "bateau", "musique"};
int nb_chance = 0;
string choix;
char rejouer;

void hanged(){
    srand(time(NULL));

    while(true){
        cout << "** JEU DU PENDU ** \n\n";
        cout << "Que voulez vous faire ? \n";
        cout << " 1 - faire une partie \n";
        cout << " 2 - quitter \n\n";
        cout << " Votre choix -> ";
        cin >> choix;
        clear();

        if(choix == "1"){
            char lettre;
            int ind_word = rand()%10;
            int lenght = longueur(words[ind_word]);
            char guess_word[lenght];

            for(int i=0; i < lenght; i++){
                guess_word[i] = '_';
            }

            while(true){
                clear();
                guess_word[lenght] = '\0';

                cout << "Voici le mot : \n";
                cout << guess_word << "\n";

                cout << "Quelle lettre choississez vous? \n";
                cout << "Joueur ->";
                cin >> lettre;
                if(lettre >= 'A' && lettre <= 'Z'){
                    lettre += ('a' - 'A');
                }

                if(search_char(guess_word, words[ind_word], lettre) == 1){
                    cout << "Vous avez reussi \n";
                    cout << "Voici votre évolution : " << guess_word << "\n";

                    if(chercher_char(guess_word, '_') == NULL){
                        cout << "\n Vous avez gagner !!!! \n\n";
                        cout << "Voulez vous rejouer? (o/n) : ";
                        cin >> rejouer;
                        if(rejouer == 'o'){
                            initialisation(guess_word, ind_word, lenght);
                            continue;
                        }else{
                            exit(0);
                        }
                    }
                }else
                if(search_char(guess_word, words[ind_word], lettre) != 1){
                    nb_chance += 1;

                    cout << "Vous avez raté \n";
                    cout << "Il ne vous reste plus que : " << 8 - nb_chance << " chances \n";

                    draw_hanged(nb_chance);

                    if(nb_chance == 8){
                        cout << "\n Vous avez perdu !!!! \n\n";
                        draw_hanged(nb_chance);
                        cout << "Voulez vous rejouer? (o/n) : ";
                        cin >> rejouer;
                        if(rejouer == 'o'){
                            initialisation(guess_word, ind_word, lenght);
                            continue;
                        }else{
                            exit(0);
                        }
                    }
                }
                clear();
            }
        }else
        if(choix == "quitter"){
            break;
        }
        

    }
}   

void clear(){
    #ifdef _WIN32
        system("CLS");
    #else
        system("clear");
    #endif
}

int search_char(char *dest, const char *chaine, char caractere){
    int i=0;
    int temoin = 0;

    while(dest[i] != '\0'){
        if(chaine[i] == caractere){
            dest[i] = caractere;
            temoin = 1;
        }
        i++;
    }

    return temoin;
}

void initialisation(char *dest, int indice, int lenght){
    indice = rand()%10;

    for(int i=0; i < lenght; i++){
        dest[i] = '_';
    }
}

void draw_hanged(int chance){
    if(chance == 1){
        cout << "\n\n"
             << " |"
             << " |"
             << " |"
             << " |"
             << " |"
             << " |"
             << "_____\n\n";
    }else
    if(chance == 2){
        cout << "\n ____\n"
             << " |"
             << " |"
             << " |"
             << " |"
             << " |"
             << " |"
             << "_____\n\n";
    }else
    if(chance == 3){
        cout << "\n ____\n"
             << " |   |"
             << " |"
             << " |"
             << " |"
             << " |"
             << " |"
             << "_____\n\n";
    }else
    if(chance == 4){
        cout << "\n ____\n"
             << " |   |"
             << " |   o"
             << " |"
             << " |"
             << " |"
             << " |"
             << "_____\n\n";
    }else
    if(chance == 5){
        cout << "\n ____\n"
             << " |   |"
             << " |   o"
             << " |  / \\"
             << " |"
             << " |"
             << " |"
             << "_____\n\n";
    }else
    if(chance == 6){
        cout << "\n ____\n"
             << " |   |"
             << " |   o"
             << " |  /|\\"
             << " |"
             << " |"
             << " |"
             << "_____\n\n";
    }else
    if(chance == 7){
        cout << "\n ____\n"
             << " |   |"
             << " |   o"
             << " |  /|\\"
             << " |  /"
             << " |"
             << " |"
             << "_____\n\n";
    }else
    if(chance == 2){
        cout << "\n ____\n"
             << " |   |"
             << " |   o"
             << " |  /|\\"
             << " |  / \\"
             << " |"
             << " |"
             << "_____\n\n";
    }
}