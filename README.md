# CPP_wxWidgets_Template
This is a generic template that I use for the Raspberry Pi, C++, and libgpiod to create projects

Below is a screen grab of the running program on a Raspberry Pi 4.

![](https://github.com/eugenedakin/CPP_wxWidgets_Template/blob/main/ScreenGrab.png)

This is a generic C++ wxWidgets template that has no graphical formatting, all controls are manually positioned. A MakeFile is included to automatically compile and run the program. You will need to change the C++ source code name and the final binary file name to meet your needs. 

Install instructions are:

install Raspberry Pi OS (64-bit)
Open a terminal and type the following commands:
sudo apt update && sudo apt upgrade -y
sudo apt install libgpiod-dev libgpiod2 gpiod
sudo apt install libwxgtk3.2-dev wx-common

Create the example program in the terminal with:``g++ -O2 wxBaseTemplateRev3.cpp -o wxBaseTemplateRev3 `wx-config --cxxflags --libs` -lgpiod -lgpiodcxx``
