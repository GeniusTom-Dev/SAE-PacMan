#ifndef MUSICGEST_H
#define MUSICGEST_H
#include "mingl/audio/audioengine.h"

/**
 * @brief Joue un sons en boucle
 * @param[in] audioEngine : moteur audio
 * @param[in] fileName : nom du fichier à lire
 * @fn void playLoopSound(nsAudio::AudioEngine &audioEngine, const std::string &fileName);
 */
void playLoopSound(nsAudio::AudioEngine &audioEngine, const std::string &fileName);

/**
 * @brief Arrete ou relance un sons en boucle
 * @param[in] audioEngine : moteur audio
 * @fn void stopPlayedSound(nsAudio::AudioEngine &audioEngine);
 */
void stopPlayedSound(nsAudio::AudioEngine &audioEngine);

/**
 * @brief Joue un sons une fois
 * @param[in] audioEngine : moteur audio
 * @param[in] fileName : nom du fichier à lire
 * @fn void playOneTimeSound(nsAudio::AudioEngine &audioEngine,const std::string &fileName);
 */
void playOneTimeSound(nsAudio::AudioEngine &audioEngine,const std::string &fileName);


#endif // MUSICGEST_H
