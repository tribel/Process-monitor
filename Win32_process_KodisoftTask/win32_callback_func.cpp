
#include "win32_process.h"

BOOL MyProcess::OnProcStart()
{
	memset( &si, 0 , sizeof(si) );
	memset( &pi, 0 , sizeof(pi) );
    
	si.cb = sizeof(si);

	if ( !CreateProcess( processName.c_str() , NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi ) ){
		std::cout<<GetLastError()<<std::endl;
		return FALSE;
	}
	
	return TRUE;	
}

BOOL MyProcess::OnProcRestart()
{
	if ( !this->Exit() ) {
		return FALSE;
	}

	CloseHandle( pi.hProcess );
	CloseHandle( pi.hThread );

	memset( &si, 0 , sizeof(si) );
	memset( &pi, 0 , sizeof(pi) );
    
	si.cb = sizeof(si);

	if ( !CreateProcess( processName.c_str() , NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi ) ){
		std::cout<<GetLastError()<<std::endl;
		return FALSE;
	}

	return TRUE;
}

BOOL MyProcess::OnProcExit()
{
	DWORD exitValue = NULL;
	if ( TerminateProcess( pi.hProcess, GetExitCodeProcess( pi.hProcess, &exitValue ) ) ){
		CloseHandle( pi.hProcess );
		CloseHandle( pi.hThread );
		return TRUE;
	}
	else FALSE;
}

BOOL MyProcess::OnProcManuallyStopped()
{
	if ( SuspendThread( pi.hThread ) != -1 ) {
		return TRUE;
	}
	else 
		return FALSE;
}
