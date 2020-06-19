# ENGR101-AVC-Team35

Install Instructions for Mac OS

1.	Make sure you have Geany installed on your computer, and that it can open files and compile programs successfully.

2.	Open the Terminal (to find it press command + space then type terminal)

3.	Install Homebrew by pasting the command on the front page of this web page, https://brew.sh/ , into the Terminal window.
The command should look like this:
/bin/bash -c "$(curl -fsSL 
https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"

4.	If the Terminal is stuck at Command Line Tools for Xcode, go into System Preferences > Software Update and install the updates, one of which should be Command Line Tools for Xcode.

5.	Once Homebrew is installed, paste into the Terminal window: 
brew install sfml

6.	In Geany, go to the menu bar: Build > Set Build Commands. Under C++ commands > Build, paste these flags at the end of the command:	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network
	
	The new command should look something like:		g++ -Wall -o "%e" "%f" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network

7.	Download the AVC_Mac zip file from the ENGR101 Project 3 web page (Usually Mac OS will extract zipped files automatically, but if it is still zipped then extract it first). 

8.	Open the robot.cpp and server3.cpp files in Geany. 

9.	Delete all code from the robot.cpp file and paste in our team’s code from GitHub. 

10.	Under the Build tab in the top menu, click Make. Do this for both files, then Execute server3.cpp, and Execute robot.cpp. 

11.	Once you can see the virtual maze and the Terminal window, enter 1 or 2 depending on what mode you want to run the robot in. 1 for Core/Completion, 2 for Challenge.

12.	If you are having trouble with running the installation process or cannot run the program, email our helpdesk and we’ll get back to you by the next working day. 
Email us at: baskaraari@myvuw.ac.nz 
