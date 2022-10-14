#include "Duree.h"
#include <iostream>

using namespace std;

Duree::Duree(int heures, int minutes, int secondes) : m_heures(heures), m_minutes(minutes), m_secondes(secondes)
{

}

void Duree::conversion(int m_heures, int m_minutes, int m_secondes)
{
    while (m_secondes >= 60)
    {
        m_secondes -= 60;
        m_minutes ++;
    }

    while (m_minutes >= 60)
    {
        m_minutes -= 60;
        m_heures ++;
    }
}

bool Duree::estEgal(Duree const& b) const
{
    return (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes == b.m_secondes);
}

bool Duree::estPlusPetitQue(Duree const& b) const
{
    if (m_heures < b.m_heures)
        return true;
    else if (m_heures == b.m_heures && m_minutes < b.m_minutes)
        return true;
    else if (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes < b.m_secondes)
        return true;
    else
        return false;
}

void Duree::afficher()
{
    cout << m_heures  << "h" << m_minutes << "m" << m_secondes << "s" << endl;
}

Duree& Duree::operator+=(const Duree& a)
{
    m_secondes += a.m_secondes;
    while (m_secondes >= 60)
    {
        m_secondes -= 60;
        m_minutes ++;
    }

    m_minutes += a.m_minutes;
    while (m_minutes >= 60)
    {
        m_minutes -= 60;
        m_heures ++;
    }

    m_heures += a.m_heures;

    return *this;
}

void Duree::afficher(ostream &flux) const
{
    flux << m_heures << "h" << m_minutes << "m" << m_secondes << "s";
}

bool operator==(Duree const& a, Duree const& b)
{
    return a.estEgal(b);
}

bool operator!=(Duree const& a, Duree const& b)
{
    return !(a==b);
}

bool operator<(Duree const &a, Duree const& b)
{
    return a.estPlusPetitQue(b);
}

bool operator>(Duree const &a, Duree const& b)
{
    return !(a<b);
}

bool operator<=(Duree const &a, Duree const& b)
{
    return !(a<b||a==b);
}

bool operator>=(Duree const& a, Duree const& b)
{
    return (a<b||a==b);
}

Duree operator+(Duree const& a, Duree const& b)
{
    Duree copie(a);
    copie += b;
    return copie;
}

ostream& operator<<(ostream &flux, Duree const& duree)
{
    duree.afficher(flux);
    return flux;
}
