/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
	startTimerHz(30);
	ADSR.resize(5);
	ADSRout.resize(5);
	for(int i = 0; i < 5; i++)
	{
		ADSR[i].setAttack(20);
		ADSR[i].setDecay(2);
		ADSR[i].setSustain(0.2);
		ADSR[i].setRelease(200);

		ADSRout[i] = 0;
	}
	

	graphicSize = 512;
	bigGraphicSize = graphicSize * 6;
	sineBuffer.resize(graphicSize);
	bigSineBuffer.resize(bigGraphicSize);
	for (int i = 0; i < graphicSize; i++)
	{
		sineBuffer[i] = 0;
	}

	for (int i = 0; i < bigGraphicSize; i++)
	{
		bigSineBuffer[i] = 0;
	}

	chosenNote.resize(5);
	for (int i = 0; i < 5; ++i)
	{
		chosenNote[i] = 0;
	}
	// midi input disable:
	//auto midiInputs = MidiInput::getDevices();
	//setMidiInput(0);
	// resize the button vector:
	//noteButtons.resize(5);
	On.resize(5);
	for (int i = 0; i < 5; ++i)
	{
		//noteButtons[i].resize(7);
		On[i].resize(7);
	}
	for (int i = 0; i < 5; i++) // columns
	{
		for (int j = 0; j < 7; j++)
		{
			On[i][j] = false;
		}
	}

	// NOTE BUTTONS:
	addAndMakeVisible(A1);
	A1.setButtonText("A1");
	A1.onClick = [this] { 
		
		for (int i = 0; i < 7;i ++)
		{
			if (On[0][i] == true)
			{
				On[0][i] = false;
			}
		}
		On[0][0] = true;
		chosenNote[0] = 'a'; };   // [8]
	A1.setColour(TextButton::buttonColourId, Colours::darkorange);
	//A1.addListener(this); // [7]

	addAndMakeVisible(A2);
	A2.setButtonText("A2");
	A2.setColour(TextButton::buttonColourId, Colours::orangered);
	A2.onClick = [this] { 
		for (int i = 0; i < 7; i++)
		{
			if (On[1][i] == true)
			{
				On[1][i] = false;
			}
		}
		On[1][0] = true;
		chosenNote[1] = 'a'; };   // [8]
	

	addAndMakeVisible(A3);
	A3.setButtonText("A3");
	A3.onClick = [this] { 
		for (int i = 0; i < 7; i++)
		{
			if (On[2][i] == true)
			{
				On[2][i] = false;
			}
		}
		On[2][0] = true; 
		chosenNote[2] = 'a'; };   // [8]
	A3.setColour(TextButton::buttonColourId, Colours::darkorange);

	addAndMakeVisible(A4);
	A4.setButtonText("A4");
	A4.onClick = [this] { 
		for (int i = 0; i < 7; i++)
		{
			if (On[3][i] == true)
			{
				On[3][i] = false;
			}
		}
		On[3][0] = true; 
		chosenNote[3] = 'a'; };   // [8]
	A4.setColour(TextButton::buttonColourId, Colours::darkorange);

	addAndMakeVisible(A5);
	A5.setButtonText("A5");
	A5.onClick = [this] {
		for (int i = 0; i < 7; i++)
		{
			if (On[4][i] == true)
			{
				On[4][i] = false;
			}
		}
		On[4][0] = true; 
		chosenNote[4] = 'a'; };   // [8]
	A5.setColour(TextButton::buttonColourId, Colours::darkorange);
	// B
	addAndMakeVisible(B1);
	B1.setButtonText("B1");
	B1.onClick = [this] { 
		for (int i = 0; i < 7; i++)
		{
			if (On[0][i] == true)
			{
				On[0][i] = false;
			}
		}
		On[0][1] = true; 
		chosenNote[0] = 'b'; };   // [8]
	B1.setColour(TextButton::buttonColourId, Colours::darkorange);

	addAndMakeVisible(B2);
	B2.setButtonText("B2");
	B2.onClick = [this] {
		for (int i = 0; i < 7; i++)
		{
			if (On[1][i] == true)
			{
				On[1][i] = false;
			}
		}
		On[1][1] = true; 
		chosenNote[1] = 'b'; };   // [8]
	B2.setColour(TextButton::buttonColourId, Colours::darkorange);

	addAndMakeVisible(B3);
	B3.setButtonText("B3");
	B3.onClick = [this] { 
		for (int i = 0; i < 7; i++)
		{
			if (On[2][i] == true)
			{
				On[2][i] = false;
			}

		}On[2][1] = true;
		chosenNote[2] = 'b'; };   // [8]
	B3.setColour(TextButton::buttonColourId, Colours::darkorange);

	addAndMakeVisible(B4);
	B4.setButtonText("B4");
	B4.onClick = [this] { 
		for (int i = 0; i < 7; i++)
		{
			if (On[3][i] == true)
			{
				On[3][i] = false;
			}

		}On[3][1] = true;
		chosenNote[3] = 'b'; };   // [8]
	B4.setColour(TextButton::buttonColourId, Colours::darkorange);

	addAndMakeVisible(B5);
	B5.setButtonText("B5");
	B5.onClick = [this] { 
		for (int i = 0; i < 7; i++)
		{
			if (On[4][i] == true)
			{
				On[4][i] = false;
			}

		}
	On[4][1] = true; 
	chosenNote[4] = 'b'; };   // [8]
	B5.setColour(TextButton::buttonColourId, Colours::darkorange);
	// C
	addAndMakeVisible(C1);
	C1.setButtonText("C1");
	C1.onClick = [this] { 
		for (int i = 0; i < 7; i++)
		{
			if (On[0][i] == true)
			{
				On[0][i] = false;
			}
		}
		On[0][2] = true;
		chosenNote[0] = 'c'; };   // [8]
	C1.setColour(TextButton::buttonColourId, Colours::darkorange);

	addAndMakeVisible(C2);
	C2.setButtonText("C2");
	C2.onClick = [this] { 
		for (int i = 0; i < 7; i++)
		{
			if (On[1][i] == true)
			{
				On[1][i] = false;
			}
		}
		On[1][2] = true;
		chosenNote[1] = 'c'; };   // [8]
	C2.setColour(TextButton::buttonColourId, Colours::darkorange);

	addAndMakeVisible(C3);
	C3.setButtonText("C3");
	C3.onClick = [this] {
		for (int i = 0; i < 7; i++)
		{
			if (On[2][i] == true)
			{
				On[2][i] = false;
			}

		}On[2][2] = true;
		chosenNote[2] = 'c'; };   // [8]
	C3.setColour(TextButton::buttonColourId, Colours::darkorange);

	addAndMakeVisible(C4);
	C4.setButtonText("C4");
	C4.onClick = [this] { 
		for (int i = 0; i < 7; i++)
		{
			if (On[3][i] == true)
			{
				On[3][i] = false;
			}
		}
		On[3][2] = true;
		chosenNote[3] = 'c'; };   // [8]
	C4.setColour(TextButton::buttonColourId, Colours::darkorange);

	addAndMakeVisible(C5);
	C5.setButtonText("C5");
	C5.onClick = [this] {
		for (int i = 0; i < 7; i++)
		{
			if (On[4][i] == true)
			{
				On[4][i] = false;
			}
		}
		On[4][2] = true; 
		chosenNote[4] = 'c'; };   // [8]
	C5.setColour(TextButton::buttonColourId, Colours::darkorange);
	// D
	addAndMakeVisible(D1);
	D1.setButtonText("D1");
	D1.onClick = [this] { 
		for (int i = 0; i < 7; i++)
		{
			if (On[0][i] == true)
			{
				On[0][i] = false;
			}
		}
		On[0][3] = true;
		chosenNote[0] = 'd'; };   // [8]
	D1.setColour(TextButton::buttonColourId, Colours::darkorange);

	addAndMakeVisible(D2);
	D2.setButtonText("D2");
	D2.onClick = [this] {
		for (int i = 0; i < 7; i++)
		{
			if (On[1][i] == true)
			{
				On[1][i] = false;
			}

		}On[1][3] = true;
		chosenNote[1] = 'c'; };   // [8]
	D2.setColour(TextButton::buttonColourId, Colours::darkorange);

	addAndMakeVisible(D3);
	D3.setButtonText("D3");
	D3.onClick = [this] {
		for (int i = 0; i < 7; i++)
		{
			if (On[2][i] == true)
			{
				On[2][i] = false;
			}

		}On[2][3] = true; 
		chosenNote[2] = 'c'; };   // [8]
	D3.setColour(TextButton::buttonColourId, Colours::darkorange);

	addAndMakeVisible(D4);
	D4.setButtonText("D4");
	D4.onClick = [this] { 
		for (int i = 0; i < 7; i++)
		{
			if (On[3][i] == true)
			{
				On[3][i] = false;
			}

		}On[3][3] = true;
		chosenNote[3] = 'c'; };   // [8]
	D4.setColour(TextButton::buttonColourId, Colours::darkorange);

	addAndMakeVisible(D5);
	D5.setButtonText("D5");
	D5.onClick = [this] { 
		for (int i = 0; i < 7; i++)
		{
			if (On[4][i] == true)
			{
				On[4][i] = false;
			}
		}
		On[4][3] = true; 
		chosenNote[4] = 'c'; };   // [8]
	D5.setColour(TextButton::buttonColourId, Colours::darkorange);
	// E
	addAndMakeVisible(E1);
	E1.setButtonText("E1");
	E1.onClick = [this] {
		for (int i = 0; i < 7; i++)
		{
			if (On[0][i] == true)
			{
				On[0][i] = false;
			}

		}On[0][4] = true;
		chosenNote[0] = 'e'; };   // [8]
	E1.setColour(TextButton::buttonColourId, Colours::darkorange);

	addAndMakeVisible(E2);
	E2.setButtonText("E2");
	E2.onClick = [this] { 
		for (int i = 0; i < 7; i++)
		{
			if (On[1][i] == true)
			{
				On[1][i] = false;
			}

		}On[1][4] = true;
		chosenNote[1] = 'e'; };   // [8]
	E2.setColour(TextButton::buttonColourId, Colours::darkorange);

	addAndMakeVisible(E3);
	E3.setButtonText("E3");
	E3.onClick = [this] { 
		for (int i = 0; i < 7; i++)
		{
			if (On[2][i] == true)
			{
				On[2][i] = false;
			}
		}
		On[2][4] = true;
		chosenNote[2] = 'e'; };   // [8]
	E3.setColour(TextButton::buttonColourId, Colours::darkorange);

	addAndMakeVisible(E4);
	E4.setButtonText("E4");
	E4.onClick = [this] { 
		for (int i = 0; i < 7; i++)
		{
			if (On[3][i] == true)
			{
				On[3][i] = false;
			}

		}On[3][4] = true;
		chosenNote[3] = 'e'; };   // [8]
	E4.setColour(TextButton::buttonColourId, Colours::darkorange);

	addAndMakeVisible(E5);
	E5.setButtonText("E5");
	E5.onClick = [this] { 
		for (int i = 0; i < 7; i++)
		{
			if (On[4][i] == true)
			{
				On[4][i] = false;
			}

		}On[4][4] = true;
		chosenNote[4] = 'e'; };   // [8]
	E5.setColour(TextButton::buttonColourId, Colours::darkorange);
	// F
	addAndMakeVisible(F1);
	F1.setButtonText("F1");
	F1.onClick = [this] {
		
		for (int i = 0; i < 7; i++)
		{
			if (On[0][i] == true)
			{
				On[0][i] = false;
			}
		}On[0][5] = true; 
		chosenNote[0] = 'f'; };   // [8]
	F1.setColour(TextButton::buttonColourId, Colours::darkorange);

	addAndMakeVisible(F2);
	F2.setButtonText("F2");
	F2.onClick = [this] {
		for (int i = 0; i < 7; i++)
		{
			if (On[1][i] == true)
			{
				On[1][i] = false;
			}

		}On[1][5] = true; 
		chosenNote[1] = 'f'; };   // [8]
	F2.setColour(TextButton::buttonColourId, Colours::darkorange);

	addAndMakeVisible(F3);
	F3.setButtonText("F3");
	F3.onClick = [this] { 
		for (int i = 0; i < 7; i++)
		{
			if (On[2][i] == true)
			{
				On[2][i] = false;
			}
		}
		On[2][5] = true;
		chosenNote[2] = 'f'; };   // [8]
	F3.setColour(TextButton::buttonColourId, Colours::darkorange);

	addAndMakeVisible(F4);
	F4.setButtonText("F4");
	F4.onClick = [this] {
		for (int i = 0; i < 7; i++)
		{
			if (On[3][i] == true)
			{
				On[3][i] = false;
			}

		}On[3][5] = true;
		chosenNote[3] = 'f'; };   // [8]
	F4.setColour(TextButton::buttonColourId, Colours::darkorange);

	addAndMakeVisible(F5);
	F5.setButtonText("F5");
	F5.onClick = [this] {
		for (int i = 0; i < 7; i++)
		{
			if (On[4][i] == true)
			{
				On[4][i] = false;
			}

		}On[4][5] = true; 
		chosenNote[4] = 'f'; };   // [8]
	F5.setColour(TextButton::buttonColourId, Colours::darkorange);
	// G 
	addAndMakeVisible(G1);
	G1.setButtonText("G1");
	G1.onClick = [this] { 
		for (int i = 0; i < 7; i++)
		{
			if (On[0][i] == true)
			{
				On[0][i] = false;
			}
		}
		On[0][6] = true; 
		chosenNote[0] = 'g'; };   // [8]
	G1.setColour(TextButton::buttonColourId, Colours::darkorange);

	addAndMakeVisible(G2);
	G2.setButtonText("G2");
	G2.onClick = [this] { 
		for (int i = 0; i < 7; i++)
		{
			if (On[1][i] == true)
			{
				On[1][i] = false;
			}
		}
		On[1][6] = true;
		chosenNote[1] = 'f'; };   // [8]
	G2.setColour(TextButton::buttonColourId, Colours::darkorange);

	addAndMakeVisible(G3);
	G3.setButtonText("G3");
	G3.onClick = [this] { 
		for (int i = 0; i < 7; i++)
		{
			if (On[2][i] == true)
			{
				On[2][i] = false;
			}
		}
		On[2][6] = true; 
		chosenNote[2] = 'f'; };   // [8]
	G3.setColour(TextButton::buttonColourId, Colours::darkorange);

	addAndMakeVisible(G4);
	G4.setButtonText("G4");
	G4.onClick = [this] {
		for (int i = 0; i < 7; i++)
		{
			if (On[3][i] == true)
			{
				On[3][i] = false;
			}

		}On[3][6] = true;
		chosenNote[3] = 'f'; };   // [8]
	G4.setColour(TextButton::buttonColourId, Colours::darkorange);

	addAndMakeVisible(G5);
	G5.setButtonText("G5");
	G5.onClick = [this] {
		for (int i = 0; i < 7; i++)
		{
			if (On[4][i] == true)
			{
				On[4][i] = false;
			}
		}
		On[4][6] = true;
		chosenNote[4] = 'f'; };   // [8]
	G5.setColour(TextButton::buttonColourId, Colours::darkorange);
	// END

	// MIDI things:
	addAndMakeVisible(midiOutputList);
	
	midiOutputList.setTextWhenNoChoicesAvailable("No MIDI Outputs Enabled");
	MidiOutput::getDevices();
	midiOutput = MidiOutput::openDevice(0);
	midiOutputList.addItemList(MidiOutput::getDevices(), 1);

	midiOutputList.onChange = [this] (){midiOutput=MidiOutput::openDevice(midiOutputList.getSelectedItemIndex()); };

	messageOn = MidiMessage::noteOn(1, 50, (uint8)0);


	//=====
	// Frequency Sliders
	freq1.setSliderStyle(Slider::RotaryVerticalDrag);
	freq1.setRange(0.0, 1.0);
	freq1.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
	freq1.setColour(Slider::textBoxTextColourId, Colours::black);
	freq1.onValueChange = [this] { f1 = freq1.getValue(); };
	freq1.setValue(f1);
	freq1.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(freq1);

	freq2.setSliderStyle(Slider::RotaryVerticalDrag);
	freq2.setRange(0.0, 1.0);
	freq2.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
	freq2.setColour(Slider::textBoxTextColourId, Colours::black);
	freq2.onValueChange = [this] { f2 = freq2.getValue(); };
	freq2.setValue(f2);
	freq2.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(freq2);

	freq3.setSliderStyle(Slider::RotaryVerticalDrag);
	freq3.setRange(0.0, 1.0);
	freq3.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
	freq3.setColour(Slider::textBoxTextColourId, Colours::black);
	freq3.onValueChange = [this] { f3 = freq3.getValue(); };
	freq3.setValue(f3);
	freq3.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(freq3);

    // Make sure you set the size of the component after
    // you add any child components.
    setSize (800, 600);

    // specify the number of input and output channels that we want to open
    setAudioChannels (2, 2);
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    // This function will be called when the audio device is started, or when
    // its settings (i.e. sample rate, block size, etc) are changed.

    // You can use this function to initialise any resources you might need,
    // but be careful - it will be called on the audio thread, not the GUI thread.

    // For more details, see the help for AudioProcessor::prepareToPlay()
}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
	// Get   pointer to the left and right buffers:
	auto* leftBuffer = bufferToFill.buffer->getWritePointer(0, bufferToFill.startSample);
	auto* rightBuffer = bufferToFill.buffer->getWritePointer(1, bufferToFill.startSample);

	// The Audio Loop:
	for (int sample = 0; sample < bufferToFill.numSamples; sample++)
	{
		//double sine = osc1.sinewave(f1);
		//double sine2 = osc4.sinewave(f2);
		double square1 = (osc2.square(f1) + 1) / 2;
		double square2 = (osc3.square(f2) + 1) / 2;
		double square3 = (osc6.square(f3) + 1) / 2;

		//double pulse1 = (osc7.pulse(f1, 0.1) + 1) / 2;
		//double pulse2 = (osc8.pulse(f2, 0.1) + 1) / 2;
		//double pulse3 = (osc9.pulse(f3, 0.1) + 1) / 2;

		if (f1==0.0) {
			//pulse1 = 0;
			square1 = 0;
		}
		if (f2 == 0.0) {
			//pulse2 = 0;
			square2 = 0;
		}
		if (f3 == 0.0) {
			//pulse3 = 0;
			square3 = 0;
		}

		// double sum = (square1+square2+square3)*0.3;
		double sum = (square1 + square2 + square3);
		//Logger::outputDebugString(std::to_string(sum));
		//std::cout << sum<<  std::endl;
		sineBuffer[index] = sum;
		index += 1;
		if (index >= graphicSize) {
			index = 0;
		}

		// if the value is zero, nothing should play
		if (sum == 0.0) //(time + sample) % noteDuration == 0
		{
			//MidiMessage messageOff = MidiMessage::noteOff(messageOn.getChannel(), messageOn.getNoteNumber());
			//messageOff.setTimeStamp(time);
			//midiOutput->sendMessageNow(messageOff);
		}

		// if the value has changed amd its not zero then we are at a new plateau
		if (sum != previous_sum && sum != 0.0)// sum == 0.0
		{
			bottomReached = true;
		}

		// if we have reached a plateau then set off a note-on event once: 
		if (bottomReached == true) //sum == previous_sum && 
		{
			// turn off current note:
			MidiMessage messageOff = MidiMessage::noteOff(messageOn.getChannel(), messageOn.getNoteNumber());
			messageOff.setTimeStamp(time);
			midiOutput->sendMessageNow(messageOff);
			playNote = true;
			bottomReached = false;

		}

		// output
		if (playNote == true)
		{
			
			int whichNote = 0;
			if (playNoteIndex == 0)
			{
				ADSR[0].trigger = 1;
				if (chosenNote[0] == 'a')
				{
					whichNote = 60;
				}
				if (chosenNote[0] == 'b')
				{
					whichNote = 58;
				}
				if (chosenNote[0] == 'c')
				{
					whichNote = 48;
				}
				if (chosenNote[0] == 'd')
				{
					whichNote = 51;
				}
				if (chosenNote[0] == 'e')
				{
					whichNote = 53;
				}
				if (chosenNote[0] == 'f')
				{
					whichNote = 54;
				}
				if (chosenNote[0] == 'g')
				{
					whichNote = 55;
				}
			}
			if (playNoteIndex == 1)//58, 60, 48, 51, 53, 54, 55,
			{
				ADSR[1].trigger = 1;
				if (chosenNote[1] == 'a')
				{
					whichNote = 58;
				}
				if (chosenNote[1] == 'b')
				{
					whichNote = 60;
				}
			}
			if (playNoteIndex == 2)
			{
				ADSR[2].trigger = 1;
				if (chosenNote[2] == 'a')
				{
					whichNote = 48;
				}
				if (chosenNote[2] == 'b')
				{
					whichNote = 51;
				}
			}
			if (playNoteIndex == 3)
			{
				ADSR[3].trigger = 1;
				if (chosenNote[3] == 'a')
				{
					whichNote = 53;
				}
				if (chosenNote[3] == 'b')
				{
					whichNote = 54;
				}
			}
			if (playNoteIndex == 4)
			{
				ADSR[4].trigger = 1;
				if (chosenNote[4] == 'a')
				{
					whichNote = 55;
				}
				if (chosenNote[4] == 'b')
				{
					whichNote = 51;
				}
			}
			for (int i = 0; i < 5; i++)
			{
				ADSRout[i] = ADSR[i].adsr(1., ADSR[i].trigger);
			}
			double vel = 127 * ADSRout[playNoteIndex];

			// the vel value rewrites for each no midi note sent, so at the moment we are monophonic. 
			// to do envelopes you need a different program logic. 
			messageOn = MidiMessage::noteOn(1, whichNote, (uint8)(127 * ADSRout[playNoteIndex])); //(unit8)100
			messageOn.setTimeStamp(time);
			//midi.addEvent(messageOn, time);
			
			midiOutput->sendMessageNow(messageOn);
			playNote = false;
			playNoteIndex++;
			if (playNoteIndex >= 4)
			{
				playNoteIndex = 0;
			}
		
		}

		previous_sum = sum;
		if (index == graphicSize-1)
		{
			nextSineBlockReady1 = true;
		}
		time = time + sample; // now time will be constantly incrementing, sample by sample
	}
	// Pass the info to the graphics by triggering the callback timer:

  //  nextSineBlockReady1 = true;
}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

