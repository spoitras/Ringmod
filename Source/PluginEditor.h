/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_A33AD9ADFE214707__
#define __JUCE_HEADER_A33AD9ADFE214707__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class RingmodAudioProcessorEditor  : public AudioProcessorEditor,
                                     public Timer,
                                     public SliderListener,
                                     public ButtonListener
{
public:
    //==============================================================================
    RingmodAudioProcessorEditor (RingmodAudioProcessor* ownerFilter);
    ~RingmodAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback();
    RingmodAudioProcessor* getProcessor() const
    {return static_cast <RingmodAudioProcessor*>(getAudioProcessor());}
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<GroupComponent> groupComponent;
    ScopedPointer<Label> freTitle;
    ScopedPointer<Slider> FreqSlider;
    ScopedPointer<TextButton> MainBypassBtn;
    ScopedPointer<Label> FreqLabel;
    ScopedPointer<GroupComponent> groupComponent2;
    ScopedPointer<Label> MixTitle;
    ScopedPointer<Slider> MixSlider;
    ScopedPointer<Label> MixLabel;
    ScopedPointer<Label> AmountTitle;
    ScopedPointer<Slider> AmtSlider;
    ScopedPointer<Label> AmtLabel;
    ScopedPointer<Label> RateTtitle;
    ScopedPointer<Slider> RateSlider;
    ScopedPointer<Label> RateLAbel;
    ScopedPointer<Label> DriveTitle;
    ScopedPointer<Slider> DriveSlider;
    ScopedPointer<Label> DriveLabel;
    ScopedPointer<ToggleButton> SquareToggle;
    ScopedPointer<ToggleButton> SineToggle;
    ScopedPointer<ToggleButton> LowToggle;
    ScopedPointer<ToggleButton> HiToggle;
    ScopedPointer<TextButton> LFOIndicator;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RingmodAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_A33AD9ADFE214707__
