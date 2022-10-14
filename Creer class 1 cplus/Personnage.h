#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <string>
#include "Arme.h"
#include "Sort.h"

class Personnage
{
    public:

    Personnage(); // constructeur
    Personnage(std::string nom, std::string nomArme, int degatsArme);
    Personnage(std::string nom, int vie, int mana);
    ~Personnage();
    void recevoirDegats(int nbDegats);
    void recevoirMagie(int nbDegats);
    void utileMana();
    void attaquer(Personnage &cible);
    void attaquerMagie(Personnage &cible);
    void boirePotionDeVie(int quantitePotion);
    void boirePotionDeMana(int quantitePotion);
    void changerSort(std::string nom, std::string element, int mana, int degats);
    void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);
    bool estVivant() const;
    void afficherEtat() const;
    void sortNom() const;

    private:

    int m_vie;
    int m_mana;
    std::string m_nom;
    Arme m_arme;
    Sort m_sort;
};

#endif // DEFF PERSONNAGE
