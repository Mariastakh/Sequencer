/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#define NOGDI
#include <string>
#include <cstdlib>
#include "maximilian.h"
#include "../JuceLibraryCode/JuceHeader.h"

// Look and Feel Class:
class OtherLookAndFeel : public LookAndFeel_V4
{
public: 
        OtherLookAndFeel()
    {
        setColour(Slider::thumbColourId, Colours::darkslategrey); // 0x1001300
        setColour(Slider::backgroundColourId, Colours::blue); // 0x1001200, defined below
        setColour(Slider::rotarySliderFillColourId, Colours::lightseagreen); // covered values
        setColour(Slider::rotarySliderOutlineColourId, Colours::darkslategrey); // outline colour when not covered
    }
    
    void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos, const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override
    {
        // JUCE code:
        
        auto outline = slider.findColour (Slider::rotarySliderOutlineColourId);
        auto fill    = slider.findColour (Slider::rotarySliderFillColourId);
        
        //auto bounds = Juce::Rectangle<int>(x, y, width, height).toFloat().reduced (10);
        auto radius = jmin(width, height) / 2.0f;
        auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
		float rad = radius * 0.5;
        auto lineW = jmin(8.0f, rad);
        auto arcRadius = radius - lineW * 0.5f;
        
        // my circle:
        float centreX = x + width * 0.5f;
                float centreY = y + height * 0.5f;
                float rx = centreX - radius;
                float ry = centreY - radius;
                float rw = radius * 2.0f;
        
        g.setColour(Colours::whitesmoke);
                g.fillEllipse(rx, ry, rw, rw);
        
        // my small circle:
        // draw a smaller filled circle:
                float rx2 = centreX - (radius/2);
                float ry2 = centreY - (radius/2);
                // fill:
                g.setColour(Colours::darkslategrey);
                g.fillEllipse(rx2, ry2, (rw/2), (rw/2));
        //
        
        Path backgroundArc;
        backgroundArc.addCentredArc (width/2,
                                     height/2,
                                     arcRadius,
                                     arcRadius,
                                     0.0f,
                                     rotaryStartAngle,
                                     rotaryEndAngle,
                                     true);
        
        g.setColour (outline);
        g.strokePath (backgroundArc, PathStrokeType (lineW, PathStrokeType::beveled, PathStrokeType::butt));
        
        if (slider.isEnabled())
        {
            Path valueArc;
            valueArc.addCentredArc (width/2,
                                    height/2,
                                    arcRadius/1.1,
                                    arcRadius/1.1,
                                    0.0f,
                                    rotaryStartAngle,
                                    toAngle,
                                    true);
			
            g.setColour (fill);
            g.strokePath (valueArc, PathStrokeType (15, PathStrokeType::beveled, PathStrokeType::butt));
        }

		if (slider.isEnabled())
		{
			Path valueArc;
			valueArc.addCentredArc(width / 2,
				height / 2,
				arcRadius / 1.5,
				arcRadius / 1.5,
				0.0f,
				rotaryStartAngle,
				toAngle,
				true);

			g.setColour(Colours::darkseagreen);
			g.strokePath(valueArc, PathStrokeType(10, PathStrokeType::beveled, PathStrokeType::butt));
		}

		//if (slider.isEnabled())
		//{
			Path valueArc;
			valueArc.addCentredArc(width / 2,
				height / 2,
				arcRadius / 2.0,
				arcRadius / 2.0,
				0.0f,
				rotaryStartAngle,
				rotaryEndAngle,
				true);

			g.setColour(fill);
			g.strokePath(valueArc, PathStrokeType(5, PathStrokeType::mitered, PathStrokeType::butt));
		//}
        
        // my dial:
        float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
        Path p;
                float pointerLength = radius * 0.53f;
                float pointerThickness = 10.0f;
                p.addRectangle(-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
                p.applyTransform(AffineTransform::rotation(angle).translated(centreX, centreY));
        
                // fill the pointer path:
                g.setColour(Colours::darkslategrey);
                g.fillPath(p);

    }
};

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public AudioAppComponent, private Timer
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (Graphics& g) override;
    void resized() override;
	// More functions:
	void timerCallback() override;
	void drawFrame(Graphics& g);
	double mapRange(double value, double inputMin, double inputMax, double outputMin, double outputMax)
	{
		double input_range = inputMax - inputMin;
		double output_range = outputMax - outputMin;

		double output = (value - inputMin)*output_range / input_range + outputMin;
	}

	//void buttonClicked(Button* button) override;

	void setMidiInput(int index);

private:
    //==============================================================================
    // Your private member variables go here...
	 // Your private member variables go here...
	maxiOsc osc1, osc2, osc3, osc4, osc5, osc6, osc7, osc8, osc9;
	bool nextSineBlockReady1 = false;
	bool playNote = false;
	vector<double> sineBuffer;
	vector<double>bigSineBuffer;
	int graphicsCounter = 0;
	float decay = 50;
	double previous_sum = 0;

	int playNoteIndex = 0;
	maxiEnvelope env;
	vector<maxiEnv> ADSR;
	vector<double> ADSRout;

	bool waitForPeak = true;
	bool bottomReached = true;
	int index = 0;
	int graphicSize;
	int bigGraphicSize;

	double f1 = 0.0;
	double f2 = 0.0;
	double f3 = 0.0;
	// GUI
	Slider freq1, freq2, freq3;
	//vector<vector<TextButton>> noteButtons;
	vector<vector<bool>> On;
	// note buttons:

	TextButton C1;
	TextButton C2;
	TextButton C3;
	TextButton C4;
	TextButton C5;
	TextButton D1;
	TextButton D2;
	TextButton D3;
	TextButton D4;
	TextButton D5;
	TextButton E1;
	TextButton E2;
	TextButton E3;
	TextButton E4;
	TextButton E5;
	TextButton F1;
	TextButton F2;
	TextButton F3;
	TextButton F4;
	TextButton F5;
	TextButton G1;
	TextButton G2;
	TextButton G3;
	TextButton G4;
	TextButton G5;
	TextButton A1;//
	TextButton A2;
	TextButton A3;
	TextButton A4;
	TextButton A5;
	TextButton B1;
	TextButton B2;
	TextButton B3;
	TextButton B4;
	TextButton B5;

	vector<int> chosenNote;

	// For MIDI:
	AudioDeviceManager deviceManager;           // [1]
	ComboBox midiOutputList;  // [2]
	ComboBox midiInputList;
	Label midiOutputListLabel;
	int lastOutputIndex = 0;
	// MIDI Stuff:
	int time = 0;
	MidiOutput* midiOutput;
	MidiMessage messageOn;

	OtherLookAndFeel otherLookAndFeel;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
