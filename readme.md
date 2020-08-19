## OSX Bundle Launcher for Command Line

This is sample app with demo bundle CmdLauncherOSX.app to allow

Question was asked on Apple Dev Forum: [CGEventTapCreate fail on Mojave (10.14)](https://developer.apple.com/forums/thread/109283)

**start.sh**:

    #!/usr/bin/env sh

    APP_PATH=./CmdLauncherOSX.app/Contents/MacOS/CmdLauncherOSX
    #compile:
    clang -Wall -o alterkeys alterkeys.c -framework ApplicationServices
    #copy:
    cp alterkeys  $APP_PATH
    #run:
    open -a Terminal $APP_PATH 

Output:

    /osx-launcher/CmdLauncherOSX.app/Contents/MacOS/CmdLauncherOSX ; exit;
    It works!

Verified on **macOS Mojave 10.14.6**
