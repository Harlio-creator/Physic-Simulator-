#include "ma_bibliotheque2.h"
#include <iostream>
#include <cmath>

using namespace std;

// Définition des constantes
const float GRAVITE = 9.81;
const float PI = 3.14159265358979323846;

// --- Calcule l'altitude z à une distance x donnée ---
float Calculer_Z_Trajectoire(float input_x, float input_alpha, float input_v0, float input_x0, float input_z0) {
    float alpha_rad = input_alpha * PI / 180;
    float dx = input_x - input_x0;
    float cos_alpha = cos(alpha_rad);

    float terme_gravite = -(GRAVITE * dx * dx) / (2 * input_v0 * input_v0 * cos_alpha * cos_alpha);
    float terme_pente = dx * tan(alpha_rad);

    return terme_gravite + terme_pente + input_z0;
}

// --- Calcule l'angle précis alpha_i de l'intercepteur ---
float Calculer_Alpha_Intercepteur(float input_xi, float input_yi_prime, float input_alpha0, float input_v0, float input_x0, float input_z0, float input_vi) {
    float zi = Calculer_Z_Trajectoire(input_xi, input_alpha0, input_v0, input_x0, input_z0);
    float yi = input_yi_prime;

    float a = -(GRAVITE * yi * yi) / (2 * input_vi * input_vi);
    float b = yi;
    float c = a - zi;

    float delta = (b * b) - (4 * a * c);
    if (delta < 0){
        return -1;
    }
    else {
    float X2 = (-b + sqrt(delta)) / (2 * a);
    return atan(X2) * 180 / PI;
    }
}
// --- Calcule le temps de vol (t = dx / Vx) ---
float Calculer_Temps_Vol(float input_x, float input_alpha, float input_v0, float input_x0, float input_z0) {
    float alpha_rad = input_alpha * PI / 180;
    return (input_x - input_x0) / (input_v0 * cos(alpha_rad));
}

// --- Calcule la différence de temps Delta T ---
float Calculer_Temps_Vol_Difference(float input_t_vol_projectile, float input_t_vol_intercepteur) {
    return input_t_vol_projectile - input_t_vol_intercepteur;
}

// --- Analyse de 0 à 90° pour vérifier si une solution existe ---
float Rechercher_Existence_Solution(float input_xi, float input_yi_prime, float input_alpha0, float input_v0, float input_x0, float input_z0, float input_vi) {
    float angle_verif = Calculer_Alpha_Intercepteur(input_xi, input_yi_prime, input_alpha0, input_v0,input_x0,  input_z0,  input_vi);
    float solution_trouver = 0;
    if (angle_verif > 0 && angle_verif < 90)
        {
    cout << "L'interception est possible calculs en cours ..." << endl;
    solution_trouver = 1;
    }
    else
    {
    cout << "Merci de mettre des valeurs possibles"<< endl;
    solution_trouver = 0;
    }
    return solution_trouver;

}

