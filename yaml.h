#ifndef YAML_H
#define YAML_H
#include <vector>
#include <string>

/**
 * @brief Récupération des paramètres
 * @param[in] filename : Nom du fichier config
 * @return vector<unsigned> : tous les parametres importés du fichier
 * @fn std::vector<unsigned> vecParam (const std::string & filename);
 */
std::vector<unsigned> vecParam (const std::string & filename);

#endif // YAML_H
