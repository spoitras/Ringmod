/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "LFO.h"
#include "SineWave.h"
#include "Math.h"



//==============================================================================
/**
*/
class RingmodAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    RingmodAudioProcessor();
    ~RingmodAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock);
    void releaseResources();

    void processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages);

    //==============================================================================
    AudioProcessorEditor* createEditor();
    bool hasEditor() const;

    //==============================================================================
    const String getName() const;

    int getNumParameters();

    float getParameter (int index);
    void setParameter (int index, float newValue);

    const String getParameterName (int index);
    const String getParameterText (int index);

    const String getInputChannelName (int channelIndex) const;
    const String getOutputChannelName (int channelIndex) const;
    bool isInputChannelStereoPair (int index) const;
    bool isOutputChannelStereoPair (int index) const;

    bool acceptsMidi() const;
    bool producesMidi() const;
    bool silenceInProducesSilenceOut() const;
    double getTailLengthSeconds() const;

    //==============================================================================
    int getNumPrograms() override                                               { return 0; }
    int getCurrentProgram() override                                            { return 0; }
    void setCurrentProgram (int /*index*/) override                             {}
    const String getProgramName (int /*index*/) override                        { return String::empty; }
    void changeProgramName (int /*index*/, const String& /*newName*/) override  {}

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    enum Parameters{MasterBypass=0,Frequency,ModSetting,Mix,Drive,LFOAmount,LFORate,LFOWaveType,totalNumParam};
    
    void setModFreq(float low, float high){lowFreq=low;highFreq=high;};
    float lin2Log(float logMin, float logMax, float linValue){
        float linMin = 0.01f;
        float linMax = 1.0f;
        
        float output;
        
        float e =2.718281828;
        
        float a,b;
        
        b =  (log(logMin / logMax) / (linMin - linMax));
        a = logMin / pow(e, (linMin * b));
        
        output = a * pow(e, (b*linValue));
        
        return output;
        
    };
private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RingmodAudioProcessor)
    float UserParams[totalNumParam];
    stk::SineWave mySine;
    LFO myLFO;
    float lowFreq;
    float highFreq;
    float lowRate;
    float highRate;
    float lowAmt;
    float highAmt;
};

#endif  // PLUGINPROCESSOR_H_INCLUDED
