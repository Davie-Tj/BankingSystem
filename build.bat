@echo off
REM LD MABESELE

REM change directory to the src to compile code
cd src
REM Compile
echo Compiling....
g++ PasswordManager.cpp BankAccount.cpp LibFunctions.cpp BankDataBase.cpp main.cpp -o ../bin/main.exe
echo Running....
 ..\bin\main.exe

pause