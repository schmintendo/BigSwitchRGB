# Big Switch RGB Lamp
#### Tutorial for turning an Arduino Pro Micro, some RGBs, and a NovelKeys Big Switch into an RGB Lamp

## Getting Started
What you'll need to get started is a Pro Micro/Elite C/any Arduino, some RGBs, and a switch (and some wire!).  Here's what I got:

1. [Elite-C V4](https://keeb.io/products/elite-c-low-profile-version-usb-c-pro-micro-replacement-atmega32u4)
2. [Neopixel/Neopixel Clone RGBs](https://www.amazon.com/gp/product/B0105VMWRM/) - You can get a bunch of different kinds of these!  These are just the ones I picked.
3. [NovelKeys Big Switch](https://novelkeys.xyz/products/the-big-switch-series) - Obviously you can use any switch, or button, but these were the inspiration for this project.

I'll assume you've worked with Pro Micros before, but if you haven't, [here's a setup guide](https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide/all) to get the Arduino IDE and associated drivers on your system.

Now that you have your Pro Micro setup, make sure you can see it on your computer, using Device Manager, or QMK Toolbox if you have that installed, or Arduino's IDE.  A lot of Pro Micros come bricked, so hopefully yours is working.  The Elite Cs are usually more reliable, but only 2 out of the 3 Pro Micros I used to prototype this project were recognized in Windows.

## Circuit Diagram

![alt text](https://i.imgur.com/bmEn3Nu.png "I wish I had a circuit diagram software")

## Code

While most of the code is explained in the file itself, I'll go over the general reasoning for why I did what I did.

My code basically swaps between modes when I press a button, since I wanted a few different colors for my LEDs - RGB cycling, Solid Pink, and Solid "old lightbulb" (2700K color temperature light).  I used the FastLED library to control the LEDs, and the Bounce2 library to add debounce, and everyone online seemed to suggest it when using buttons.

For the color cycling, I stole the code from somewhere, but it's pretty self explanatory, the H part of the HSV infinitely increments over time, resulting in smooth color changing of the LEDs. 

If you don't get anything, feel free to message me on reddit!  I'll try my best to explain it.  My username is [/u/schmintendo](http://www.reddit.com/u/schmintendo).

## Things to keep in mind

The HSV in FastLED and typical HSV color codes are **not the same**.   This is documented here: https://github.com/FastLED/FastLED/wiki/FastLED-HSV-Colors
I might make a FastLED HSV to normal HSV converter at some point, but for now, here are the calculations to change the typical color codes from a HSV color selector like [this one](https://alloyui.com/examples/color-picker/hsv.html) to FastLED HSV codes:

FastLED H: (H\*256)/360

FastLED S: (S\*256)/100

FastLED V: (V\*256)/100


