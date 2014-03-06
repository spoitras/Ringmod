/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
RingmodAudioProcessor::RingmodAudioProcessor()
{
    UserParams[MasterBypass]=0.0f;
    UserParams[ModSetting]=0.0f;
    UserParams[Mix]=1.0f;
    UserParams[Drive]=0.0f;
    UserParams[LFOAmount]=0.0f;
    UserParams[LFORate]=0.01f;
    UserParams[Frequency]=0.01f;
    UserParams[LFOWaveType]=0.0f;
    
    
    lowFreq = 0.6;
    highFreq = 80;
    lowRate = 0.1f;
    highRate = 25.0f;
    lowAmt = 1.0f;
    highAmt = 4.0f;
    
    
    myLFO.setRate(lin2Log(lowRate, highRate, UserParams[LFORate]));
    myLFO.setAmount(UserParams[LFOAmount]*(highAmt-lowAmt)+lowAmt);
    myLFO.setWaveType(LFO::Sine);
    
    mySine.setFrequency(lin2Log(lowFreq, highFreq, UserParams[Frequency]));
    stk::Stk::setSampleRate(44100);
    
}

RingmodAudioProcessor::~RingmodAudioProcessor()
{
}

//==============================================================================
const String RingmodAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int RingmodAudioProcessor::getNumParameters()
{
    return totalNumParam;
}

float RingmodAudioProcessor::getParameter (int index)
{
    switch (index) {
        case MasterBypass:
            return UserParams[MasterBypass];
        case Frequency:
            return UserParams[Frequency];
        case ModSetting:
            return UserParams[ModSetting];
        case Mix:
            return UserParams[Mix];
        case Drive:
            return UserParams[Drive];
        case LFOAmount:
            return UserParams[LFOAmount];
        case LFORate:
            return UserParams[LFORate];
        case LFOWaveType:
            return UserParams[LFOWaveType];
        default:
            return 0.0f;
    }
}

void RingmodAudioProcessor::setParameter (int index, float newValue)
{
    switch (index) {
        case MasterBypass:
            UserParams[MasterBypass]=newValue;
            break;
        
        case Frequency:
            UserParams[Frequency]=newValue;
            mySine.setFrequency(lin2Log(lowFreq, highFreq, UserParams[Frequency]));
            break;
        case ModSetting:
            UserParams[ModSetting]=newValue;
            if (UserParams[ModSetting]==1.0f) {
                setModFreq(30, 4000);
                mySine.setFrequency(lin2Log(lowFreq, highFreq, UserParams[Frequency]));
            }else{
                setModFreq(0.6, 80);
                mySine.setFrequency(lin2Log(lowFreq, highFreq, UserParams[Frequency]));
            }
            break;
        case Mix:
            UserParams[Mix]=newValue;
            break;
        case Drive:
            UserParams[Drive]=newValue;
            break;
        case LFOAmount:
            UserParams[LFOAmount]=newValue;
            myLFO.setAmount(UserParams[LFOAmount]*(highAmt-lowAmt)+lowAmt);
            break;
        case LFORate:
            UserParams[LFORate]=newValue;
            myLFO.setRate(lin2Log(lowRate, highRate, UserParams[LFORate]));
            break;
        case LFOWaveType:
            UserParams[LFOWaveType]=newValue;
            if (UserParams[LFOWaveType]==0.0f) {
                myLFO.setWaveType(LFO::Sine);
            }else{
                myLFO.setWaveType(LFO::Square);
            }
            break;
        default:
            break;
    }
}

const String RingmodAudioProcessor::getParameterName (int index)
{
    switch (index) {
        case MasterBypass:
            return "Master Bypass";
        case Frequency:
            return "Frequency";
        case ModSetting:
            return "Modulation Setting";
        case Mix:
            return "Dry/Wet Mix";
        case Drive:
            return "Drive";
        case LFOAmount:
            return "LFO Amount";
        case LFORate:
            return "LFO Rate";
        case LFOWaveType:
            return "LFO Wave Type";
        default:
            return String::empty;
    }
    
    return String::empty;
}

