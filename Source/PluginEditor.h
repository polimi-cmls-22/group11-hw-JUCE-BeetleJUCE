/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "LFOSliders.h"

//==============================================================================
/**
*/
class FlangerAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    FlangerAudioProcessorEditor(FlangerAudioProcessor&);
    ~FlangerAudioProcessorEditor() override;

    //==============================================================================
    void paint(juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    FlangerAudioProcessor& audioProcessor;
    LFOSliders sliders;

    juce::Slider delaySlider;
    juce::Label delayLabel;

    juce::Slider fbSlider;
    juce::Label fbLabel;

    juce::Slider wetDrySlider;
    juce::Label wetDryLabel;

    juce::Slider gSlider;
    juce::Label gLabel;

    juce::ComboBox waveSelector;
    juce::Label waveSelectorLabel;

    juce::ComboBox interpolSelector;
    juce::Label interpolSelectorLabel;

    juce::ToggleButton phaseSwitch;

    juce::ImageComponent logo;

    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> waveSelectorCall;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> interpolSelectorCall;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> delayCall;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> fbCall;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> gCall;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> phaseCall;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FlangerAudioProcessorEditor)
};
