#include "movementPhantom.h"
#include <cstdlib>

using namespace std ;
using namespace nsGraphics;

void moovePhan(MinGL & window, nsGui::Sprite & Phantom, posElement & phan, const unsigned & pixelSize){

    if(phan.X<phan.MatX*(pixelSize+1)){
        phan.X+=1;
    }else if(phan.X>phan.MatX*(pixelSize+1)){
        phan.X-=1;
    }else if(phan.Y>phan.MatY*(pixelSize+1)){
        phan.Y-=1;
    }else if(phan.Y<phan.MatY*(pixelSize+1)){
        phan.Y+=1;
    }
    Phantom.setPosition(Vec2D(phan.X+5,phan.Y));
    window << Phantom;
}

void moovePhanInMat(CMatrix & Mat, posElement & phan, KInMat & K ,unsigned & pixelSize){

    if (phan.toWall){
        vector<string> possibleDir = {};
        srand((unsigned int)time(NULL));
        for (unsigned var = 0; var < 4; ++var) {
            if (Mat[phan.MatY][phan.MatX+1]!=K.Wall)
                possibleDir.push_back("right");
            if (Mat[phan.MatY][phan.MatX-1]!=K.Wall)
                possibleDir.push_back("left");
            if (Mat[phan.MatY-1][phan.MatX]!=K.Wall)
                possibleDir.push_back("up");
            if (Mat[phan.MatY+1][phan.MatX]!=K.Wall)
                possibleDir.push_back("down");
        }
        phan.dir = possibleDir[rand()%possibleDir.size()];
        phan.toWall = false;
    }
    else{
        if(phan.dir == "right" && Mat[phan.MatY][phan.MatX+1]!=K.Wall){
            phan.MatX+=1;
            if(Mat[phan.MatY][phan.MatX] == 'T'){
                phan.MatX = 1;
                phan.X = 1 *(pixelSize+1);
            }
        }else if(phan.dir == "left" && Mat[phan.MatY][phan.MatX-1]!=K.Wall){
            phan.MatX-=1;
            if(Mat[phan.MatY][phan.MatX] == 'T'){
                phan.MatX = Mat[phan.MatY].size()-2;
                phan.X = (Mat[phan.MatY].size()-2)*(pixelSize+1);
            }
        }else if(phan.dir == "up" && Mat[phan.MatY-1][phan.MatX]!=K.Wall){
            phan.MatY-=1;
        }else if(phan.dir == "down" && Mat[phan.MatY+1][phan.MatX]!=K.Wall){
            phan.MatY+=1;
        }else{
            phan.toWall = true;
        }
    }
}
