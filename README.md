Ringmod
=======

Ring Modulation VST plugin for OS X and Windows. Very much inspired by Moog's MF-102 in designed, if not in actual
sound. I don't really know the MF-102 sounds as I don't own one, but I've modeled what the user manual tells us it
does.

Licence
-------
Ringmod is shared under GNU Public Licence (GPLv2 or later).

Third Party Code
----------------
Ringmod is made possible thanks to the following:

- [JUCE] (http://www.juce.com/) (Jules' Utility Class Extensions) shared under GNU Public Licence.
- [The Synthesis ToolKit] (https://ccrma.stanford.edu/software/stk/) in C++ (STK) Copyright (c) 1995-2012 Perry R. Cook and Gary P. Scavone 

The latter was made packaged into a JUCE module by GitHub user [drowaudio] (https://github.com/drowaudio/stk_module).

All the above can be found under Ringmod/JuceLibraryCode/modules/


What does it do?
----------------
There are two sections:

- (left) Low frequency oscillator (LFO) that modulates the frequency of the ring modulation.
- (right) Ring modulation that is applied to input signal.

To disengage the LFO section, set the amount knob to zero.  It's probably a good idea to try the Ring Modulation
settings independently of the LFO to get an idea of the sound.

Try setting the mix all the way up, so that you'll hear only the wet signal.

The High / Low selector chooses between two range of frenquency for the modulation.

The effect you'll hear will depend on the input signal and whether or not the modulation frequency is within the
audible range (~20Hz).  You'll get a tremolo effect if you set modulation frequency below the audible range.  This
is straight forward amplitude modulation.

When the frequency is set within the audible range, we get ring modulation instead of amplitude modulation.  To 
understand what's happening, try using a simple signal like a sine wave as an input signal.  If your input has only 
a single harmonic partial (let say 220) and your modulation frequency is set to 100, your output signal will have two
partials: one at 120 (220 - 100) and one at 320 (220 + 100).  If you mix in your input signal, you can retain the 
original partial as well.

The LFO will mess with this by changing the modulation frequency.  It ranges from none (counter-clockwise) to three
octaves (clockwise).

