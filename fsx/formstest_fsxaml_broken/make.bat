@echo off
set path=%PATH%;c:\programs\mingw\bin;
rem if x%Path:g++=%==x%Path% set PATH=%PATH%;%str1%
mingw32-make %1
