@echo off

set Option=%1

setlocal enabledelayedexpansion
IF "%Option%"=="-h" (
    echo    # Make Sure cmake already registered to path
    echo    # Without extension
    echo    -n { New Solution Name }                        = New
    echo    -b  { Solution Name }                           = Build
    echo    -d  { Solution Name } { Debuging Sample Order } = Set Debug Mode
    echo    -r  { Solution Name }                           = Run Every Samples
    echo        { Test Input File Name }.ini : Write Arguments after "Arg" and Answers after "Ans"
) ELSE IF "%Option%"=="-n" (
    set SolutionName=%2
    if not exist !SolutionName!.cpp (
        mkdir !SolutionName!
        copy .\Origin\Origin.cpp .\!SolutionName!\!SolutionName!.cpp
        copy .\Origin\Origin.ini .\!SolutionName!\!SolutionName!.ini
    )
    cmake -D TestName:STRING=!SolutionName! -B "%cd%/build"
    code . .\!SolutionName!\!SolutionName!.cpp .\!SolutionName!\!SolutionName!.ini
) ELSE IF "%Option%"=="-b" (
    set SolutionName=%2
    cmake -D TestName:STRING=!SolutionName! -B "%cd%/build"
    cmake --build "%cd%/build" --config Debug --target ALL_BUILD -j 6
) ELSE IF "%Option%"=="-d" (
    echo -d
@REM ) ELSE IF "%Option%"=="-r" (
@REM     set True="True"
@REM     set False="False"
@REM     set IsParam=True

@REM     set TestInputFileName=%3
@REM     set Argument=%4
@REM     set Answer=%5
@REM     set "Status="
@REM     set "allLines="
@REM     for /f "tokens=* delims=" %%a in (!TestInputFileName!.ini) do (
@REM         set "Variable=%%a"

@REM         IF "!Variable!"=="!Argument!" (
@REM             set "Status=!Argument!"
@REM         ) ELSE IF "!Variable!"=="!Answer!" (
@REM             set "Status=!Answer!"
@REM         ) ELSE (
@REM             IF "!Status!"=="!Argument!" (
@REM                 set "allLines=!allLines! %%a"
@REM             ) ELSE IF "!Status!"=="!Answer!" (

@REM                 // Able to Show Multiple Answers

@REM                 @echo on
@REM                 echo Result
@REM                 ( echo !allLines! | .\build\Debug\CodingTest.exe )
@REM                 @REM echo.
@REM                 @REM echo Answer
@REM                 @REM echo %%a
@REM                 @REM echo.
@REM                 @REM set "allLines="
@REM                 @echo off
@REM             ) Else (
@REM                 @echo on
@REM                 echo Status is error
@REM                 @echo off
@REM             )
@REM         )
@REM     )
)
endlocal