const String RingmodAudioProcessor::getParameterText (int index)
{
    switch (index) {
        case Frequency:
            return String(lin2Log(lowFreq, highFreq, UserParams[Frequency]));
        case ModSetting:
            if (UserParams[ModSetting]==0.0f) {
                return "Low";
            }else{
                return "High";
            }
        case Mix:
            return String((int)(UserParams[Mix]*100));
        case Drive:
            return String(1+UserParams[Drive]);
        case LFOAmount:
            return String((int)(UserParams[LFOAmount]*100));
        case LFORate:
            return String(lin2Log(lowRate, highRate, UserParams[LFORate]));
        case LFOWaveType:
            if (UserParams[LFOWaveType]==0.0f) {
                return "Sine";
            }else{
                return "Square";
            }
        default:
        return String(UserParams[index]);//return parameter value as string
    }
}

const String RingmodAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String RingmodAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool RingmodAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool RingmodAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool RingmodAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool RingmodAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool RingmodAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double RingmodAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

//==============================================================================
void RingmodAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void RingmodAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void RingmodAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...

    
    if (stk::Stk::sampleRate()!=RingmodAudioProcessor::getSampleRate()) {
        stk::Stk::setSampleRate(RingmodAudioProcessor::getSampleRate());
    }
    
    if(UserParams[MasterBypass]!=1){
       
        float* leftData = buffer.getSampleData(0);
        float* rightData = buffer.getSampleData(1);
        
            for (int i=0; i<buffer.getNumSamples(); i++) {
                
                *(leftData+i) = *(leftData+i) * (UserParams[Drive]+1.0f);
                *(rightData+i) = *(rightData+i) * (UserParams[Drive]+1.0f);
                
                if (UserParams[LFOAmount]>0) {
                    mySine.setFrequency((lin2Log(lowFreq, highFreq, UserParams[Frequency])* myLFO.getTick()) + (lin2Log(lowFreq, highFreq, UserParams[Frequency])));
                }else{
                    mySine.setFrequency((lin2Log(lowFreq, highFreq, UserParams[Frequency])) + (lin2Log(lowFreq, highFreq, UserParams[Frequency])));
                }
                
                float tick = mySine.tick();
                float leftEffect = *(leftData+i) * tick;
                float rightEffect = *(rightData+i) * tick;
                
                *(leftData+i)=(*(leftData+i) * (1.0f-UserParams[Mix])) + (UserParams[Mix] * leftEffect);
                
                *(rightData+i)=(*(rightData+i) * (1.0f-UserParams[Mix])) + (UserParams[Mix] * rightEffect);
            }
    }
}

//==============================================================================
bool RingmodAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* RingmodAudioProcessor::createEditor()
{
    return new RingmodAudioProcessorEditor (this);
}

//==============================================================================



void RingmodAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.

    // Create an outer XML element..
    XmlElement xml ("ringmodsettings");
    
    // add some attributes to it..
    xml.setAttribute ("Bypass", UserParams[MasterBypass]);
    xml.setAttribute ("Frequency", UserParams[Frequency]);
    xml.setAttribute("ModSetting", UserParams[ModSetting]);
    xml.setAttribute("Drive", UserParams[Drive]);
    xml.setAttribute("LFOAmount", UserParams[LFOAmount]);
    xml.setAttribute("LFORate", UserParams[LFORate]);
    xml.setAttribute("LFOWaveType", UserParams[LFOWaveType]);
    
    
    // then use this helper function to stuff it into the binary blob and return it..
    copyXmlToBinary (xml, destData);


}


void RingmodAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.

    ScopedPointer<XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));
    
    if (xmlState != nullptr)
    {

        // make sure that it's actually our type of XML object..
        if (xmlState->hasTagName ("ringmodsettnigs"))
        {
            // ok, now pull out our parameters..
            setParameterNotifyingHost(MasterBypass,(float) xmlState->getDoubleAttribute ("Bypass", UserParams[MasterBypass]));
            setParameterNotifyingHost(Frequency,(float) xmlState->getDoubleAttribute ("Frequency", UserParams[Frequency]));
            setParameterNotifyingHost(ModSetting,(float)xmlState->getDoubleAttribute("ModSetting",UserParams[ModSetting]));
            setParameterNotifyingHost(Drive, (float)xmlState->getDoubleAttribute("Drive",UserParams[Drive]));
            setParameterNotifyingHost(LFOAmount, (float)xmlState->getDoubleAttribute("LFOAmount",UserParams[LFOAmount]));
            setParameterNotifyingHost(LFORate, (float)xmlState->getDoubleAttribute("LFORate",UserParams[LFORate]));
            setParameterNotifyingHost(LFOWaveType, (float)xmlState->getDoubleAttribute("LFOWaveType",UserParams[LFOWaveType]));
        }
    }

}


//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new RingmodAudioProcessor();
}



