#ifndef DRAW_H
#define DRAW_H
#include "mingl/mingl.h"
#include "type.h"
#include "mingl/gui/sprite.h"


/**
 * @brief affiche le score aux coordonnées
 * @param[in] window : Fenêtre du jeu
 * @param[in] X : position X du score
 * @param[in] Y : position Y du score
 * @param[in] Score : Score actuel de la partie
 * @fn void showScore(MinGL & window, unsigned & X, unsigned & Y, unsigned & score);
 */
void showScore(MinGL & window, unsigned & X, unsigned & Y, unsigned & score);

/**
 * @brief Crée un cube de mur
 * @param[in] window : Fenêtre du jeu
 * @param[in] X : position X du mur
 * @param[in] Y : position Y du mur
 * @param[in] pixelSize : Taille du cube de mur
 * @fn void wall(MinGL & window, const unsigned & X, const unsigned & Y, const unsigned pixelSize);
 */
void wall(MinGL & window, unsigned & X, unsigned & Y, const unsigned pixelSize);

/**
 * @brief Crée un cube de mur traversable par les fantomes
 * @param[in] window : Fenêtre du jeu
 * @param[in] X : position X du mur
 * @param[in] Y : position Y du mur
 * @param[in] pixelSize : Taille du cube de mur
 * @fn void phantomWall(MinGL & window, const unsigned & X, const unsigned & Y, const unsigned pixelSize);
 */
void phantomWall(MinGL & window, unsigned & X, unsigned & Y, const unsigned pixelSize);

/**
 * @brief Crée un point commestible
 * @param[in] window : Fenêtre du jeu
 * @param[in] X : position X du point
 * @param[in] Y : position Y du point
 * @fn void dot(MinGL & window, const unsigned & X, const unsigned & Y);
 */
void dot(MinGL & window, const unsigned & X, const unsigned & Y, bool & eatQT);

/**
 * @brief Crée un point commestible donnant le buff
 * @param[in] window : Fenêtre du jeu
 * @param[in] X : position X du point
 * @param[in] Y : position Y du point
 * @param[in] eatQT : booleen du buff de pacman
 * @fn void qt(MinGL & window, const unsigned & X, const unsigned & Y);
 */
void qt(MinGL & window, const unsigned & X, const unsigned & Y);

/**
 * @brief Dessine le nombre de coeur en fonction de la vie restante
 * @param[in] window : Fenêtre du jeu
 * @param[in] life : nombre de vie restante
 * @param[in] spriteHeart1 : sprite coeur 1
 * @param[in] spriteHeart2 : sprite coeur 2
 * @param[in] spriteHeart3 : sprite coeur 3
 * @fn void showLife(MinGL & window, unsigned & life, nsGui::Sprite & spriteHeart1,  nsGui::Sprite & spriteHeart2, nsGui::Sprite & spriteHeart3);
 */
void showLife(MinGL & window, unsigned & life, nsGui::Sprite & spriteHeart1,  nsGui::Sprite & spriteHeart2, nsGui::Sprite & spriteHeart3);

/**
 * @brief Affichage de la matrice dans la fenêtre
 * @param[in] Mat : Matrice du jeu
 * @param[in] window : Fenêtre du jeu
 * @param[in] pixelSize : Taille d'une case
 * @param[in] K : Caractère des éléments dans la matrice
 * @param[in] eatQT : booleen du buff de pacman
 * @fn void  drawMatrix (CMatrix & Mat, MinGL & window, unsigned pixelSize, KInMat & K, bool & eatQT);
 */
void  drawMatrix (CMatrix & Mat, MinGL & window, const unsigned pixelSize, KInMat & K, bool & eatQT);


#endif // DRAW_H
