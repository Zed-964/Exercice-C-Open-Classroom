#include <iostream>
#include "Duree.h"

using namespace std;

int main()
{
    Duree duree1(1, 45, 50), duree2(1, 15, 40);
    Duree resultat;

    if (duree1 <= duree2)
        cout << "La premiere duree est plus grande" << endl;
    else
        cout << "La premiere duree n'est pas plus grande" << endl;

    duree1.afficher();
    cout << " et " << endl;
    duree2.afficher();

    resultat = duree1 + duree2;

    cout << " donne " << endl ;
    resultat.afficher();

    cout << duree1 << " et " << duree2 << endl;

    return 0;
}
