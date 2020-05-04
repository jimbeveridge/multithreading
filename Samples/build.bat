@echo off
if not "%INCLUDE%" == "" goto okay
echo.
echo Your environment is not configured to run the Visual C++
echo command line compiler.  To set up the environment, run
echo \MSDEV\BIN\VCVARS32.BAT
echo 
goto done
:okay

echo ---- BackPrnt.02
cd BackPrnt.02
nmake -nologo -f BackPrnt.mak CFG="BackPrnt - Win32 Release" %1
REM -- This file is not supposed to compile correctly.
REM echo ---- BadClass.09
REM cd ..\BadClass.09
REM nmake -nologo -f BadClass.mak CFG="BadClass - Win32 Release" %1
echo ---- Banner.08
cd ..\Banner.08
nmake -nologo -f Banner.mak CFG="Banner - Win32 Release" %1
echo ---- Busy2.03
cd ..\Busy2.03
nmake -nologo -f Busy2.mak CFG="Busy2 - Win32 Release" %1
echo ---- Busy3.03
cd ..\Busy3.03
nmake -nologo -f Busy3.mak CFG="Busy3 - Win32 Release" %1
echo ---- BusyPrio.05
cd ..\BusyPrio.05
nmake -nologo -f BusyPrio.mak CFG="BusyPrio - Win32 Release" %1
echo ---- BusyWait.03
cd ..\BusyWait.03
nmake -nologo -f BusyWait.mak CFG="BusyWait - Win32 Release" %1
echo ---- Cancel.11
cd ..\Cancel.11
nmake -nologo -f Cancel.mak CFG="Cancel - Win32 Release" %1
echo ---- ComDemo.17
cd ..\ComDemo.17
nmake -nologo -f ComDemo.mak CFG="ComDemo - Win32 Release" %1
echo ---- ComDemo.17\MfcCli
cd MfcCli
nmake -nologo -f MfcCli.mak CFG="MfcCli - Win32 Release" %1
cd ..\..
echo ---- CppSkel.09
cd CppSkel.09
nmake -nologo -f CppSkel.mak CFG="CppSkel - Win32 Release" %1
echo ---- Dining.04
cd ..\Dining.04
nmake -nologo -f Dining.mak CFG="Dining - Win32 Release" %1
echo ---- Error.02
cd ..\Error.02
nmake -nologo -f Error.mak CFG="Error - Win32 Release" %1
echo ---- EventTst.04
cd ..\EventTst.04
nmake -nologo -f EventTst.mak CFG="EventTst - Win32 Release" %1
echo ---- ExitCode.02
cd ..\ExitCode.02
nmake -nologo -f ExitCode.mak CFG="ExitCode - Win32 Release" %1
echo ---- ExitThrd.02
cd ..\ExitThrd.02
nmake -nologo -f ExitThrd.mak CFG="ExitThrd - Win32 Release" %1
echo ---- IoByAPC.06
cd ..\IoByAPC.06
nmake -nologo -f IoByAPC.mak CFG="IoByAPC - Win32 Release" %1
echo ---- IoByEvnt.06
cd ..\IoByEvnt.06
nmake -nologo -f IoByEvnt.mak CFG="IoByEvnt - Win32 Release" %1
echo ---- IoByFile.06
cd ..\IoByFile.06
nmake -nologo -f IoByFile.mak CFG="IoByFile - Win32 Release" %1
echo ---- Is2odbc.16
cd ..\Is2odbc.16
nmake -nologo -f Is2Odbc.mak CFG="Is2Odbc - Win32 Release" %1
echo ---- Member.09
cd ..\Member.09
nmake -nologo -f Member.mak CFG="Member - Win32 Release" %1
nmake -nologo -f Member2.mak CFG="Member2 - Win32 Release" %1
echo ---- NumClass.10
cd ..\NumClass.10
nmake -nologo -f NumClass.mak CFG="NumClass - Win32 Release" %1
echo ---- Numbers.02
cd ..\Numbers.02
nmake -nologo -f Numbers.mak CFG="Numbers - Win32 Release" %1
echo ---- Numbers.10
cd ..\Numbers.10
nmake -nologo -f numbers.mak CFG="numbers - Win32 Release" %1
echo ---- Numbers2.10
cd ..\Numbers2.10
nmake -nologo -f Numbers2.mak CFG="Numbers2 - Win32 Release" %1
echo ---- PrntWait.03
cd ..\PrntWait.03
nmake -nologo -f PrntWait.mak CFG="PrntWait - Win32 Release" %1
echo ---- ReadWrit.07
cd ..\ReadWrit.07
nmake -nologo -f ReadWrit.mak CFG="ReadWrit - Win32 Release" %1
echo ---- ShareMem.13
cd ..\ShareMem.13
nmake -nologo -f ShareMem.mak CFG="ShareMem - Win32 Release" %1
echo ---- SmallDll.14
cd ..\SmallDll.14
nmake -nologo -f SmallDll.mak CFG="SmallDll - Win32 Release" %1
nmake -nologo -f main1.mak CFG="Main1 - Win32 Release" %1
nmake -nologo -f main2.mak CFG="Main2 - Win32 Release" %1
nmake -nologo -f Main3.mak CFG="Main3 - Win32 Release" %1
echo ---- SrchCrt.08
cd ..\SrchCrt.08
nmake -nologo -f SrchCrt.mak CFG="SrchCrt - Win32 Release" %1
echo ---- SrchWin.08
cd ..\SrchWin.08
nmake -nologo -f SrchWin.mak CFG="SrchWin - Win32 Release" %1
echo ---- TaskQueM.03
cd ..\TaskQueM.03
nmake -nologo -f TaskQueM.mak CFG="TaskQueM - Win32 Release" %1
echo ---- TaskQueS.03
cd ..\TaskQueS.03
nmake -nologo -f TaskQueS.mak CFG="TaskQueS - Win32 Release" %1
echo ---- ThrdTerm.05
cd ..\ThrdTerm.05
nmake -nologo -f ThrdTerm.mak CFG="ThrdTerm - Win32 Release" %1
echo ---- Worker.14
cd ..\Worker.14
nmake -nologo -f worker.mak CFG="Worker - Win32 Release" %1
echo ---- CopyData.13\CopyRecv
cd ..\CopyData.13\CopyRecv
nmake -nologo -f CopyRecv.mak CFG="CopyRecv - Win32 Release" %1
echo ---- CopyData.13\CopySend
cd ..\CopySend
nmake -nologo -f CopySend.mak CFG="CopySend - Win32 Release" %1
echo ---- Echo.06\EchoCli
cd ..\..\Echo.06\EchoCli
nmake -nologo -f EchoCli.mak CFG="EchoCli - Win32 Release" %1
echo ---- Echo.06\EchoSrv
cd ..\EchoSrv
nmake -nologo -f EchoSrv.mak CFG="EchoSrv - Win32 Release" %1
cd ..\..
echo ---- Is2odbc.16\DbServer
cd Is2odbc.16\DbServer
nmake -nologo -f DbServer.mak CFG="DbServer - Win32 Release" %1
cd ..\..

:done