//=====================================
void MainComponent::timerCallback()
{
	if (nextSineBlockReady1 == true)
	{
		nextSineBlockReady1 = false;
		repaint();
	}
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
	g.fillAll(Colours::yellow);  // yellow
	g.fillAll(Colours::transparentBlack);
	g.setColour(Colours::darkslategrey);
	g.fillRect(194, 45, 318, 210); //200
	g.setColour(Colours::darkgrey);
	g.fillRect(199, 50, 308, 200); //200
	drawFrame(g);
}

void MainComponent::resized()
{
	
	// Sliders for first sample:
	freq1.setBounds(10, 40, 150, 150);
	freq2.setBounds(10, 230, 150, 150);
	freq3.setBounds(10, 420, 150, 150);
	// Labels:
	
	// ComboBox:
	midiOutputList.setBounds(700, 10, 70, 30);
	
	A1.setBounds(510+10, 90, 50, 20);
	A2.setBounds(510+60, 90, 50, 20);
	A3.setBounds(510+110, 90, 50, 20);
	A4.setBounds(510+160, 90, 50, 20);
	A5.setBounds(510+210, 90, 50, 20);

	B1.setBounds(510+10, 110, 50, 20);
	B2.setBounds(510+60, 110, 50, 20);
	B3.setBounds(510+110, 110, 50, 20);
	B4.setBounds(510+160, 110, 50, 20);
	B5.setBounds(510+210, 110, 50, 20);

	C1.setBounds(510+10, 130, 50, 20);
	C2.setBounds(510+60, 130, 50, 20);
	C3.setBounds(510+110, 130, 50, 20);
	C4.setBounds(510+160, 130, 50, 20);
	C5.setBounds(510+210, 130, 50, 20);

	D1.setBounds(510+10, 150, 50, 20);
	D2.setBounds(510+60, 150, 50, 20);
	D3.setBounds(510+110, 150, 50, 20);
	D4.setBounds(510+160, 150, 50, 20);
	D5.setBounds(510+210, 150, 50, 20);

	E1.setBounds(510+10, 170, 50, 20);
	E2.setBounds(510+60, 170, 50, 20);
	E3.setBounds(510+110, 170, 50, 20);
	E4.setBounds(510+160, 170, 50, 20);
	E5.setBounds(510+210, 170, 50, 20);

	F1.setBounds(510+10, 190, 50, 20);
	F2.setBounds(510+60, 190, 50, 20);
	F3.setBounds(510+110, 190, 50, 20);
	F4.setBounds(510+160, 190, 50, 20);
	F5.setBounds(510+210, 190, 50, 20);

	G1.setBounds(510+10, 210, 50, 20);
	G2.setBounds(510+60, 210, 50, 20);
	G3.setBounds(510+110, 210, 50, 20);
	G4.setBounds(510+160, 210, 50, 20);
	G5.setBounds(510+210, 210, 50, 20);


}

