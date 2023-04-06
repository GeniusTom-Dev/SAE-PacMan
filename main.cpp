#define FPS_LIMIT 60

#include <iostream>
#include <thread>
#include <vector>

#include "mingl/gui/sprite.h"
#include "mingl/mingl.h"
#include "MinGL2/include/mingl/audio/audioengine.h"

#include "yaml.h"
#include "musicGest.h"
#include "movementPacman.h"
#include "movementPhantom.h"
#include "draw.h"
#include "map.h"
#include "menu.h"
#include "type.h"

using namespace std;
using namespace nsGraphics;
using namespace nsAudio;

int main()
{
    KInMat K;
    K.Wall = 'X';
    K.PhantomWall = 'x';
    K.Dot = 'o';
    K.QT = 'Q';

    vector<unsigned> vectParamKey = vecParam("build/config.yaml");
    unsigned pixelSize = 30;

    unsigned score = 0;

    posElement pac ;
    resetPosPac(pac, pixelSize);

    posElement phan1 ;
    phan1.MatY = 11;
    phan1.MatX = 12;
    phan1.Y = phan1.MatY*(pixelSize+1);
    phan1.X = phan1.MatX*(pixelSize+1);
    phan1.toWall = false;
    phan1.dir = "up";

    posElement phan2 ;
    phan2.MatY = 11;
    phan2.MatX = 13;
    phan2.Y = phan2.MatY*(pixelSize+1);
    phan2.X = phan2.MatX*(pixelSize+1);
    phan2.toWall = false;
    phan2.dir = "right";

    posElement phan3 ;
    phan3.MatY = 11;
    phan3.MatX = 11;
    phan3.Y = phan3.MatY*(pixelSize+1);
    phan3.X = phan3.MatX*(pixelSize+1);
    phan3.toWall = false;
    phan3.dir = "left";

    bool textEnter = true ;
    bool chrono = true;
    unsigned deb;

    bool win = true;
    bool startGame = false;
    bool endGame = false;
    bool eatQT = false;
    unsigned posPacChoice = 0;
    unsigned life = 3;
    unsigned temps=0;

    unsigned posScoreX = 600;
    unsigned posScoreY = 20;
    nsAudio::AudioEngine audioEngine;

    nsGui::Sprite pacMan("build/assets/Casali.si2", Vec2D(pac.X,pac.Y));
    nsGui::Sprite Phan1("build/assets/i_bleu.si2", Vec2D(phan1.X,phan1.Y));
    nsGui::Sprite Phan2("build/assets/i_jaune.si2", Vec2D(phan2.X,phan2.Y));
    nsGui::Sprite Phan3("build/assets/i_vert.si2", Vec2D(phan3.X,phan3.Y));
    nsGui::Sprite PacMap("build/assets/pacmap.si2", nsGraphics::Vec2D(780/2-180,780/4-100));
    nsGui::Sprite Map1("build/assets/map1.si2", nsGraphics::Vec2D(780/2-180,780/2-100));
    nsGui::Sprite Map2("build/assets/map2.si2", nsGraphics::Vec2D(780/2-180,780/2));
    nsGui::Sprite Map3("build/assets/map3.si2", nsGraphics::Vec2D(780/2-180,780/2+100));
    nsGui::Sprite pacChoose("build/assets/pacchoose.si2", nsGraphics::Vec2D(780/2-200,780/2 - 75));
    nsGui::Sprite spriteHeart1("build/assets/heart.si2", Vec2D(30,5));
    nsGui::Sprite spriteHeart2("build/assets/heart.si2", Vec2D(50,5));
    nsGui::Sprite spriteHeart3("build/assets/heart.si2", Vec2D(70,5));
    nsGui::Sprite winTitle("build/assets/win.si2", nsGraphics::Vec2D(780/2-180,800/4-100));
    nsGui::Sprite looseTitle("build/assets/loose.si2", nsGraphics::Vec2D(780/2-180,800/4-100));


    vector<CMatrix> vectMap = vecMapGenerator();
    CMatrix mat;

    // Initialise le système
    MinGL window("PacMan", Vec2D(780,780), Vec2D(128, 128), KBlack);

    window.initGlut();
    window.initGraphic();

    // Variable qui tient le temps de frame
    chrono::microseconds frameTime = chrono::microseconds::zero();


    playLoopSound(audioEngine, "pacman_ringtone.wav");

    // On fait tourner la boucle tant que la fenêtre est ouverte
    while (window.isOpen())
    {
        // Récupère l'heure actuelle
        chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now();

        // On efface la fenêtre
        window.clearScreen();

        ++temps;
        if (temps==1000) temps = 0;
        if (temps %5 ==0) textEnter = !textEnter;

        if(eatQT){
            if (chrono){
            deb = temps;
            deb = deb + vectParamKey[0]*100-1 ;
            while (deb > 1000) deb = deb-1000;
            chrono = false;
            }
            if (temps == deb){
                eatQT = false;
                playLoopSound(audioEngine, "pacman_beginning.wav");
                chrono = true;
            }
        }
        if (endGame == false)
            drawMatrix(mat, window, pixelSize, K, eatQT);

        if(!startGame && endGame == false){
            this_thread::sleep_for(chrono::milliseconds(200));
            menuStart(window,PacMap, Map1, Map2, Map3,pacChoose, vectParamKey,startGame, textEnter, posPacChoice,mat, vectMap, audioEngine);

        }else if (endGame == false && thereIsDot(mat,K)){
            showScore(window, posScoreX, posScoreY, score);
            showLife(window, life, spriteHeart1, spriteHeart2, spriteHeart3);
            clavier(window, mat, pac,K,vectParamKey);
            //Déplacement du PacMan
            if(phan1.X==phan1.MatX*(pixelSize+1) && phan1.Y==phan1.MatY*(pixelSize+1))
                moovePhanInMat(mat,phan1,K,pixelSize);
            if(phan2.X==phan2.MatX*(pixelSize+1) && phan2.Y==phan2.MatY*(pixelSize+1))
                moovePhanInMat(mat,phan2,K,pixelSize);
            if(phan3.X==phan3.MatX*(pixelSize+1) && phan3.Y==phan3.MatY*(pixelSize+1))
                moovePhanInMat(mat,phan3,K,pixelSize);
            if(pac.X==pac.MatX*(pixelSize+1) && pac.Y==pac.MatY*(pixelSize+1))
                moovePacInMat(mat,pac, K, score, pixelSize, eatQT, audioEngine);
            collide(pac, phan1, phan2, phan3, pixelSize, eatQT, life, score, audioEngine);

            moovePhan(window, Phan1, phan1, pixelSize);
            moovePhan(window, Phan2, phan2, pixelSize);
            moovePhan(window, Phan3, phan3, pixelSize);
            moovePac(window, pacMan, pac, pixelSize);
        }else if (!thereIsDot(mat,K)){
            if(win == false) playLoopSound(audioEngine, "pacman_ringtone.wav");
            resetPosPac(pac, pixelSize);
            win = true;
            endgame(window ,endGame, startGame, life, vectParamKey, score,phan1, phan2, phan3);
            menuEnd(window, win, winTitle, looseTitle,score);
        }
        if(life <= 0){
            resetPosPac(pac, pixelSize);
            win = false;
            endgame(window,endGame, startGame, life, vectParamKey, score, phan1, phan2, phan3);
            menuEnd(window, win, winTitle, looseTitle,score);
        }
        // On finit la frame en cours
        window.finishFrame();

        // On vide la queue d'évènements
        window.getEventManager().clearEvents();

        // On attend un peu pour limiter le framerate et soulager le CPU
        this_thread::sleep_for(chrono::milliseconds(1000 / FPS_LIMIT) - chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start));

        // On récupère le temps de frame
        frameTime = chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start);

    }

    return 0;
}
