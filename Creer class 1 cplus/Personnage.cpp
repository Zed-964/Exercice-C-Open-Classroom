#include "Personnage.h"

using namespace std;

Personnage::Personnage() : m_nom("david"), m_vie(100), m_mana(100)
{

}

Personnage::Personnage(string nom, string nomArme, int degatsArme) : m_nom(nom), m_vie(100), m_mana(100), m_arme(nomArme, degatsArme)
{

}

Personnage::Personnage(string nom, int vie, int mana) : m_nom(nom), m_vie(vie), m_mana(mana)
{

}

Personnage::~Personnage()
{

}

void Personnage::recevoirDegats(int nbDegats)
{
    m_vie -= nbDegats; // on enleve le nb de degats reçus a la vie du personnage

    if (m_vie < 0)
    {
        m_vie = 0;
    }
}

void Personnage::recevoirMagie(int nbDegats)
{
    m_vie -= nbDegats;

    if (m_vie < 0)
    {
        m_vie = 0;
    }
}

void Personnage::attaquer(Personnage &cible)
{
    cible.recevoirDegats(m_arme.getDegats()); // on inflige a la cible les degats que cause notre arme
}

void Personnage::utileMana()
{
    cout << "Votre mana est a : " << m_mana << endl;
    m_mana -= m_sort.getConso();
    cout << "Votre mana est descendu a : " << m_mana << endl;
}

void Personnage::attaquerMagie(Personnage &cible)
{
    utileMana();
    cible.recevoirMagie(m_sort.getDegats());
}

void Personnage::boirePotionDeVie(int quantitePotion)
{
    m_vie += quantitePotion;

    if (m_vie > 100)
    {
        m_vie = 100;
    }
}

void Personnage::boirePotionDeMana(int quantitePotion)
{
    m_mana += quantitePotion;

    if (m_mana > 100)
    {
        m_mana = 100;
    }
}

void Personnage::sortNom() const
{
    cout << m_sort.getNom();
}

void Personnage::changerSort(string nom, string element, int mana, int degats)
{
    m_sort.changer(nom, element, mana, degats);
}

void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
{
    m_arme.changer(nomNouvelleArme, degatsNouvelleArme);
}

bool Personnage::estVivant() const
{
    if (m_vie > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Personnage::afficherEtat() const
{
    cout << "Vie : " << m_vie << endl;
    cout << "Mana : " << m_mana << endl;
    m_arme.afficher();
}