void MainComponent::drawFrame(Graphics& g)
{
	float xinc = 100 / 1024 * 2.0;


		for (int i = 0; i < 512; i++)
		{
			bigSineBuffer[i + 2560] = bigSineBuffer[i + 2048];
			bigSineBuffer[i + 2048] = bigSineBuffer[i + 1536];
			bigSineBuffer[i + 1536] = bigSineBuffer[i + 1024];
			bigSineBuffer[i + 1024] = bigSineBuffer[i + 512];
			bigSineBuffer[i + 512] = bigSineBuffer[i];
			bigSineBuffer[i] = sineBuffer[i];
		}

	

	// should be until less than 1024/2 (size of fft up to Nyquist)
	// but we'll only do the first 128 bins so we can fit the
	// graph into the screen space (most of the activity is happening
	// at the bottom):
	for (int i = 1; i < bigGraphicSize - 1; i++) {
		float height1 = (bigSineBuffer[i]*0.3) * 5;
		float height_prev =(bigSineBuffer[i - 1] *0.3)* 5;



		// Draw a rectangle for every frequency value:
		g.setColour(Colours::skyblue);
		//  g.fillRect(500.2 +(i*4), 150.1-height1, 4.0, height1);
		 // g.fillRect(10.2 +(i*4), 100.0+height1, 4.0, 10);
		g.drawLine(200.0 + (((i / 10) - 1)), 150.0 - (height_prev * 20), 200.0 + (((i / 10))), 150.0 - (height1 * 20), 5);
		// g.drawLine(50.0 + ((i-1)*4), 200.0 + height_prev, 50.0 + ((i)*4), 200.0 - height_current);
	}
	// std::cout << bufferToFill.numSamples << std::endl;
	/*graphicsCounter++;
	if (graphicsCounter == 3)
	{
		graphicsCounter = 0;
	}*/
}

//====================
void MainComponent::setMidiInput(int index)
{
	
}

//========
//void buttonClicked(Button* button) // [2]
//{

	//if (button == &A1)                                                  
//	{
		                                 
		// some shit               
	//}
//}