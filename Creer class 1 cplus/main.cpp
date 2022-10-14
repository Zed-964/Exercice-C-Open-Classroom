#include <iostream>
#include "Personnage.h"

using namespace std;

int main()
{
    Personnage david;
    Personnage goliath("goliath","Epée aiguisée", 20), inconus("inconus","Baton magique cheater", 0); // Création de 3 objets de type Personnage

    goliath.attaquer(david);
    david.boirePotionDeVie(20);
    goliath.attaquer(david);
    david.attaquer(goliath);

    goliath.changerArme("Double hache tranchante vénéneuse de la mort", 40);
    goliath.attaquer(david);

    cout << "David" << endl;
    david.afficherEtat();
    cout << "Goliath" << endl;
    goliath.afficherEtat();

    cout << "Inconus joint la bataille" << endl;
    inconus.sortNom();
    inconus.attaquerMagie(goliath);

    cout << "inconus" << endl;
    inconus.afficherEtat();
    cout << "Goliath" << endl;
    goliath.afficherEtat();

    inconus.boirePotionDeMana(50);
    goliath.boirePotionDeVie(50);

    inconus.changerSort("BouleDeFeu","feu",30,30);
    inconus.sortNom();
    cout << endl;
    inconus.attaquerMagie(goliath);
    cout << "Goliath" << endl;
    goliath.afficherEtat();

    inconus.changerSort("Blizzrad","glace",50,60);
    inconus.sortNom();
    cout << endl;
    inconus.attaquerMagie(goliath);
    cout << "Inconus" << endl;
    inconus.afficherEtat();
    cout << "Goliath" << endl;
    goliath.afficherEtat();


    return 0;
}
