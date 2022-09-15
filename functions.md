<!-- a guide to andrew's functions -->

# goF(Int time, Int power)

`Run all wheel motors at a given power for a given time to achive forward movement.`

###### Required Variables

time = Time in milliseconds

###### Optional Variables

power = Power given to the motors as a percentage. Set to 100% by default.

# goB(Int time, Int power)

`Run all wheel motors at a given power for a given time to achive backward movement.`

###### Required Variables

time = Time in milliseconds

###### Optional Variables

power = Power given to the motors as a percentage. Set to 100% by default.

# Tr(), Tl()

`My attempt at programming a function to turn the robot 90 degrees to the right.`

###### No required variables 

###### No optional variables 

###### Please Note: 

This function is inconsistent at best, try not to use it. I had planned to shift this to using a given rpm value, but thats not done.

# ClawClose(Int duration, Int power)

`Closes the claw for a given time at a given power.`

##### Required Variables

time = time in milliseconds

##### Optional Variables

power = Power given to the motor as a percentage. Set to 100% by default.

# ClawOpen(Int duration, Int power)

`Closes the claw for a given time at a given power.`

##### Required Variables

time = time in milliseconds

##### Optional Variables

power = Power given to the motor as a percentage. Set to 100% by default.

# allStop()

`Stops all the motors connected to the robot. This function is hard coded -- any motors we add will have to be added here manually at least until I can figure out a way to do something like this dynamically.`

###### No required variables 

###### No optional variables 

# newLine(Int row, bool isCont)

This function was made to more easily add things to the brain's screen. 

##### Required Variables

row = row of the display to add to.

##### Optional Variables

isCont = checks to add this to the controller or brain's screen. True for controller, false for brain.

###### Please Note: 
Setting isCont to true does nothing -- writing to the screen of the controller makes the program run too slowly (it generates lag). I'm not sure why, and it's more trouble than it's worth to fix (There are more important things I had to work on. If anyone wants to add to this, be my guest. But please note it is the **lowest priority.**) 

# makeButtonDisp(Int x, Int y, char label, Color Col)

`Makes a circle with radius 10 at a given position, with a given color, with a given character inside.`

##### Required Variables

x = X position of the circle

y = Y position of the circle 

label = The character to put in the center. Can take a string, but will throw a warning. This can be ignored (it will still work).

color = The color of the circle.

##### No Optional Varables