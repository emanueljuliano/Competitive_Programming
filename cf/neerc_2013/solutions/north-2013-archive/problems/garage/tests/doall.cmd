@echo off

setlocal enabledelayedexpansion

set test=0
for /f "delims=" %%a in (tests.all) do (
    set /a test = test + 1
    set /a test1 = test / 10
    set /a test2 = test %% 10
    echo %%a>!test1!!test2!
)
