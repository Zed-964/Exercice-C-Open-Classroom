#include <iostream>
#include "ZFraction.h"

using namespace std;

ZFraction::ZFraction() : m_numerateur(0), m_denominateur(0)
{

}

ZFraction::ZFraction(int numerateur) : m_numerateur(numerateur), m_denominateur(1)
{

}

ZFraction::ZFraction(int numerateur, int denominateur) : m_numerateur(numerateur), m_denominateur(denominateur)
{
    simplifier();
}

void ZFraction::afficher()
{
    cout << m_numerateur << "/" << m_denominateur << endl;
}

 void ZFraction::afficher(ostream &flux) const
 {
     if(m_denominateur == 1)
     {
         flux << m_numerateur;
     }
     else
     {
         flux << m_numerateur << "/" << m_denominateur;
     }
 }

 void ZFraction::simplifier()
 {
     int pg(1);
     pg = pgcd(m_numerateur, m_denominateur);
     m_numerateur /= pg;
     m_denominateur /= pg;
 }

 ZFraction& ZFraction::operator+=(const ZFraction& b)
 {
     int denomCopie1(0), denomCopie2(0), numCopie1(0), numCopie2(0);

     denomCopie1 = b.m_denominateur;
     denomCopie2 = m_denominateur;
     numCopie1 = b.m_numerateur;
     numCopie2 = b.m_denominateur;

     m_numerateur *= b.m_denominateur;
     numCopie1 *= m_denominateur;
     m_denominateur *= denomCopie1;
     numCopie2 *=denomCopie2;

     m_numerateur += numCopie1;

     simplifier();

     return *this;
 }

 ZFraction& ZFraction::operator+=(ZFraction const& autre)
{
    m_numerateur = autre.m_denominateur * m_numerateur + m_denominateur * autre.m_numerateur;
    m_denominateur = m_denominateur * autre.m_denominateur;

    simplifie();    //On simplifie la fraction
    return *this;
}

ZFraction& ZFraction::operator*=(ZFraction const& autre)
{
    m_numerateur *= autre.m_numerateur;
    m_denominateur *= autre.m_denominateur;

    simplifie();    //On simplifie la fraction
    return *this;
}

bool ZFraction::estEgal(ZFraction const& b) const
{
    if (m_numerateur == b.m_numerateur && m_denominateur == b.m_denominateur)
        return true;
    else
        return false;
}

bool ZFraction::estPlusPetitQue(ZFraction const& autre) const
{
    return (m_numerateur * autre.m_denominateur < m_denominateur * autre.m_numerateur);
}

//Operateurs

bool operator==(ZFraction const& a, ZFraction const& b)
{
    return a.estEgal(b);
}

ZFraction operator+(ZFraction const& a, ZFraction const& b)
{
    ZFraction copie(a);
    copie += b;
    return copie;
}

ostream &operator<<(ostream &flux, ZFraction const& ZFraction)
{
    ZFraction.afficher(flux) ;
    return flux;
}

int pgcd(int a, int b)
{
    while(b != 0)
    {
        const int t = b;
        b = a%b;
        a = t;
    }
    return a;
}

bool operator<(ZFraction const& a, ZFraction const& b)
{
    return a.estPlusPetitQue(b);
}

bool operator>(ZFraction const& a, ZFraction const& b)
{
    return b.estPlusPetitQue(a);
}

bool operator<=(ZFraction const& a, ZFraction const& b)
{
    return !(b.estPlusPetitQue(a));
}

bool operator>=(ZFraction const& a, ZFraction const& b)
{
    return !(a.estPlusPetitQue(b));
}
