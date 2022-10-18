//
//  AudioEngine.cpp
//  AudioEngine_NoAPI
//
//  Created by John Rupsch on 10/15/22.
//

// Inclusions
#include "AudioEngine.h"


#include <stdio.h>
#include <thread>
#include <iostream>
#include <memory>

Implementation* sgpImplementation = nullptr;

Implementation::Implementation(){
    // System objects need to be declared as NULL
    // Constructor
}
Implementation::~Implementation(){
    // Destructor
}

void AudioEngine::Init(){
    sgpImplementation = new Implementation;
}

void AudioEngine::Update()
{
    sgpImplementation->Update();
}

void AudioEngine::Shutdown(){
    delete sgpImplementation;
}

/* --------------
 JukeBox Function Declarations
 - Load Sound
 - Unload Sound
 - Play Sound
 */
void AudioEngine::LoadSound(const string& strSoundName, bool b3d, bool bLooping, bool bStream){
    auto tFoundIt = sgpImplementation->mSounds.find(strSoundName);
    if(tFoundIt != sgpImplementation->mSounds.end())
        return;
}

void AudioEngine::UnloadSound(const string& strSoundName){
    auto tFoundIt = sgpImplementation->mSounds.find(strSoundName);
    if(tFoundIt == sgpImplementation->mSounds.end())
       return;
   sgpImplementation->mSounds.erase(tFoundIt);
}

int AudioEngine::PlaySound(const string& strSoundName, const Vector3& vPos, float fVolumedB){
    
    int nChannelId = sgpImplementation->mnNextChannelId++;
    auto tFoundIt = sgpImplementation->mSounds.find(strSoundName);
    if(tFoundIt != sgpImplementation->mSounds.end())
    {
        LoadSound(strSoundName);
        tFoundIt = sgpImplementation->mSounds.find(strSoundName);
        if(tFoundIt==sgpImplementation->mSounds.end())
        {
            return nChannelId;
        }
    }
    return nChannelId;
}
// ---------------

/* --------------
 Channel and Orientation Function Declarations
 - Stop Channel
 - Pause Channel
 - Stop All Channels
 - Set 3D Listener and Orientation
 - Set Channel 3D Position
 - Set Channel Volume
 */

void AudioEngine::SetChannelVolume(int nChannelId, float fVolumedB){
    auto tFoundIt = sgpImplementation->mChannels.find(nChannelId);
    if(tFoundIt == sgpImplementation->mChannels.end())
        return;
}

/* --------------
 Booleans and Analytics
 - Is Playing?
 - Is Event Playing?
 - Is Bank Playing?
 - Is Sound Playing?
 - Is Channel Playing?
 - Is Clipping?
 
 */
//bool isClipping(){
//}

/* --------------
 Conversion Function Declarations
 - dB to Amplitude
 - Amplitude to dB
 */
float AudioEngine::dBToVolume(float dB){
    return powf(10.f, 0.05f * dB);
    // aka: amplitude = 10^(dB/20)
}

float AudioEngine::VolumeTodB(float volume){
    return 20.f*log10f(volume);
    // aka: dB = 20 * log10(amplitude)
}
// ---------------
