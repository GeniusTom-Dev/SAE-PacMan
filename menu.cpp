/**
 * @date : 15 jan 2023
 * @authors AlexPOSS, TomEVEN, BastienBOUGEARD
 * @synopisis : realisation d'un pac man en c++
 **/
#include "menu.h"
#include "mingl/mingl.h"
#include "mingl/gui/text.h"
#include "type.h"
#include "musicGest.h"

void menuStart(MinGL &window,nsGui::Sprite & PacMap,nsGui::Sprite & map1,nsGui::Sprite & map2,nsGui::Sprite & map3, nsGui::Sprite & pacChoose,
               std::vector<unsigned> vectParamKey, bool & startGame, bool & textEnter, unsigned & posPacChoice, CMatrix & mat, std::vector<CMatrix> vectMap, nsAudio::AudioEngine &audioEngine){
    window.clearScreen();

    if (textEnter){
        window << nsGui::Text(nsGraphics::Vec2D(window.getWindowSize().getX()/2-120, 650), " keep pressing enter to start", nsGraphics::KYellow, nsGui::GlutFont::BITMAP_9_BY_15);
    }
    pacChoose.setPosition(nsGraphics::Vec2D(780/2-200,780/2 - 75 + (posPacChoice*100)));
    window << PacMap;
    window << map1 << map2 << map3;
    window << pacChoose;

    if (window.isPressed({char(vectParamKey[1]), false})){
        startGame = true;
        playLoopSound(audioEngine, "pacman_beginning.wav");
        mat = vectMap[posPacChoice];

    }else if (window.isPressed({char(vectParamKey[4]), false})){ // touche down
        if (posPacChoice == 2) posPacChoice = 0;
        else ++posPacChoice;
    }else if (window.isPressed({char(vectParamKey[5]), false})){ // touche up
        if (posPacChoice == 0) posPacChoice = 2;
        else --posPacChoice;
    }
}

void menuEnd(MinGL &window,bool & win,nsGui::Sprite & winTitle,nsGui::Sprite & looseTitle, unsigned & score){
    if(win){
        window << winTitle;
    }else{
        window << looseTitle;
    }
    window << nsGui::Text(nsGraphics::Vec2D(window.getWindowSize().getX()/2 - 25, window.getWindowSize().getY()/2), "Score : " + std::to_string(score), nsGraphics::KYellow, nsGui::GlutFont::BITMAP_HELVETICA_18);
}

void endgame(MinGL & window, bool & endGame, bool & startGame, unsigned & life, std::vector<unsigned> & vectParamKey,
             unsigned & score, posElement & phan1, posElement & phan2, posElement & phan3){
    endGame = true;
    startGame  = false;

    phan1.MatY = 11;
    phan1.MatX = 12;
    phan1.Y = phan1.MatY*(31);
    phan1.X = phan1.MatX*(31);
    phan1.toWall = false;
    phan1.dir = "up";

    phan2.MatY = 11;
    phan2.MatX = 13;
    phan2.Y = phan2.MatY*(31);
    phan2.X = phan2.MatX*(31);
    phan2.toWall = false;
    phan2.dir = "right";

    phan3.MatY = 11;
    phan3.MatX = 11;
    phan3.Y = phan3.MatY*(31);
    phan3.X = phan3.MatX*(31);
    phan3.toWall = false;
    phan3.dir = "left";
    window << nsGui::Text(nsGraphics::Vec2D(window.getWindowSize().getX()/2-80, 650), "press space to restart", nsGraphics::KYellow, nsGui::GlutFont::BITMAP_9_BY_15);
    if (window.isPressed({char(vectParamKey[6]), false})){
        endGame = false;
        life = 3;
        score = 0;
    }
}
