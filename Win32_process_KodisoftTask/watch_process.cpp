
#include "watch_process.h"

WatchProcess::WatchProcess( DWORD idProcess )
{
	hProcess = OpenProcess( PROCESS_ALL_ACCESS, TRUE, idProcess );
		if ( !hProcess ){
			std::cout<<GetLastError()<<std::endl;
		}	
   
}

WatchProcess::~WatchProcess()
{
	CloseHandle( hProcess );
}

DWORD WatchProcess::GetProcStatus()
{
	DWORD tmp = NULL;
	GetExitCodeProcess( hProcess, &tmp );
	return tmp;
}

LPTSTR WatchProcess::GetCommLine()
{
	return GetCommandLine();
}