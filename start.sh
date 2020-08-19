#!/usr/bin/env sh

APP_PATH=./CmdLauncherOSX.app/Contents/MacOS/CmdLauncherOSX
#compile:
clang -Wall -o alterkeys alterkeys.c -framework ApplicationServices
#copy:
cp alterkeys  $APP_PATH
#run:
open -a Terminal $APP_PATH 
