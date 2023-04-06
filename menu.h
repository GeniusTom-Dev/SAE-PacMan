#include <vector>
#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"
#include "type.h"
#include "mingl/audio/audioengine.h"
#ifndef MENU_H
#define MENU_H

/**
 * @brief Création d'un menu avant le début d'une partie
 * @param[in] window : Fenêtre du jeu
 * @param[in] PacMap : Sprite pour le menu
 * @param[in] map1 : Sprite pour le menu
 * @param[in] map2 : Sprite pour le menu
 * @param[in] map3 : Sprite pour le menu
 * @param[in] pacChoose : Sprite pour le menu
 * @param[in] vectParamKey : Vecteur avec les touches venant du config.yaml
 * @param[in,out] startGame : Bool -> Si la partie a commencer
 * @param[in] textEnter : Bool -> S'il doit afficher le text de lancement
 * @param[in,out] posPacChoice : index de la map a rentrer
 * @param[in,out] mat : Matrice de la partie
 * @param[in] vectMap : Matrice comprenant les maps
 * @param[in] audioEngine : gestionaire des sons
 * @fn void menuStart(MinGL &window,nsGui::Sprite & PacMap,nsGui::Sprite & map1,nsGui::Sprite & map2,nsGui::Sprite & map3, nsGui::Sprite & pacChoose,
               std::vector<unsigned> vectParamKey, bool & startGame, bool & textEnter, unsigned & posPacChoice,
               CMatrix & mat, std::vector<CMatrix> vectMap);
 */
void menuStart(MinGL &window,nsGui::Sprite & PacMap,nsGui::Sprite & map1,nsGui::Sprite & map2,nsGui::Sprite & map3, nsGui::Sprite & pacChoose,
               std::vector<unsigned> vectParamKey, bool & startGame, bool & textEnter, unsigned & posPacChoice,
               CMatrix & mat, std::vector<CMatrix> vectMap, nsAudio::AudioEngine &audioEngine);

/**
 * @brief Creation d'un menu pour la fin de la partie
 * @param[in] window : Fenêtre du jeu
 * @param[in] win : booleen qui indique si on a gagné ou perdu
 * @param[in] winTitle : Sprite pour le menu de fin gagné
 * @param[in] looseTitle : Sprite pour le menu de fin perdu
 * @param[in] score : score actuel
 * @fn void menuEnd(MinGL &window, bool & win, nsGui::Sprite & winTitle, nsGui::Sprite & looseTitle, unsigned & score);
 */
void menuEnd(MinGL &window, bool & win, nsGui::Sprite & winTitle, nsGui::Sprite & looseTitle, unsigned & score);

/**
 * @brief fin de la partie et redemarrage si la touche est appuyée
 * @param[in] window : Fenêtre du jeu
 * @param[in,out] endGame : booleen pour la fin du jeu
 * @param[in,out] startGame : booleen pour le debut du jeu
 * @param[in,out] life : nombre de vie restantes
 * @param[in] vectParamKey : Vecteur avec les touches venant du config.yaml
 * @param[in,out] score : score actuel
 * @param[in,out] phan1 positions de phan1
 * @param[in,out] phan2 positions de phan2
 * @param[in,out] phan3 positions de phan3
 * @fn void endgame(MinGL & window, bool & endGame, bool & startGame, unsigned & life);
 */
void endgame(MinGL & window, bool & endGame, bool & startGame, unsigned & life, std::vector<unsigned> & vectParamKey,  unsigned & score,
             posElement & phan1, posElement & phan2, posElement & phan3);


#endif // MENU_H
