#ifndef DEFF_DUREE
#define DEFF_DUREE
#include <iostream>

class Duree
{
    public:

    Duree(int heures = 0, int minutes = 0, int secondes = 0);
    void conversion(int m_heures, int m_minutes, int m_secondes);
    bool estEgal(Duree const& b) const;
    bool estPlusPetitQue(Duree const& b) const;
    void afficher();
    Duree& operator+=(const Duree& a);
    void afficher(std::ostream &flux) const;

    private:

    int m_heures;
    int m_minutes;
    int m_secondes;
};

bool operator==(Duree const& a, Duree const& b);
bool operator!=(Duree const& a, Duree const& b);
bool operator<(Duree const &a, Duree const& b);
bool operator>(Duree const &a, Duree const& b);
bool operator<=(Duree const &a, Duree const& b);
bool operator>=(Duree const &a, Duree const& b);
Duree operator+(Duree const& a, Duree const& b);
std::ostream& operator<<(std::ostream &flux, Duree const& duree);

#endif // DEFF_DUREE
