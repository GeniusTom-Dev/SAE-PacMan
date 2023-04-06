#include<vector>
#ifndef MAP_H
#define MAP_H
#include "type.h"

/**
 * @brief Fonction de récupérations des matrices
 * @return vector : return les matrices
 * @fn std::vector<CMatrix> vecMapGenerator();
 */
std::vector<CMatrix> vecMapGenerator();

/**
 * @brief Crée un point commestible donnant le buff
 * @param[in] Mat : Matrice du jeu
 * @param[in] K : Caractère des éléments dans la matrice
 * @return bool: S'il reste un point
 * @fn bool thereIsDot(CMatrix & Mat, KInMat & K);
 */
bool thereIsDot(CMatrix & Mat, KInMat & K);


#endif // MAP_H

