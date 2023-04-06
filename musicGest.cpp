#include "mingl/audio/audioengine.h"

void playLoopSound(nsAudio::AudioEngine &audioEngine, const std::string &fileName){
    audioEngine.setMusic("build/assets/sounds/"+ fileName);
    audioEngine.startMusicFromBeginning();
}

void stopPlayedSound(nsAudio::AudioEngine &audioEngine){
    audioEngine.toggleMusicPlaying();
}

void playOneTimeSound(nsAudio::AudioEngine &audioEngine,const std::string &fileName){
    audioEngine.loadSound("build/assets/sounds/"+ fileName);
    audioEngine.playSoundFromBuffer("build/assets/sounds/"+ fileName);
}
