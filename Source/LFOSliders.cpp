/*
  ==============================================================================

    LFOSliders.cpp
    Created: 11 May 2022 11:30:14am
    Author:  prude

  ==============================================================================
*/

#include <JuceHeader.h>
#include "LFOSliders.h"
#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
LFOSliders::LFOSliders(FlangerAudioProcessor& p): audioProcessor(p)
{
    // LFO Sweep (Amplitude)
    sweepSlider.setSliderStyle(juce::Slider::LinearHorizontal);
    sweepSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 20);

    sweepLabel.setText("Sweep", juce::dontSendNotification);

    addAndMakeVisible(sweepSlider);
    addAndMakeVisible(sweepLabel);

    // LFO Speed (Frequency)
    speedSlider.setSliderStyle(juce::Slider::LinearHorizontal);
    speedSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 20);

    speedLabel.setText("Speed", juce::dontSendNotification);

    addAndMakeVisible(speedSlider);
    addAndMakeVisible(speedLabel);

    

    // Parameters
    sweepCall = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "SWEEP", sweepSlider);
    speedCall = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "SPEED", speedSlider);
   
}

LFOSliders::~LFOSliders()
{
}

void LFOSliders::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::dimgrey);   // clear the background

    // Slider colors
    getLookAndFeel().setColour(juce::Slider::thumbColourId, juce::Colours::pink);

    g.setColour (juce::Colours::white);
    g.setFont (16.0f);
}

void LFOSliders::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    juce::FlexBox sliderFlex;
    sliderFlex.flexWrap = juce::FlexBox::Wrap::wrap;
    sliderFlex.justifyContent = juce::FlexBox::JustifyContent::flexStart;
    sliderFlex.flexDirection = juce::FlexBox::Direction::column;



    sliderFlex.items.add(juce::FlexItem(sweepLabel).withMinHeight(50.0f).withMinWidth(50.0f).withMaxHeight(80.0f).withFlex(1, 1));
    sliderFlex.items.add(juce::FlexItem(sweepSlider).withMinHeight(50.0f).withMinWidth(50.0f).withMaxHeight(50.0f).withFlex(1, 1));

    sliderFlex.items.add(juce::FlexItem(speedLabel).withMinHeight(50.0f).withMinWidth(50.0f).withMaxHeight(80.0f).withFlex(1, 1));
    sliderFlex.items.add(juce::FlexItem(speedSlider).withMinHeight(50.0f).withMinWidth(50.0f).withMaxHeight(50.0f).withFlex(1, 1));

    sliderFlex.performLayout(getLocalBounds().reduced(4, 4).toFloat());
}
