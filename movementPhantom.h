#ifndef MOVEMENTPHANTOM_H
#define MOVEMENTPHANTOM_H
#include <vector>
#include <string>
#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"
#include "type.h"

/**
 * @brief Déplacement d'un phantom en valeur réel
 * @param[in] window : Fenêtre du jeu
 * @param[in] Phantom : Sprite du phantom
 * @param[in,out] phan : Position du phantom
 * @param[in] pixelSize : Taille d'une case
 * @fn void moovePhan(MinGL & window, nsGui::Sprite & Phantom, posElement & phan, const unsigned & pixelSize);
 */
void moovePhan(MinGL & window, nsGui::Sprite & Phantom, posElement & phan, const unsigned & pixelSize);

/**
 * @brief Déplacement du phantom dans la matrice
 * @param[in] Mat : Matrice du jeu
 * @param[in,out] phan : Position du pacMan
 * @param[in] K : Caractère des éléments dans la matrice
 * @param[in] pixelSize : Taille d'une case
 * @fn void moovePhanInMat(CMatrix & Mat, posElement & phan, KInMat & K ,unsigned & pixelSize);
 */
void moovePhanInMat(CMatrix & Mat, posElement & phan, KInMat & K ,unsigned & pixelSize);

#endif // MOVEMENTPHANTOM_H
