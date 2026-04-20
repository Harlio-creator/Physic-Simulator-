#include <iostream>
#include "ma_bibliotheque2.h"

using namespace std;

int main() {
    float v0, alpha0, x0, z0, xi, vi, yi_prime;
    float possible = 0;

while(possible == 0)
{
    cout << "========== SIMULATEUR D'INTERCEPTION ==========" << endl;

    // --- SAISIE UNIQUE DES PARAMETRES ---
    cout << "\n--- PARAMETRES DE LA CIBLE ---" << endl;
    cout << "Vitesse v0 (m/s) : "; cin >> v0;
    cout << "Angle alpha0 (deg) : "; cin >> alpha0;
    cout << "Position x0 (m) : "; cin >> x0;
    cout << "Altitude z0 (m) : "; cin >> z0;
    cout << "Distance d'impact xi (m) : "; cin >> xi;

    cout << "\n--- PARAMETRES DE L'INTERCEPTEUR ---" << endl;
    cout << "Vitesse vi (m/s) : "; cin >> vi;
    cout << "Distance yi' (m) : "; cin >> yi_prime;

    cout << "\n----------------------------------------------------------" << endl;

    // 1. Vérification de l'existence d'une solution
    possible = Rechercher_Existence_Solution(xi, yi_prime, alpha0, v0, x0, z0, vi);
}

// 2. Calculs finaux si la solution est confirmée
float zi = Calculer_Z_Trajectoire(xi, alpha0, v0, x0, z0);
float alpha_i = Calculer_Alpha_Intercepteur(xi, yi_prime, alpha0, v0, x0, z0, vi);
float t0 = Calculer_Temps_Vol(xi, alpha0, v0, x0, z0);
float ti = Calculer_Temps_Vol(yi_prime, alpha_i, vi, 0, 0);
float delta_t = Calculer_Temps_Vol_Difference(t0, ti);
cout << "\n----------------------------------------------------------" << endl;
// 3. Affichage des résultats
cout << "\n--- RESULTATS FINAUX ---" << endl;
cout << "Altitude d'impact : " << zi << " m" << endl;
cout << "Angle de l'intercepteur : " << alpha_i << " degres" << endl;
cout << "Temps de vol cible : " << t0 << " s" << endl;
cout << "Temps de vol intercepteur : " << ti << " s" << endl;
cout << "DECALAGE DE TIR (Delta T) : " << delta_t << " s" << endl;

    cout << "================================================" << endl;
    return 0;
}

