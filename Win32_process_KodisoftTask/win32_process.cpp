
#include "win32_process.h"
#include "event_logg.h"

MyProcess::MyProcess( std::wstring lpApplicationName, LPWSTR lpCommandLine )
{
	LOG_TRACE
		
	memset( &si, 0 , sizeof(si) );
	memset( &pi, 0 , sizeof(pi) );
    
	si.cb = sizeof(si);

	if ( !CreateProcess( lpApplicationName.c_str() , NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi ) ){
		std::cout<<GetLastError()<<std::endl;
	}
	
}

MyProcess::~MyProcess()
{
	
        CloseHandle( pi.hProcess );
		CloseHandle( pi.hThread );
		
}

BOOL MyProcess::RestartProcess( std::wstring lpApplicationName )
{
	LOG_TRACE

	if ( !this->Exit() ) {
		return FALSE;
	}

	CloseHandle( pi.hProcess );
	CloseHandle( pi.hThread );

	memset( &si, 0 , sizeof(si) );
	memset( &pi, 0 , sizeof(pi) );
    
	si.cb = sizeof(si);

	if ( !CreateProcess( lpApplicationName.c_str() , NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi ) ){
		std::cout<<GetLastError()<<std::endl;
		return FALSE;
	}

	return TRUE;
}

BOOL MyProcess::SuspendProcess()
{
	LOG_TRACE

	if ( SuspendThread( pi.hThread ) != -1 ) {
		return TRUE;
	}
	else 
		return FALSE;
}

BOOL MyProcess::ResumeProcess()
{
	LOG_TRACE

	if ( ResumeThread( pi.hThread ) != -1) {
		return TRUE;
	}
	else
		return FALSE;
}


BOOL MyProcess::Exit()
{
	LOG_TRACE

	DWORD exitValue = NULL;
	if ( TerminateProcess( pi.hProcess, GetExitCodeProcess( pi.hProcess, &exitValue ) ) ){
		CloseHandle( pi.hProcess );
		CloseHandle( pi.hThread );
		return TRUE;
	}
	else FALSE;
}

DWORD MyProcess::GetProcStatus()
{
	LOG_TRACE

	DWORD tmp = NULL;
	GetExitCodeProcess( GetProcHandle(), &tmp );
	return tmp;
}


void LoggerStart()
{
	EventLogger Date_time;
	Date_time.SetDateTime();
}