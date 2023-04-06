#include "movementPacman.h"
#include "type.h"
#include "musicGest.h"

using namespace std ;
using namespace nsGraphics;

void clavier(MinGL & window, CMatrix & Mat, posElement & pac, KInMat & K, vector<unsigned> vectParamKey){

        // On vérifie si ZQSD est pressé, et met a jour la pac.direction
        if (window.isPressed({(vectParamKey[5]), false}) && Mat[pac.MatY-1][pac.MatX]!=K.Wall && Mat[pac.MatY-1][pac.MatX]!=K.PhantomWall){
            pac.dir = "up";
        }
        if (window.isPressed({(vectParamKey[4]), false}) && Mat[pac.MatY+1][pac.MatX]!=K.Wall && Mat[pac.MatY+1][pac.MatX]!=K.PhantomWall){
            pac.dir = "down";
        }
        if (window.isPressed({(vectParamKey[2]), false}) && Mat[pac.MatY][pac.MatX-1]!=K.Wall && Mat[pac.MatY][pac.MatX-1]!=K.PhantomWall){
            pac.dir = "left";
        }
        if (window.isPressed({(vectParamKey[3]), false}) && Mat[pac.MatY][pac.MatX+1]!=K.Wall && Mat[pac.MatY][pac.MatX+1]!=K.PhantomWall){
            pac.dir = "right";
        }
}

void moovePac(MinGL & window, nsGui::Sprite & pacMan, posElement & pac, const unsigned & pixelSize){

    if(pac.X<pac.MatX*(pixelSize+1)){
        pac.X+=1;
    }else if(pac.X>pac.MatX*(pixelSize+1)){
        pac.X-=1;
    }else if(pac.Y>pac.MatY*(pixelSize+1)){
        pac.Y-=1;
    }else if(pac.Y<pac.MatY*(pixelSize+1)){
        pac.Y+=1;
    }
    pacMan.setPosition(Vec2D(pac.X+5,pac.Y));
    window << pacMan;
}

void resetPosPac(posElement & pac, unsigned & pixelSize){
    pac.MatX = 2;
    pac.MatY = 2;
    pac.Y = pac.MatY*(pixelSize+1);
    pac.X = pac.MatX*(pixelSize+1);
    pac.dir = "";
}
void collide(posElement & pac, posElement & phan1, posElement & phan2, posElement & phan3, unsigned & pixelSize, bool & eatQT, unsigned & life, unsigned & score, nsAudio::AudioEngine & audioEngine){
    if((pac.MatY == phan1.MatY && pac.MatX == phan1.MatX) || (pac.MatY == phan2.MatY && pac.MatX == phan2.MatX) || (pac.MatY == phan3.MatY && pac.MatX == phan3.MatX)){
        if (!eatQT){
            --life;
            if(life == 0){
                playLoopSound(audioEngine, "pacman_ringtone.wav");
            }
            pac.MatX=2;
            pac.MatY=2;
            pac.X=2*(pixelSize+1);
            pac.Y=2*(pixelSize+1);
        }else if (eatQT){
            if(pac.MatY == phan1.MatY && pac.MatX == phan1.MatX){
                phan1.MatX=12;
                phan1.MatY=11;
                phan1.X=12*(pixelSize+1);
                phan1.Y=11*(pixelSize+1);
            }else if((pac.MatY == phan2.MatY && pac.MatX == phan2.MatX)){
                phan2.MatX=13;
                phan2.MatY=11;
                phan2.X=13*(pixelSize+1);
                phan2.Y=11*(pixelSize+1);
            }else if((pac.MatY == phan3.MatY && pac.MatX == phan3.MatX)){
                phan3.MatX=11;
                phan3.MatY=11;
                phan3.X=11*(pixelSize+1);
                phan3.Y=11*(pixelSize+1);
            }
            score += 1000;
        }
    }
}

void moovePacInMat(CMatrix & Mat, posElement & pac, KInMat & K, unsigned & score, unsigned & pixelSize, bool & eatQT, nsAudio::AudioEngine &audioEngine){

    if(pac.dir == "right" && Mat[pac.MatY][pac.MatX+1]!=K.Wall && Mat[pac.MatY][pac.MatX+1]!=K.PhantomWall) // ca tu es pas con tu comprends
        pac.MatX+=1;
    else if(pac.dir == "left" && Mat[pac.MatY][pac.MatX-1]!=K.Wall && Mat[pac.MatY][pac.MatX-1]!=K.PhantomWall)
        pac.MatX-=1;
    else if(pac.dir == "up" && Mat[pac.MatY-1][pac.MatX]!=K.Wall && Mat[pac.MatY-1][pac.MatX]!=K.PhantomWall)
        pac.MatY-=1;
    else if(pac.dir == "down" && Mat[pac.MatY+1][pac.MatX]!=K.Wall && Mat[pac.MatY+1][pac.MatX]!=K.PhantomWall)
        pac.MatY+=1;

    if(Mat[pac.MatY][pac.MatX] == K.Dot){
        score += 100;
        Mat[pac.MatY][pac.MatX]=' ';
    }
    else if(Mat[pac.MatY][pac.MatX] == K.QT){
        eatQT = true;
        playOneTimeSound(audioEngine,"pacman_eatfruit.wav");
        playLoopSound(audioEngine,"pacman_chomp.wav");
        Mat[pac.MatY][pac.MatX]=' ';
    }
    else if(Mat[pac.MatY][pac.MatX] == 'T'){
        if(pac.MatX < Mat.size()/2){
            pac.MatX = Mat[pac.MatY].size()-2;
            pac.X = (Mat[pac.MatY].size()-2)*(pixelSize+1);
        }else{
            pac.MatX = 1;
            pac.X = pixelSize+1;
        }
    }
}
