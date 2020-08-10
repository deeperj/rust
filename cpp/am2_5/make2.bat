@echo off
set path=c:\mingw\bin
rem if x%Path:g++=%==x%Path% set PATH=%PATH%;%str1%
mingw32-make %1
