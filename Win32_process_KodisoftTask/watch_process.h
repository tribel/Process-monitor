/*************************************************************************
"watch_process" contains class "WatchProcess" to watch already running 
 process. It can returned current status, handle and extract
 command line for this process

Copyright (c) Tribel Artem.
*************************************************************************/

#pragma once

#include "stdafx.h"
#include <Windows.h>
#include <tchar.h>

class WatchProcess {
private:
	HANDLE hProcess;

public:
	WatchProcess( DWORD idProcess );
	~WatchProcess();

	DWORD GetProcStatus();
	LPTSTR GetCommLine();

	inline HANDLE GetProcHandle() {
		return hProcess;
	}


};