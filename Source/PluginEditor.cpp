/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
    getLookAndFeel().setColour(juce::Slider::ColourIds::thumbColourId, juce::Colour::fromRGB (242, 202, 16));
    getLookAndFeel().setColour(juce::Slider::ColourIds::rotarySliderFillColourId, juce::Colour::fromRGB (115, 155, 184));
    getLookAndFeel().setColour(juce::Slider::ColourIds::rotarySliderOutlineColourId, juce::Colour::fromRGB (44, 53, 57));
    
    using SliderStyle       = juce::Slider::SliderStyle;
    using Attachment        = juce::SliderParameterAttachment;
    const auto boxWidth     = 35;
    const auto boxHeight    = 15;
    
    rateSlider.setSliderStyle (SliderStyle::RotaryVerticalDrag);
    rateSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, true, boxWidth, boxHeight);
    addAndMakeVisible (rateSlider);
    
    feedbackSlider.setSliderStyle (SliderStyle::RotaryVerticalDrag);
    feedbackSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, true, boxWidth, boxHeight);
    addAndMakeVisible (feedbackSlider);
    
    mixSlider.setSliderStyle (SliderStyle::RotaryVerticalDrag);
    mixSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, true, boxWidth, boxHeight);
    addAndMakeVisible (mixSlider);
    
    rateLabel.setJustificationType (juce::Justification::centred);
    addAndMakeVisible (rateLabel);
    feedbackLabel.setJustificationType (juce::Justification::centred);
    addAndMakeVisible (feedbackLabel);
    mixLabel.setJustificationType (juce::Justification::centred);
    addAndMakeVisible (mixLabel);
    
    pluginTitle.setFont (currentFont.boldened().withHeight(60.0f));
    pluginTitle.setColour (juce::Label::ColourIds::textColourId, juce::Colours::white);
    addAndMakeVisible (pluginTitle);
    
    auto& apvts = audioProcessor.apvts;
    
    rateSliderAttachment    = std::make_unique<Attachment>(*apvts.getParameter ("RATE"), rateSlider);
    feedbackSliderAttachment    = std::make_unique<Attachment>(*apvts.getParameter ("FEEDBACK"), feedbackSlider);
    mixSliderAttachment    = std::make_unique<Attachment>(*apvts.getParameter ("MIX"), mixSlider);
    
    
    
    
    setSize (400, 350);
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::black);
}

void NewProjectAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
