#include "draw.h"
#include "mingl/shape/rectangle.h"
#include "mingl/shape/circle.h"
#include "mingl/gui/text.h"


using namespace std;
using namespace nsGraphics;
using namespace nsShape;

void showScore(MinGL & window, unsigned & X, unsigned & Y, unsigned & score){
    window << nsGui::Text(nsGraphics::Vec2D(X, Y), "Score: " + to_string(score), KYellow, nsGui::GlutFont::BITMAP_HELVETICA_18);
}

//fonction pour dessiner une case mur
void wall(MinGL & window, const unsigned & X, const unsigned & Y, const unsigned pixelSize){
    window << Rectangle(Vec2D(X, Y), Vec2D(X+pixelSize, Y+pixelSize), nsGraphics::KTransparent, nsGraphics::KBlue);
}

//fonction pour dessiner une case phantom
void phantomWall(MinGL & window, const unsigned & X, const unsigned & Y, const unsigned pixelSize){
    window << Rectangle(Vec2D(X, Y), Vec2D(X+pixelSize, Y+pixelSize), nsGraphics::KTransparent, nsGraphics::KCyan);
}

void dot(MinGL & window, const unsigned & X, const unsigned & Y, bool & eatQT){
    //window << nsGui::Sprite("build/assets/OM.si2", Vec2D(X+2,Y+2));
    if(eatQT)
        window << Circle(Vec2D(X,Y), 5, KTransparent, KBlue);
    else
        window << Circle(Vec2D(X,Y), 5, KTransparent, KYellow);
}

//fonction pour dessiner un QT
void qt(MinGL & window, const unsigned & X, const unsigned & Y){
    //window << nsGui::Sprite("build/assets/OM.si2", Vec2D(X+2,Y+2));
    nsGui::Sprite spriteQT("build/assets/QT_logo.si2", Vec2D(X,Y));
    window << spriteQT;
}
void showLife(MinGL & window, unsigned & life, nsGui::Sprite & spriteHeart1,  nsGui::Sprite & spriteHeart2, nsGui::Sprite & spriteHeart3){

    if (life >= 1){
        window << spriteHeart1;
        if(life >=2){
            window << spriteHeart2;
            if(life == 3)
                window << spriteHeart3;
        }
    }
}

void  drawMatrix (CMatrix & Mat, MinGL & window, unsigned pixelSize, KInMat & K, bool & eatQT){
    window.clearScreen();
    for (unsigned line = 0 ; line < Mat.size(); ++line) {
        for (unsigned column = 0 ; column < Mat[line].size(); ++column) {
            if(Mat[column][line] == K.Wall)
                wall(window,line*(pixelSize+1),column*(pixelSize+1),pixelSize);
            if(Mat[column][line] == K.PhantomWall)
                phantomWall(window,line*(pixelSize+1),column*(pixelSize+1),pixelSize);
            else if(Mat[column][line] == K.Dot){
                dot(window,line*(pixelSize+1)+pixelSize/2,column*(pixelSize+1)+pixelSize/2, eatQT);
            }if(Mat[column][line] == K.QT)
                qt(window,line*(pixelSize+1)+5,column*(pixelSize+1)+5);
        }
    }
}
