#include <iostream>
#include "ZFraction.h"

using namespace std;

int main()
{
    ZFraction a(1,5),b(1,5);
    ZFraction resultat(1,1);

    a.afficher();

    if (a==b)
        cout << "Les deux fractions sont egales" << endl;
    else
        cout << "Pas pareil" << endl;

    cout << a << " + " << b << endl << "=";

    resultat = a + b;
    resultat.afficher();
    resultat.simplifier();
    resultat.afficher();

    return 0;
}
