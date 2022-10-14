#ifndef DEFF_SORT
#define DEFF_SORT

#include <iostream>
#include <string>

class Sort
{
    public :

    Sort();
    Sort(std::string nom, std::string element, int manaUtile, int degats);
    int getConso() const;
    int getDegats() const;
    std::string getNom() const;
    void changer(std::string nom, std::string element, int mana, int degats);

    private :

    int m_conso;
    int m_degatsMagique;
    std::string m_nom;
    std::string m_element;
};

#endif // DEFF_SORT
