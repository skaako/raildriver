# raildriver
Custom Raildriver DLL for using custom hardware with Train Sim World 2

This is still very much a work in progress...

XINPUT VERSION

This allows game controllers to be used. I use x360ce https://www.x360ce.com/ to map my controls to an emulated Xbox 360 Controller. Use anything other than Controller 1
as this controller is mapped to the usual Train Sim World 2 controller functions. The DLL will pickup only one controller that is not mapped to controller 1.

I have tested it with a PS4 controller mapped to Controller 2 for example to test it. Going into the Raildriver Calibrate settings in TSW2 will allow you to check it.

Here is how the DLL interprets the game controller axis...

Reverser - Left Thumbstick X
Throttle/Brake - Left Thumbstick Y
Automatic Brake - Right Thumbstick X
Independent Brake/Bail-off* - Right Thumbstick Y
Rotary Switch 1 - Left Trigger
Rotary Switch 2 - Right Trigger

*Note: The bail-off control on the original Raildriver is a 0-255 analog value like the rest. I have set it up so to use bail-off hold the DPad Up Button. The Bail-Off value
will be that of the Right Thubstick Y and Independent Brake value will be 0. (Let me know if this needs work as I'm not famililar with the outputs of the actual Raildriver)

To install just replace the original DLL. On my installation the folder is...
C:\SteamLibrary\steamapps\common\Train Sim World 2\WindowsNoEditor\TS2Prototype\Binaries\ThirdParty\PieHid\Binaries

Custom XInput controller with Arduino Leonardo: I have tested this with the XInput library and have been sucessful. Follow the intructions for using XInput once the Arduino XInput Library has been installed.



SERIAL PORT VERSION

INI file has to go into c:\Windows folder to work in TSW2. Set the com port in the INI file to connect to your Arduino (Test code included)

Arduino sends the string 'Output: xxx xxx xxx xxx xxx xxx xxx' xxx is the output to each analog channel that the Raildriver outputs. Each output has to be 3 characters to keep the string length consistant. As you can see in the Arduino code I have added padding for numbers under 10 and under 100 that require it.

The 7 channels output are in the order Reverser, Throttle, Auto Brake, Independent Brake, Bail Off, Top Rotary Switch, Bottom Rotary Switch. These are 8 bit channels (0 - 255)

I haven't implemented any of the buttons yet. 

I have had the speed output working but didn't find it useful enough for my case.



SPLITTING COMBINED THROTTLE AND BRAKE

The combined throttle and brake in the Raildriver control is sent over Byte 2 (Throttle). To split this you can use one pot connected to the Arduino as the Throttle to output 128 to 255. Then use another pot to go from 127 to 0 for braking. The braking pot should override the Throttle pot.



INSTALLATION

Just rename the original pieHid64.dll and put the new one in the folder. Rename them back if you need the original or if program crashes.
Put INI file into C:\Windows folder. Edit Port to the com port of your Arduino. COM3 COM5 etc.

On my installation the folder is...
C:\SteamLibrary\steamapps\common\Train Sim World 2\WindowsNoEditor\TS2Prototype\Binaries\ThirdParty\PieHid\Binaries



VERSION HISTORY

2.0.0.1    XInput Version - Allows XInput controller to be used to supply TSW2 with data. Use a program like x360ce to map your controllers, throttles etc.

1.0.0.2    Added INI file for setting serial port. Keep in the format COM1 COM2 COM3 etc.

1.0.0.1    First Version - Only works on COM3
