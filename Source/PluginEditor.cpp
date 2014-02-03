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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
RingmodAudioProcessorEditor::RingmodAudioProcessorEditor (RingmodAudioProcessor* ownerFilter)
    : AudioProcessorEditor(ownerFilter)
{
    addAndMakeVisible (groupComponent = new GroupComponent ("new group",
                                                            TRANS("MODUATION")));
    groupComponent->setTextLabelPosition (Justification::centred);
    groupComponent->setColour (GroupComponent::outlineColourId, Colours::cadetblue);
    groupComponent->setColour (GroupComponent::textColourId, Colour (0xffee5d45));

    addAndMakeVisible (freTitle = new Label ("FreqTitle",
                                             TRANS("FREQUENCY")));
    freTitle->setFont (Font (36.00f, Font::plain));
    freTitle->setJustificationType (Justification::centredLeft);
    freTitle->setEditable (false, false, false);
    freTitle->setColour (Label::textColourId, Colours::cadetblue);
    freTitle->setColour (TextEditor::textColourId, Colours::black);
    freTitle->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (FreqSlider = new Slider ("FreqSlider"));
    FreqSlider->setTooltip (TRANS("Modulation Frequency"));
    FreqSlider->setRange (0.01, 1, 0.01);
    FreqSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    FreqSlider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    FreqSlider->setColour (Slider::thumbColourId, Colours::cadetblue);
    FreqSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffee5d45));
    FreqSlider->setColour (Slider::rotarySliderOutlineColourId, Colours::cadetblue);
    FreqSlider->setColour (Slider::textBoxTextColourId, Colours::cadetblue);
    FreqSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    FreqSlider->setColour (Slider::textBoxHighlightColourId, Colour (0x001111ee));
    FreqSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    FreqSlider->addListener (this);

    addAndMakeVisible (MainBypassBtn = new TextButton ("MainBypassBtn"));
    MainBypassBtn->setTooltip (TRANS("Bypass Button"));
    MainBypassBtn->setButtonText (TRANS("BYPASS"));
    MainBypassBtn->addListener (this);
    MainBypassBtn->setColour (TextButton::buttonColourId, Colours::cadetblue);
    MainBypassBtn->setColour (TextButton::buttonOnColourId, Colour (0xffee5d45));

    addAndMakeVisible (FreqLabel = new Label ("new label",
                                              TRANS("freq label")));
    FreqLabel->setFont (Font (15.00f, Font::plain));
    FreqLabel->setJustificationType (Justification::centred);
    FreqLabel->setEditable (false, false, false);
    FreqLabel->setColour (Label::textColourId, Colours::cadetblue);
    FreqLabel->setColour (TextEditor::textColourId, Colours::black);
    FreqLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (groupComponent2 = new GroupComponent ("new group",
                                                             TRANS("LFO")));
    groupComponent2->setTextLabelPosition (Justification::centred);
    groupComponent2->setColour (GroupComponent::outlineColourId, Colours::cadetblue);
    groupComponent2->setColour (GroupComponent::textColourId, Colour (0xffee5d45));

    addAndMakeVisible (MixTitle = new Label ("MixTitle",
                                             TRANS("MIX")));
    MixTitle->setFont (Font (36.00f, Font::plain));
    MixTitle->setJustificationType (Justification::centred);
    MixTitle->setEditable (false, false, false);
    MixTitle->setColour (Label::textColourId, Colours::cadetblue);
    MixTitle->setColour (TextEditor::textColourId, Colours::black);
    MixTitle->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (MixSlider = new Slider ("MixSlider"));
    MixSlider->setTooltip (TRANS("Dry / Wet Mix"));
    MixSlider->setRange (0, 1, 0);
    MixSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    MixSlider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    MixSlider->setColour (Slider::thumbColourId, Colours::cadetblue);
    MixSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffee5d45));
    MixSlider->setColour (Slider::rotarySliderOutlineColourId, Colours::cadetblue);
    MixSlider->setColour (Slider::textBoxTextColourId, Colours::cadetblue);
    MixSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    MixSlider->setColour (Slider::textBoxHighlightColourId, Colour (0x001111ee));
    MixSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    MixSlider->addListener (this);

    addAndMakeVisible (MixLabel = new Label ("MixLabek",
                                             TRANS("Mix label")));
    MixLabel->setFont (Font (15.00f, Font::plain));
    MixLabel->setJustificationType (Justification::centred);
    MixLabel->setEditable (false, false, false);
    MixLabel->setColour (Label::textColourId, Colours::cadetblue);
    MixLabel->setColour (TextEditor::textColourId, Colours::black);
    MixLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (AmountTitle = new Label ("AmountTitle",
                                                TRANS("AMOUNT")));
    AmountTitle->setFont (Font (36.00f, Font::plain));
    AmountTitle->setJustificationType (Justification::centred);
    AmountTitle->setEditable (false, false, false);
    AmountTitle->setColour (Label::textColourId, Colours::cadetblue);
    AmountTitle->setColour (TextEditor::textColourId, Colours::black);
    AmountTitle->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (AmtSlider = new Slider ("AmtSlider"));
    AmtSlider->setTooltip (TRANS("LFO Amount"));
    AmtSlider->setRange (0, 1, 0);
    AmtSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    AmtSlider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    AmtSlider->setColour (Slider::thumbColourId, Colours::cadetblue);
    AmtSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffee5d45));
    AmtSlider->setColour (Slider::rotarySliderOutlineColourId, Colours::cadetblue);
    AmtSlider->setColour (Slider::textBoxTextColourId, Colours::cadetblue);
    AmtSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    AmtSlider->setColour (Slider::textBoxHighlightColourId, Colour (0x001111ee));
    AmtSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    AmtSlider->addListener (this);

    addAndMakeVisible (AmtLabel = new Label ("AmtLabel",
                                             TRANS("Amount Label")));
    AmtLabel->setFont (Font (15.00f, Font::plain));
    AmtLabel->setJustificationType (Justification::centred);
    AmtLabel->setEditable (false, false, false);
    AmtLabel->setColour (Label::textColourId, Colours::cadetblue);
    AmtLabel->setColour (TextEditor::textColourId, Colours::black);
    AmtLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (RateTtitle = new Label ("RateTitle",
                                               TRANS("RATE")));
    RateTtitle->setFont (Font (36.00f, Font::plain));
    RateTtitle->setJustificationType (Justification::centred);
    RateTtitle->setEditable (false, false, false);
    RateTtitle->setColour (Label::textColourId, Colours::cadetblue);
    RateTtitle->setColour (TextEditor::textColourId, Colours::black);
    RateTtitle->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (RateSlider = new Slider ("RateSlder"));
    RateSlider->setTooltip (TRANS("LFO Rate"));
    RateSlider->setRange (0.01, 1, 0.01);
    RateSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    RateSlider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    RateSlider->setColour (Slider::thumbColourId, Colours::cadetblue);
    RateSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffee5d45));
    RateSlider->setColour (Slider::rotarySliderOutlineColourId, Colours::cadetblue);
    RateSlider->setColour (Slider::textBoxTextColourId, Colours::cadetblue);
    RateSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    RateSlider->setColour (Slider::textBoxHighlightColourId, Colour (0x001111ee));
    RateSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    RateSlider->addListener (this);

    addAndMakeVisible (RateLAbel = new Label ("RateLabel",
                                              TRANS("Rate Label")));
    RateLAbel->setFont (Font (15.00f, Font::plain));
    RateLAbel->setJustificationType (Justification::centred);
    RateLAbel->setEditable (false, false, false);
    RateLAbel->setColour (Label::textColourId, Colours::cadetblue);
    RateLAbel->setColour (TextEditor::textColourId, Colours::black);
    RateLAbel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (DriveTitle = new Label ("DriveTitle",
                                               TRANS("GAIN")));
    DriveTitle->setFont (Font (36.00f, Font::plain));
    DriveTitle->setJustificationType (Justification::centred);
    DriveTitle->setEditable (false, false, false);
    DriveTitle->setColour (Label::textColourId, Colours::cadetblue);
    DriveTitle->setColour (TextEditor::textColourId, Colours::black);
    DriveTitle->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (DriveSlider = new Slider ("DriveSlider"));
    DriveSlider->setTooltip (TRANS("Pre-effect input Gain"));
    DriveSlider->setRange (0, 1, 0);
    DriveSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    DriveSlider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    DriveSlider->setColour (Slider::thumbColourId, Colours::cadetblue);
    DriveSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffee5d45));
    DriveSlider->setColour (Slider::rotarySliderOutlineColourId, Colours::cadetblue);
    DriveSlider->setColour (Slider::textBoxTextColourId, Colours::cadetblue);
    DriveSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    DriveSlider->setColour (Slider::textBoxHighlightColourId, Colour (0x001111ee));
    DriveSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    DriveSlider->addListener (this);

    addAndMakeVisible (DriveLabel = new Label ("DriveLabel",
                                               TRANS("Drive Label")));
    DriveLabel->setFont (Font (15.00f, Font::plain));
    DriveLabel->setJustificationType (Justification::centred);
    DriveLabel->setEditable (false, false, false);
    DriveLabel->setColour (Label::textColourId, Colours::cadetblue);
    DriveLabel->setColour (TextEditor::textColourId, Colours::black);
    DriveLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (SquareToggle = new ToggleButton ("new toggle button"));
    SquareToggle->setTooltip (TRANS("LFO Square Wave"));
    SquareToggle->setButtonText (TRANS("SQUARE"));
    SquareToggle->setRadioGroupId (1);
    SquareToggle->addListener (this);
    SquareToggle->setColour (ToggleButton::textColourId, Colours::cadetblue);

    addAndMakeVisible (SineToggle = new ToggleButton ("new toggle button"));
    SineToggle->setTooltip (TRANS("LFO Sine Wave"));
    SineToggle->setButtonText (TRANS("SINE"));
    SineToggle->setRadioGroupId (1);
    SineToggle->addListener (this);
    SineToggle->setToggleState (true, dontSendNotification);
    SineToggle->setColour (ToggleButton::textColourId, Colours::cadetblue);

    addAndMakeVisible (LowToggle = new ToggleButton ("new toggle button"));
    LowToggle->setTooltip (TRANS("Low Frequencies"));
    LowToggle->setButtonText (TRANS("LOW"));
    LowToggle->setRadioGroupId (2);
    LowToggle->addListener (this);
    LowToggle->setToggleState (true, dontSendNotification);
    LowToggle->setColour (ToggleButton::textColourId, Colours::cadetblue);

    addAndMakeVisible (HiToggle = new ToggleButton ("new toggle button"));
    HiToggle->setTooltip (TRANS("High Frequencies"));
    HiToggle->setButtonText (TRANS("HIGH"));
    HiToggle->setRadioGroupId (2);
    HiToggle->addListener (this);
    HiToggle->setColour (ToggleButton::textColourId, Colours::cadetblue);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 800);


    //[Constructor] You can add your own custom stuff here..

    startTimer(20);//starts timer with interval of 50ms
    MainBypassBtn->setClickingTogglesState(true);


    //[/Constructor]
}

