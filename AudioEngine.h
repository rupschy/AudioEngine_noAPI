//
//  AudioEngine.h
//  AudioEngine_NoAPI
//
//  Created by John Rupsch on 10/15/22.
//

#ifndef AudioEngine_h
#define AudioEngine_h
// Header files
#include <math.h>
#include <stdio.h>
// Inclusions
#include <thread>
#include <string>
#include <vector>
#include <map>
#include <iostream>



using namespace std;
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Implementation {
    // Constructor
    Implementation();
    // Destructor
    ~Implementation();
    
    void Update();
    
    int mnNextChannelId;
    
    // TypeDefs
    typedef map<string, float*> SoundMap;
    typedef map<int, int*> ChannelMap;
    typedef map<string, string*> EventMap;
    typedef map<string, float*> BankMap;
    // Instantiate
    SoundMap mSounds;
    ChannelMap mChannels;
    EventMap mEvents;
    BankMap mBanks;
};

class AudioEngine
{
public:
    static void Init();
    static void Update();
    static void Shutdown();
    // static int ErrorCheck();
    
    // Jukebox Functions
    void LoadSound(const string& strSoundName, bool b3d=true, bool bLooping=false, bool bStream = false);
    void UnloadSound(const string& strSoundName);
    void Set3dListenerAndOrientation(const Vector3& vPosition, const Vector3& vLook, const Vector3& vUp);
    int PlaySound(const string& strSoundName, const Vector3& vPos=Vector3{0,0,0}, float fVolumedB = 0.f);
    
    // Channel Functions
    void StopChannel(int nChannelId, float fFadeTimeSeconds = 0.f);
    void PauseChannel(int nChannelId);
    void StopAllChannels();
    void SetChannel3dPosition(int nChannelId, const Vector3& vPosition);
    void SetChannelVolume(int nChannelId, float fVolumedB);
    
    // Bank Functions
    void LoadBank(const string& strBankName);
    
    // Event Functions
    void LoadEvent(const string& strEventName);
    void PlayEvent(const string& strEventName);
    void StopEvent(const string& strEventName);
    
    // Analytics and Bools
    bool IsPlaying(int nChannelId) const;
    bool IsEventPlaying(const string &strEventName) const;
    bool IsBankPlaying(const string &strBankName) const;
    bool IsSoundPlaying(const string &strSoundName) const;
    bool IsChannelPlaying(const int &nChannelId) const;
    bool IsClipping();
    
    // Conversions
    float dBToVolume(float dB);
    float VolumeTodB(float volume);
    
    // Plugin effects
    
};

#endif /* AudioEngine_h */
