@echo off

set Option=%1

setlocal enabledelayedexpansion
IF "%Option%"=="-h" (
    echo    # Without extension
    echo    -n { New Solution Name } - New
    echo    -b  { Solution Name } - Build
    echo    -d  { Solution Name } { Debuging Sample Order } - Set Debug Mode
    echo    -r  { Solution Name } - Run Every Samples
    echo        { Test Input File Name }.ini : Write Arguments after "Arg" and Answers after "Ans"
) ELSE IF "%Option%"=="-n" (
    set SolutionName=%2
    if not exist !SolutionName!.cpp (
        copy Origin.const !SolutionName!.cpp
    )
    code !SolutionName!.cpp
) ELSE IF "%Option%"=="-b" (
    set SolutionName=%2
    "C:\Program Files\CMake\bin\cmake.EXE" -D TestName:STRING=!SolutionName! -B "%cd%/build"
    "C:\Program Files\CMake\bin\cmake.EXE" --build "%cd%/build" --config Debug --target ALL_BUILD -j 6
) ELSE IF "%Option%"=="-d" (
    echo -d
) ELSE IF "%Option%"=="-r" (
    set True="True"
    set False="False"
    set IsParam=True

    set TestInputFileName=%3
    set Argument=%4
    set Answer=%5
    set "Status="
    set "allLines="
    for /f "tokens=* delims=" %%a in (!TestInputFileName!.ini) do (
        set "Variable=%%a"

        IF "!Variable!"=="!Argument!" (
            set "Status=!Argument!"
        ) ELSE IF "!Variable!"=="!Answer!" (
            set "Status=!Answer!"
        ) ELSE (
            IF "!Status!"=="!Argument!" (
                set "allLines=!allLines! %%a"
            ) ELSE IF "!Status!"=="!Answer!" (

                // Able to Show Multiple Answers

                @echo on
                echo Result
                ( echo !allLines! | .\build\Debug\CodingTest.exe )
                @REM echo.
                @REM echo Answer
                @REM echo %%a
                @REM echo.
                @REM set "allLines="
                @echo off
            ) Else (
                @echo on
                echo Status is error
                @echo off
            )
        )
    )
)
endlocal