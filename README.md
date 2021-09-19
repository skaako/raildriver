# raildriver
Custom Raildriver DLL for using custom hardware with Train Sim World 2

This is still very much a work in progress...

Set the com port in the INI file to connect to your Arduino (Test code included)

Arduino sends the string 'Output: xxx xxx xxx xxx xxx xxx xxx' xxx is the output to each analog channel that the Raildriver outputs. Each output has to be 3 characters to kkep the string length consistant. As you can see in the Arduino code I have added padding for numbers under 10 and under 100 that require it.

The 7 channels output are in the order Reverser, Throttle, Auto Brake, Independent Brake, Bail Off, Top Rotary Switch, Bottom Rotary Switch. These are 8 bit channels (0 - 255)

I haven't implemented any of the buttons yet. 

I have had the speed output working but didn't find it useful enough for my case.


SPLITTING COMBINED THROTTLE AND BRAKE

The combined throttle and brake in the Raildriver control is sent over Byte 2 (Throttle). To split this you can use one pot connected to the Arduino as the Throttle to output 128 to 255. Then use another pot to go from 127 to 0 for braking. The braking pot should override the Throttle pot.


INSTALLATION

Just rename the original pieHid64.dll and put the new one in the folder. Rename them back if you need the original or if program crashes.

VERSION HISTORY

1.0.0.2    Added INI file for setting serial port. Keep in the format COM1 COM2 COM3 etc.

1.0.0.1    First Version - Only works on COM3
