#ifndef TYPE_H
#define TYPE_H
#include <vector>
#include <string>


/**
 * @struct KInMat
 * @brief constante des caractère définissant la map
 */
struct KInMat {
    char Wall, PhantomWall, Dot, QT;
};

/**
 * @struct posElement
 * @brief Position d'un élement
 */
struct posElement {
    unsigned X,Y,MatX,MatY;
    bool toWall;
    std::string dir;
};

/**
 * @typedef CMatrix
 * @brief Matrice : Vecteur de Vecteur
 */
typedef std::vector <char> CVLine;
typedef std::vector <CVLine> CMatrix;

#endif // TYPE_H
