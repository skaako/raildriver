# raildriver
Custom Raildriver DLL for using custom hardware with Train Sim World 2

This is still very much a work in progress...

Currently DLL opens COM3 to an Arduino (Test code included)

Arduino sends the string 'Output: xxx xxx xxx xxx xxx xxx xxx' xxx is the output to each analog channel that the Raildriver outputs. Each output has to be 3 characters to kkep the string length consistant. As you can see in the Arduino code I have added padding for numbers under 10 and under 100 that require it.

The 7 channels output are in the order Reverser, Throttle, Auto Brake, Independent Brake, Bail Off, Top Rotary Switch, Bottom Rotary Switch. These are 8 bit channels (0 - 255)

I haven't implemented any of the buttons yet. 

I have had the speed output working but didn't find it useful enough for my case.


INSTALLATION

Just rename the original pieHid64.dll and put the new one in the folder. Rename them back if you need the original or if program crashes.
