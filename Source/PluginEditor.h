/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class NewProjectAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    NewProjectAudioProcessorEditor (NewProjectAudioProcessor&);
    ~NewProjectAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    juce::Slider rateSlider;
    juce::Slider feedbackSlider;
    juce::Slider mixSlider;
    juce::Label rateLabel           { "Rate", "Rate" };
    juce::Label feedbackLabel       { "Feedback", "Feedback" };
    juce::Label mixLabel            { "Mix", "Mix" };
    juce::Label pluginTitle         { "Plug-in Title", "Delay" };
    
    using Attachment = std::unique_ptr<juce::SliderParameterAttachment>;
    
    Attachment rateSliderAttachment;
    Attachment feedbackSliderAttachment;
    Attachment mixSliderAttachment;
    
    juce::Font currentFont;
    
    NewProjectAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NewProjectAudioProcessorEditor)
};
