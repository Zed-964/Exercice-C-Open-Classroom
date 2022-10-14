#include "Sort.h"

using namespace std;

Sort::Sort() : m_nom("Kame Hame HA !"), m_element("Ki"), m_conso(15), m_degatsMagique(15)
{

}

Sort::Sort(string nom, string element, int manaUtile, int degats) : m_nom(nom),m_element(element), m_conso(manaUtile), m_degatsMagique(degats)
{

}

int Sort::getConso() const
{
    return m_conso;
}

int Sort::getDegats() const
{
    return m_degatsMagique;
}

string Sort::getNom() const
{
    return m_nom;
}

void Sort::changer(string nom, string element, int mana, int degats)
{
    m_nom = nom;
    m_element = element;
    m_conso = mana;
    m_degatsMagique = degats;
}
