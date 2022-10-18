//
//  BusStructure.h
//  AudioEngine_NoAPI
//
//  Created by John Rupsch on 10/15/22.
//
#include <string>
#ifndef BusStructure_h
#define BusStructure_h

class Bus(){
    struct Bus{
        string name = "BusName";
        int* busPtr = nullptr;
        int numChildren = 0;
    }
    
    // Creators
    void createBus();
    
    // Setters
    void setBus();
    
    //Getters
    void getBus();
    
    // Analytics/Bools
    bool isBusPlaying();
    
};


void Bus::createBus(){
    
}

bool Bus::isBusPlaying(){
    
}
#endif /* BusStructure_h */
