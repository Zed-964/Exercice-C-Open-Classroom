#ifndef DEFF_ZFRACTION
#define DEFF_ZFRACTION

#include <iostream>

class ZFraction
{
    public:

    ZFraction();
    ZFraction(int numerateur);
    ZFraction(int numerateur, int denominateur);
    void afficher();
    void afficher(std::ostream &flux) const;
    void simplifier();
    ZFraction& operator+=(const ZFraction& a);
    ZFraction& operator*=(ZFraction const& autre);
    bool estEgal(ZFraction const& b) const;
    bool estPlusPetitQue(ZFraction const& autre) const;

    private:

    int m_numerateur;
    int m_denominateur;
};

bool operator==(ZFraction const& a, ZFraction const& b);
bool operator<(ZFraction const& a, ZFraction const& b);
bool operator>(ZFraction const& a, ZFraction const& b);
bool operator<=(ZFraction const& a, ZFraction const& b);
bool operator>=(ZFraction const& a, ZFraction const& b);
ZFraction operator+(ZFraction const& a, ZFraction const& b);
std::ostream& operator<<(std::ostream &flux, ZFraction const& ZFraction);
int pgcd(int a, int b);

#endif // DEFF_ZFRACTION
