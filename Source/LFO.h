/*
  ==============================================================================

    LFO.h
    Created: 29 Jan 2014 12:07:51pm
    Author:  Sylvain Poitras

  ==============================================================================
*/

#ifndef LFO_H_INCLUDED
#define LFO_H_INCLUDED
#include "..\..\JuceLibraryCode\modules\stk\stk\SineWave.h"


class LFO{
public:
    enum waveTypes{Sine=0,Square,TotalWaveNum};

    void setWaveType(waveTypes waveType){
        switch (waveType) {
            case Sine:
                LFOWaves[Sine]=true;
                LFOWaves[Square]=false;
                break;
            case Square:
                LFOWaves[Sine]=false;
                LFOWaves[Square]=true;
            default:
                break;
        }
    };
    
    void setRate(float newRate){
        rate = newRate;
        mySine.setFrequency(rate);
    };
        
    void setAmount(float newAmount){
        amount = newAmount;
    };

    
    float getTick(){
        currentTick = mySine.tick();
        
        if (LFOWaves[Sine]) {
            return currentTick * amount;
        }else{
            return sgn(currentTick) * amount;
        }
    };

    
    
private:
    bool LFOWaves[TotalWaveNum];
    float rate;
    float amount;
    float currentTick;
    
    int sgn(float val) {
        return (float(0) < val) - (val < float(0));
    }
    
    stk::SineWave mySine;
};












#endif  // LFO_H_INCLUDED
