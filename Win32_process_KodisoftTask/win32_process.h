/*************************************************************************
"win32_process.h" contains class "MyProcess" that launch and monitor win32 
 process. It has method to Start, Restart , Suspend( paused ) , Resume
 and exit from current process. Also it has callbacks to  events
 like OnProcStart, OnProcCrash, OnProcManuallyStopped.

Copyright (c) Tribel Artem.
*************************************************************************/

#pragma once

#include <Windows.h>
#include <tchar.h>
#include "stdafx.h"


class MyProcess {
private:
	STARTUPINFO si;           //startupInfo
    PROCESS_INFORMATION pi;   //processInfo
	std::wstring processName;

public:
	MyProcess( std::wstring lpApplicationName, LPWSTR lpCommandLine );
	~MyProcess();

	BOOL RestartProcess( std::wstring lpApplicationName );
	BOOL SuspendProcess();
	BOOL ResumeProcess();
	BOOL Exit();
	
	DWORD GetProcStatus();

	inline HANDLE GetProcHandle() {
		return pi.hProcess;
	}

	inline DWORD GetProcId() {
		return pi.dwProcessId;
	}


	// callbacks functions
	BOOL OnProcStart();
	BOOL OnProcManuallyStopped();
	BOOL OnProcExit();
	BOOL OnProcRestart();
};

	void LoggerStart();
		// provide first enter to logg file for write current time and data. 

