#ifndef SAE_INFO_MA_BIBLIOTHEQUE_H
#define SAE_INFO_MA_BIBLIOTHEQUE_H

/** Déclaration des variables constantes définies en externe **/
// Constante d'accélération de la pesanteur en m/s^2
extern const float GRAVITE;

/** Déclaration des prototypes de fonctions **/

// Fonction : Calculer l'altitude z d'un projectile pour une position en abscisse donnée
float Calculer_Z_Trajectoire(
    float input_x,      // l'abscisse du point d'interception
    float input_alpha,  // l'angle d'élévation en degrés
    float input_v0,     // la vitesse initiale en m/s
    float input_x0,     // l'abscisse du point de départ du tir
    float input_z0      // l'altitude du point de départ du tir
);

// Fonction : Calculer l'angle d'élévation alpha_i pour l'intercepteur
float Calculer_Alpha_Intercepteur(
    float input_xi,        // l'abscisse du point d'interception
    float input_yi_prime,  // l'abscisse du point d'interception dans le plan de l'intercepteur
    float input_alpha0,    // l'angle d'élévation en degrés du départ de tir du premier projectile
    float input_v0,        // la vitesse initiale en m/s du premier projectile
    float input_x0,        // l'abscisse du point de départ du tir du premier projectile
    float input_z0,        // l'altitude du point de départ du tir du premier projectile
    float input_vi         // la vitesse initiale en m/s de l'intercepteur
);

// Fonction : Calculer le temps de vol d'un projectile
float Calculer_Temps_Vol(
    float input_x,      // l'abscisse du point d'interception
    float input_alpha,  // l'angle d'élévation en degrés
    float input_v0,     // la vitesse initiale en m/s
    float input_x0,     // l'abscisse du point de départ du tir
    float input_z0      // l'altitude du point de départ du tir
);

// Fonction : Calculer le décalage de temps entre les 2 départs de tir
float Calculer_Temps_Vol_Difference(
    float input_t_vol_projectile,  // le temps de vol du premier projectile
    float input_t_vol_intercepteur // le temps de vol de l'intercepteur
);

// Fonction : Rechercher l'existence d'une solution physique d'interception
float Rechercher_Existence_Solution(
    float input_xi,        // l'abscisse du point d'interception
    float input_yi_prime,  // l'abscisse du point d'interception dans le plan de l'intercepteur
    float input_alpha0,    // l'angle d'élévation en degrés du départ de tir du premier projectile
    float input_v0,        // la vitesse initiale en m/s du premier projectile
    float input_x0,        // l'abscisse du point de départ du tir du premier projectile
    float input_z0,        // l'altitude du point de départ du tir du premier projectile
    float input_vi         // la vitesse initiale en m/s de l'intercepteur
);

#endif // SAE_INFO_MA_BIBLIOTHEQUE_H