RingmodAudioProcessorEditor::~RingmodAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    groupComponent = nullptr;
    freTitle = nullptr;
    FreqSlider = nullptr;
    MainBypassBtn = nullptr;
    FreqLabel = nullptr;
    groupComponent2 = nullptr;
    MixTitle = nullptr;
    MixSlider = nullptr;
    MixLabel = nullptr;
    AmountTitle = nullptr;
    AmtSlider = nullptr;
    AmtLabel = nullptr;
    RateTtitle = nullptr;
    RateSlider = nullptr;
    RateLAbel = nullptr;
    DriveTitle = nullptr;
    DriveSlider = nullptr;
    DriveLabel = nullptr;
    SquareToggle = nullptr;
    SineToggle = nullptr;
    LowToggle = nullptr;
    HiToggle = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void RingmodAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff292729));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void RingmodAudioProcessorEditor::resized()
{
    groupComponent->setBounds (proportionOfWidth (0.6800f), proportionOfHeight (0.0500f), proportionOfWidth (0.2900f), proportionOfHeight (0.9000f));
    freTitle->setBounds (proportionOfWidth (0.7000f), proportionOfHeight (0.6500f), proportionOfWidth (0.2500f), 45);
    FreqSlider->setBounds (proportionOfWidth (0.7000f), (proportionOfHeight (0.6500f)) + (45) - -5, proportionOfWidth (0.2500f), proportionOfHeight (0.2000f));
    MainBypassBtn->setBounds (proportionOfWidth (0.3750f), proportionOfHeight (0.7500f), proportionOfWidth (0.2500f), proportionOfHeight (0.1000f));
    FreqLabel->setBounds (proportionOfWidth (0.7000f), ((proportionOfHeight (0.6500f)) + (45) - -5) + (proportionOfHeight (0.2000f)) - 11, proportionOfWidth (0.2500f), 24);
    groupComponent2->setBounds (proportionOfWidth (0.0300f), proportionOfHeight (0.0500f), proportionOfWidth (0.2900f), proportionOfHeight (0.9000f));
    MixTitle->setBounds (proportionOfWidth (0.7000f), proportionOfHeight (0.0800f), proportionOfWidth (0.2500f), 45);
    MixSlider->setBounds (proportionOfWidth (0.7000f), (proportionOfHeight (0.0800f)) + (45), proportionOfWidth (0.2500f), proportionOfHeight (0.2000f));
    MixLabel->setBounds (proportionOfWidth (0.7000f), ((proportionOfHeight (0.0800f)) + (45)) + (proportionOfHeight (0.2000f)) - 11, proportionOfWidth (0.2500f), 24);
    AmountTitle->setBounds (proportionOfWidth (0.0500f), proportionOfHeight (0.0800f), proportionOfWidth (0.2500f), 45);
    AmtSlider->setBounds (proportionOfWidth (0.0500f), (proportionOfHeight (0.0800f)) + (45), proportionOfWidth (0.2500f), proportionOfHeight (0.2000f));
    AmtLabel->setBounds (proportionOfWidth (0.0500f), ((proportionOfHeight (0.0800f)) + (45)) + (proportionOfHeight (0.2000f)) - 11, proportionOfWidth (0.2500f), 24);
    RateTtitle->setBounds (proportionOfWidth (0.0500f), proportionOfHeight (0.6500f), proportionOfWidth (0.2500f), 45);
    RateSlider->setBounds (proportionOfWidth (0.0500f), (proportionOfHeight (0.6500f)) + (45), proportionOfWidth (0.2500f), proportionOfHeight (0.2000f));
    RateLAbel->setBounds (proportionOfWidth (0.0500f), ((proportionOfHeight (0.6500f)) + (45)) + (proportionOfHeight (0.2000f)) - 11, proportionOfWidth (0.2500f), 24);
    DriveTitle->setBounds (proportionOfWidth (0.3750f), proportionOfHeight (0.0800f), proportionOfWidth (0.2500f), 45);
    DriveSlider->setBounds (proportionOfWidth (0.3750f), (proportionOfHeight (0.0800f)) + (45), proportionOfWidth (0.2500f), proportionOfHeight (0.2000f));
    DriveLabel->setBounds (proportionOfWidth (0.3750f), ((proportionOfHeight (0.0800f)) + (45)) + (proportionOfHeight (0.2000f)) - 11, proportionOfWidth (0.2500f), 24);
    SquareToggle->setBounds (proportionOfWidth (0.0950f), 392, proportionOfWidth (0.1250f), proportionOfHeight (0.0300f));
    SineToggle->setBounds (proportionOfWidth (0.0950f), 360, proportionOfWidth (0.1250f), proportionOfHeight (0.0300f));
    LowToggle->setBounds (proportionOfWidth (0.7600f), 360, proportionOfWidth (0.1250f), proportionOfHeight (0.0300f));
    HiToggle->setBounds (proportionOfWidth (0.7600f), 392, proportionOfWidth (0.1250f), proportionOfHeight (0.0300f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void RingmodAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    RingmodAudioProcessor* ourProcessor = getProcessor();
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == FreqSlider)
    {
        //[UserSliderCode_FreqSlider] -- add your slider handling code here..
        ourProcessor->setParameterNotifyingHost(RingmodAudioProcessor::Frequency, FreqSlider->getValue());
        FreqLabel->setText(ourProcessor->getParameterText(RingmodAudioProcessor::Frequency), dontSendNotification);
        //[/UserSliderCode_FreqSlider]
    }
    else if (sliderThatWasMoved == MixSlider)
    {
        //[UserSliderCode_MixSlider] -- add your slider handling code here..
        ourProcessor->setParameterNotifyingHost(RingmodAudioProcessor::Mix, MixSlider->getValue());
        MixLabel->setText(ourProcessor->getParameterText(RingmodAudioProcessor::Mix),dontSendNotification);
        //[/UserSliderCode_MixSlider]
    }
    else if (sliderThatWasMoved == AmtSlider)
    {
        //[UserSliderCode_AmtSlider] -- add your slider handling code here..
        ourProcessor->setParameterNotifyingHost(RingmodAudioProcessor::LFOAmount, AmtSlider->getValue());
        AmtLabel->setText(ourProcessor->getParameterText(RingmodAudioProcessor::LFOAmount), dontSendNotification);
        //[/UserSliderCode_AmtSlider]
    }
    else if (sliderThatWasMoved == RateSlider)
    {
        //[UserSliderCode_RateSlider] -- add your slider handling code here..
        ourProcessor->setParameterNotifyingHost(RingmodAudioProcessor::LFORate, RateSlider->getValue());
        RateLAbel->setText(ourProcessor->getParameterText(RingmodAudioProcessor::LFORate), dontSendNotification);
        //[/UserSliderCode_RateSlider]
    }
    else if (sliderThatWasMoved == DriveSlider)
    {
        //[UserSliderCode_DriveSlider] -- add your slider handling code here..
        ourProcessor->setParameterNotifyingHost(RingmodAudioProcessor::Drive, DriveSlider->getValue());
        DriveLabel->setText(ourProcessor->getParameterText(RingmodAudioProcessor::Drive), dontSendNotification);
        //[/UserSliderCode_DriveSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void RingmodAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
        RingmodAudioProcessor* ourProcessor = getProcessor();
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == MainBypassBtn)
    {
        //[UserButtonCode_MainBypassBtn] -- add your button handler code here..
        ourProcessor->setParameterNotifyingHost(RingmodAudioProcessor::MasterBypass, MainBypassBtn->getToggleState());



        //[/UserButtonCode_MainBypassBtn]
    }
    else if (buttonThatWasClicked == SquareToggle)
    {
        //[UserButtonCode_SquareToggle] -- add your button handler code here..
        ourProcessor->setParameterNotifyingHost(RingmodAudioProcessor::LFOWaveType, 1.0f);
        //[/UserButtonCode_SquareToggle]
    }
    else if (buttonThatWasClicked == SineToggle)
    {
        //[UserButtonCode_SineToggle] -- add your button handler code here..
        ourProcessor->setParameterNotifyingHost(RingmodAudioProcessor::LFOWaveType, 0.0f);
        //[/UserButtonCode_SineToggle]
    }
    else if (buttonThatWasClicked == LowToggle)
    {
        //[UserButtonCode_LowToggle] -- add your button handler code here..
        ourProcessor->setParameterNotifyingHost(RingmodAudioProcessor::ModSetting,0.0f);
        FreqLabel->setText(ourProcessor->getParameterText(RingmodAudioProcessor::Frequency), dontSendNotification);

        //[/UserButtonCode_LowToggle]
    }
    else if (buttonThatWasClicked == HiToggle)
    {
        //[UserButtonCode_HiToggle] -- add your button handler code here..
        ourProcessor->setParameterNotifyingHost(RingmodAudioProcessor::ModSetting, 1.0f);
        FreqLabel->setText(ourProcessor->getParameterText(RingmodAudioProcessor::Frequency), dontSendNotification);
        //[/UserButtonCode_HiToggle]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void RingmodAudioProcessorEditor::timerCallback()
{
        //exchange any data you want between UI elements and the Plugin "ourProcessor"

    RingmodAudioProcessor* ourProcessor = getProcessor();

    if (ourProcessor->getParameter(RingmodAudioProcessor::MasterBypass) != MainBypassBtn->getToggleState()) {
        MainBypassBtn->setToggleState(1.0f == ourProcessor->getParameter(RingmodAudioProcessor::MasterBypass), juce::dontSendNotification);
    }

    if (ourProcessor->getParameter(RingmodAudioProcessor::Frequency)!=FreqSlider->getValue()) {
        FreqSlider->setValue(ourProcessor->getParameter(RingmodAudioProcessor::Frequency), juce::dontSendNotification);
        FreqLabel->setText(ourProcessor->getParameterText(RingmodAudioProcessor::Frequency), dontSendNotification);
    }

    if (FreqLabel->getText().compare(ourProcessor->getParameterText(RingmodAudioProcessor::Frequency))!=0) {

        FreqLabel->setText(ourProcessor->getParameterText(RingmodAudioProcessor::Frequency), dontSendNotification);

    }

    if (MixLabel->getText().compare(ourProcessor->getParameterText(RingmodAudioProcessor::Mix))) {
        MixLabel->setText(ourProcessor->getParameterText(RingmodAudioProcessor::Mix), dontSendNotification);
    }

    if (ourProcessor->getParameter(RingmodAudioProcessor::Mix)!=MixSlider->getValue()) {
        MixSlider->setValue(ourProcessor->getParameter(RingmodAudioProcessor::Mix));
    }

    if (ourProcessor->getParameter(RingmodAudioProcessor::ModSetting)==1.0f && LowToggle->getToggleState()) {
        LowToggle->setToggleState(false, dontSendNotification);
        HiToggle->setToggleState(true, dontSendNotification);

    }

    if (ourProcessor->getParameter(RingmodAudioProcessor::ModSetting)==0.0f && HiToggle->getToggleState()) {
        HiToggle->setToggleState(false, dontSendNotification);
        LowToggle->setToggleState(true, dontSendNotification);
    }

    if (ourProcessor->getParameter(RingmodAudioProcessor::LFOWaveType)==0.0f &&
        SquareToggle->getToggleState()) {
        SquareToggle->setToggleState(false, dontSendNotification);
        SineToggle->setToggleState(true, dontSendNotification);
    }

    if (ourProcessor->getParameter(RingmodAudioProcessor::LFOWaveType)==1.0f &&
        SineToggle->getToggleState()) {
        SquareToggle->setToggleState(true, dontSendNotification);
        SineToggle->setToggleState(false, dontSendNotification);
    }


    if (ourProcessor->getParameter(RingmodAudioProcessor::Drive)!=DriveSlider->getValue()) {
        DriveSlider->setValue(ourProcessor->getParameter(RingmodAudioProcessor::Drive),dontSendNotification);
    }

    if (ourProcessor->getParameterText(RingmodAudioProcessor::Drive).compare(DriveLabel->getText()) != 0) {
        DriveLabel->setText(ourProcessor->getParameterText(RingmodAudioProcessor::Drive), dontSendNotification);
    }

    if (ourProcessor->getParameter(RingmodAudioProcessor::LFOAmount) !=
        AmtSlider->getValue()) {
        AmtSlider->setValue(ourProcessor->getParameter(RingmodAudioProcessor::LFOAmount));
    }

    if (ourProcessor->getParameterText(RingmodAudioProcessor::LFOAmount).compare(AmtLabel->getText())) {
        AmtLabel->setText(ourProcessor->getParameterText(RingmodAudioProcessor::LFOAmount),dontSendNotification);
    }

    if (ourProcessor->getParameter(RingmodAudioProcessor::LFORate)!=
        RateSlider->getValue()) {
        RateSlider->setValue(ourProcessor->getParameter(RingmodAudioProcessor::LFORate));
    }
    if (ourProcessor->getParameterText(RingmodAudioProcessor::LFORate).compare(RateLAbel->getText())!=0) {
        RateLAbel->setText(ourProcessor->getParameterText(RingmodAudioProcessor::LFORate), dontSendNotification);
    }
}




//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="RingmodAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="RingmodAudioProcessor* ownerFilter" variableInitialisers="AudioProcessorEditor(ownerFilter)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="600" initialHeight="800">
  <BACKGROUND backgroundColour="ff292729"/>
  <GROUPCOMPONENT name="new group" id="bac12dd935cbbe14" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="68% 5% 29% 90%" outlinecol="ff5f9ea0"
                  textcol="ffee5d45" title="MODUATION" textpos="36"/>
  <LABEL name="FreqTitle" id="6b5f6e42d708ba58" memberName="freTitle"
         virtualName="" explicitFocusOrder="0" pos="70% 65% 25% 45" textCol="ff5f9ea0"
         edTextCol="ff000000" edBkgCol="0" labelText="FREQUENCY" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="36" bold="0" italic="0" justification="33"/>
  <SLIDER name="FreqSlider" id="18317f4158201b94" memberName="FreqSlider"
          virtualName="" explicitFocusOrder="0" pos="70% -5R 25% 20%" posRelativeY="6b5f6e42d708ba58"
          tooltip="Modulation Frequency" thumbcol="ff5f9ea0" rotarysliderfill="ffee5d45"
          rotaryslideroutline="ff5f9ea0" textboxtext="ff5f9ea0" textboxbkgd="ffffff"
          textboxhighlight="1111ee" textboxoutline="808080" min="0.010000000000000000208"
          max="1" int="0.010000000000000000208" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="MainBypassBtn" id="6333c736540b4e69" memberName="MainBypassBtn"
              virtualName="" explicitFocusOrder="0" pos="37.5% 75% 25% 10%"
              tooltip="Bypass Button" bgColOff="ff5f9ea0" bgColOn="ffee5d45"
              buttonText="BYPASS" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="de7fc3b45ce01674" memberName="FreqLabel"
         virtualName="" explicitFocusOrder="0" pos="70% 11R 25% 24" posRelativeY="18317f4158201b94"
         textCol="ff5f9ea0" edTextCol="ff000000" edBkgCol="0" labelText="freq label"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
  <GROUPCOMPONENT name="new group" id="f6da2a5f0bada8ba" memberName="groupComponent2"
                  virtualName="" explicitFocusOrder="0" pos="3% 5% 29% 90%" outlinecol="ff5f9ea0"
                  textcol="ffee5d45" title="LFO" textpos="36"/>
  <LABEL name="MixTitle" id="10b8b45307eb3564" memberName="MixTitle" virtualName=""
         explicitFocusOrder="0" pos="70% 8% 25% 45" textCol="ff5f9ea0"
         edTextCol="ff000000" edBkgCol="0" labelText="MIX" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="36" bold="0" italic="0" justification="36"/>
  <SLIDER name="MixSlider" id="a2093554f47f4619" memberName="MixSlider"
          virtualName="" explicitFocusOrder="0" pos="70% 0R 25% 20%" posRelativeY="10b8b45307eb3564"
          tooltip="Dry / Wet Mix" thumbcol="ff5f9ea0" rotarysliderfill="ffee5d45"
          rotaryslideroutline="ff5f9ea0" textboxtext="ff5f9ea0" textboxbkgd="ffffff"
          textboxhighlight="1111ee" textboxoutline="808080" min="0" max="1"
          int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="MixLabek" id="961089ea64db9cca" memberName="MixLabel" virtualName=""
         explicitFocusOrder="0" pos="70% 11R 25% 24" posRelativeY="a2093554f47f4619"
         posRelativeH="a2093554f47f4619" textCol="ff5f9ea0" edTextCol="ff000000"
         edBkgCol="0" labelText="Mix label" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="AmountTitle" id="2732819e0ddf88f3" memberName="AmountTitle"
         virtualName="" explicitFocusOrder="0" pos="5% 8% 25% 45" textCol="ff5f9ea0"
         edTextCol="ff000000" edBkgCol="0" labelText="AMOUNT" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="36" bold="0" italic="0" justification="36"/>
  <SLIDER name="AmtSlider" id="ab71cdf4b6d86ce9" memberName="AmtSlider"
          virtualName="" explicitFocusOrder="0" pos="5% 0R 25% 20%" posRelativeY="2732819e0ddf88f3"
          tooltip="LFO Amount" thumbcol="ff5f9ea0" rotarysliderfill="ffee5d45"
          rotaryslideroutline="ff5f9ea0" textboxtext="ff5f9ea0" textboxbkgd="ffffff"
          textboxhighlight="1111ee" textboxoutline="808080" min="0" max="1"
          int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="AmtLabel" id="449be90db0770da6" memberName="AmtLabel" virtualName=""
         explicitFocusOrder="0" pos="5% 11R 25% 24" posRelativeY="ab71cdf4b6d86ce9"
         posRelativeH="a2093554f47f4619" textCol="ff5f9ea0" edTextCol="ff000000"
         edBkgCol="0" labelText="Amount Label" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="RateTitle" id="52dbf66a8e9cfce6" memberName="RateTtitle"
         virtualName="" explicitFocusOrder="0" pos="5% 65% 25% 45" textCol="ff5f9ea0"
         edTextCol="ff000000" edBkgCol="0" labelText="RATE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="36" bold="0" italic="0" justification="36"/>
  <SLIDER name="RateSlder" id="e8cab765e09c1e6" memberName="RateSlider"
          virtualName="" explicitFocusOrder="0" pos="5% 0R 25% 20%" posRelativeY="52dbf66a8e9cfce6"
          tooltip="LFO Rate" thumbcol="ff5f9ea0" rotarysliderfill="ffee5d45"
          rotaryslideroutline="ff5f9ea0" textboxtext="ff5f9ea0" textboxbkgd="ffffff"
          textboxhighlight="1111ee" textboxoutline="808080" min="0.010000000000000000208"
          max="1" int="0.010000000000000000208" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="RateLabel" id="bb8114d38c64e3b2" memberName="RateLAbel"
         virtualName="" explicitFocusOrder="0" pos="5% 11R 25% 24" posRelativeY="e8cab765e09c1e6"
         posRelativeH="a2093554f47f4619" textCol="ff5f9ea0" edTextCol="ff000000"
         edBkgCol="0" labelText="Rate Label" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="DriveTitle" id="481a8b18db35e504" memberName="DriveTitle"
         virtualName="" explicitFocusOrder="0" pos="37.5% 8% 25% 45" textCol="ff5f9ea0"
         edTextCol="ff000000" edBkgCol="0" labelText="GAIN" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="36" bold="0" italic="0" justification="36"/>
  <SLIDER name="DriveSlider" id="3f73c25d9283764f" memberName="DriveSlider"
          virtualName="" explicitFocusOrder="0" pos="37.5% 0R 25% 20%"
          posRelativeY="481a8b18db35e504" tooltip="Pre-effect input Gain"
          thumbcol="ff5f9ea0" rotarysliderfill="ffee5d45" rotaryslideroutline="ff5f9ea0"
          textboxtext="ff5f9ea0" textboxbkgd="ffffff" textboxhighlight="1111ee"
          textboxoutline="808080" min="0" max="1" int="0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="DriveLabel" id="33d61e42110e85ec" memberName="DriveLabel"
         virtualName="" explicitFocusOrder="0" pos="37.5% 11R 25% 24"
         posRelativeY="3f73c25d9283764f" posRelativeH="a2093554f47f4619"
         textCol="ff5f9ea0" edTextCol="ff000000" edBkgCol="0" labelText="Drive Label"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
  <TOGGLEBUTTON name="new toggle button" id="c9c6f01fb35424bb" memberName="SquareToggle"
                virtualName="" explicitFocusOrder="0" pos="9.5% 392 12.5% 3%"
                tooltip="LFO Square Wave" txtcol="ff5f9ea0" buttonText="SQUARE"
                connectedEdges="0" needsCallback="1" radioGroupId="1" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="52bbc65499f1627b" memberName="SineToggle"
                virtualName="" explicitFocusOrder="0" pos="9.5% 360 12.5% 3%"
                tooltip="LFO Sine Wave" txtcol="ff5f9ea0" buttonText="SINE" connectedEdges="0"
                needsCallback="1" radioGroupId="1" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="a675f618c2460609" memberName="LowToggle"
                virtualName="" explicitFocusOrder="0" pos="76% 360 12.5% 3%"
                tooltip="Low Frequencies" txtcol="ff5f9ea0" buttonText="LOW"
                connectedEdges="0" needsCallback="1" radioGroupId="2" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="595025282107e84f" memberName="HiToggle"
                virtualName="" explicitFocusOrder="0" pos="76% 392 12.5% 3%"
                tooltip="High Frequencies" txtcol="ff5f9ea0" buttonText="HIGH"
                connectedEdges="0" needsCallback="1" radioGroupId="2" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
