/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class FlangerAudioProcessor : public juce::AudioProcessor
{
public:
    //==============================================================================
    FlangerAudioProcessor();
    ~FlangerAudioProcessor() override;

    //==============================================================================
    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

#ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
#endif

    void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    int getNumParameters();

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram(int index) override;
    const juce::String getProgramName(int index) override;
    void changeProgramName(int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation(juce::MemoryBlock& destData) override;
    void setStateInformation(const void* data, int sizeInBytes) override;

    static const float kMaximumDelay;
    static const float kMaximumSweepWidth;

    juce::AudioProcessorValueTreeState apvts;

    // Declaration of function 
    float getParameter(int index);
    void setParameter(int index, float newValue);
    const juce::String getParameterName(int index);
    const juce::String getParameterText(int index);
    const juce::String getInputChannelName(int channelIndex) const;
    const juce::String getOutputChannelName(int channelIndex) const;
    bool isInputChannelStereoPair(int index) const;
    bool isOutputChannelStereoPair(int index) const;

    //bool silenceInProducesSilenceOut() const;


private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FlangerAudioProcessor)

    juce::AudioProcessorValueTreeState::ParameterLayout createParameters();

    // Variables for the delay circular buffer: length, actual circular buffer, read and write pointers
    int delayBufferLength;
    juce::AudioSampleBuffer delayBuffer;
    int delayBufferRead;
    int delayBufferWrite;

    enum Parameters
    {

        kDelayParam = 0,
        kSweepParam,
        kDepthParam,
        kWetParam,
        kWaveParam,
        kInterpolParam,
        kFbParam,
        kFrequencyParam,
        kStereoParam,
        kNumParameters
    };

    enum Waves
    {
        kSineWave = 0,
        kTrWave = 1,
        kSqWave = 2,
        kSawWave = 3
    };

    enum Interpol
    {
        kLinear = 0,
        kQuadratic = 1,
        kCubic = 2
    };

    float lfoPhase;
    double inverseSampleRate;

    // Variables for the flanger parameters
    float delay;
    float wet;
    float fb;
    float sweep;
    float g;
    float speed; // frequency
    float time;
    int polarity;
    int interpol;
    int wave;
    int stereo;
};