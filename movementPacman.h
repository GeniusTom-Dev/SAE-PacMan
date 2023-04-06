#ifndef MOVEMENTPACMAN_H
#define MOVEMENTPACMAN_H
#include <vector>
#include <string>
#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"
#include "type.h"
#include "mingl/audio/audioengine.h"

/**
 * @brief Gestion du clavier
 * @param[in] window : Fenêtre du jeu
 * @param[in] Mat : Matrice du jeu
 * @param[in] pac : Position du pacMan
 * @param[in] K : Caractère des éléments dans la matrice
 * @param[in] vectParamKey : Vecteur avec les touches venant du config.yaml
 * @fn void clavier(MinGL & window, CMatrix & Mat, posElement & pac, KInMat & K, std::vector<unsigned> vectParamKey);
 */
void clavier(MinGL & window, CMatrix & Mat, posElement & pac, KInMat & K, std::vector<unsigned> vectParamKey);


/**
 * @brief Déplacement en pixel du pacman qui sera affiché
 * @param[in] window : Fenêtre du jeu
 * @param[in] pacMan : Sprite du pacman
 * @param[in] pac : Position du pacMan
 * @param[in] pixelSize : Taille d'une case
 * @fn void moovePac(MinGL & window, nsGui::Sprite & pacMan, posElement & pac, const unsigned & pixelSize);
 */
void moovePac(MinGL & window, nsGui::Sprite & pacMan, posElement & pac, const unsigned & pixelSize);

/**
 * @brief met les position du pacman a la valeur initiale
 * @param[in_out] pac : Positions du pacMan
 * @param[in] pixelSize : taille d'une case
 * @fn void resetPosPac(posElement & pac);
 */
void resetPosPac(posElement & pac, unsigned & pixelSize);


/**
 * @brief detecte des collisions entre pac man et fantômes
 * @param[in,out] pac : Positions du pacMan
 * @param[in,out] phan1 : Position du Phantom 1
 * @param[in,out] phan2 : Position du Phantom 2
 * @param[in,out] phan3 : Position du Phantom 3
 * @param[in] pixelSize : taille d'une case
 * @param[in] eatQT : booleen de si pacman est en mode buff
 * @param[in] life : nombre de vie restantes
 * @param[in] score : score du jeu
 * @param[in] audioEngine : gestionnaire des sons
 * @fn void collide(posElement & pac, posElement & phan1, posElement & phan2, posElement & phan3, unsigned & pixelSize, bool & eatQT, unsigned & life, unsigned & score);
 */
void collide(posElement & pac, posElement & phan1, posElement & phan2, posElement & phan3, unsigned & pixelSize, bool & eatQT, unsigned & life, unsigned & score, nsAudio::AudioEngine &audioEngine);

/**
 * @brief Déplacement du pacman dans la matrice, vérification de la case pour points, teleporteur et bonus et verification des collisions avec les fantomes
 * @param[in] Mat : Matrice du jeu
 * @param[in,out] pac : Position du pacMan
 * @param[in] K : Caractère des éléments dans la matrice
 * @param[in] score : score du jeu
 * @param[in] pixelSize : Taille d'une case
 * @param[in,out] eatQT : Si le pacman est en mode buff
 * @param[in] audioEngine : gestionnaire des sons
 * @fn void moovePacInMat(CMatrix & Mat, posElement & pac, posElement & phan1, posElement & phan2, posElement & phan3, KInMat & K, unsigned & score, unsigned & pixelSize, bool & QT,unsigned & life, nsAudio::AudioEngine &audioEngine);
 */
void moovePacInMat(CMatrix & Mat, posElement & pac, KInMat & K, unsigned & score, unsigned & pixelSize, bool & eatQT, nsAudio::AudioEngine &audioEngine );

#endif // MOVEMENTPACMAN_H
