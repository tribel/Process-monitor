
#include "event_logg.h"
#include "test_run.h"

void test_create( std::wstring tmpWstr )
{
	LoggerStart();
	 
	MyProcess Proc( tmpWstr, NULL );

	if ( Proc.GetProcStatus() == STILL_ACTIVE ) {
		 std::cout<<"stiil active"<<std::endl;
	 }
	 else 
		 std::cout<<"no active"<<std::endl;
}

void test_create_restart( std::wstring tmpWstr )
{
	LoggerStart();
	
	MyProcess Proc( tmpWstr, NULL );
	 Sleep( 3000 );
	Proc.RestartProcess( tmpWstr );
}

void test_create_exit( std::wstring tmpWstr )
{
	LoggerStart(); 
	
	MyProcess Proc( tmpWstr, NULL );
	 
	if ( Proc.GetProcStatus() == STILL_ACTIVE ) {
		 std::cout<<"stiil active"<<std::endl;
	 }
	 else 
		 std::cout<<"no active"<<std::endl;
	 
	Sleep(3000);
	Proc.Exit();
	Sleep( 1000 );

	if ( Proc.GetProcStatus() == STILL_ACTIVE ) {
		 std::cout<<"stiil active"<<std::endl;
	 }
	 else 
		 std::cout<<"no active"<<std::endl;
}

void test_suspend_resume ( std::wstring tmpWstr )
{
	LoggerStart();
	
	MyProcess Proc( tmpWstr, NULL );
		std::cout<<std::endl<<"suspend a process"<<std::endl;
		Sleep( 3000 ); 
	Proc.SuspendProcess();
		std::cout<<"wait"<<std::endl;
		Sleep( 3000 );
		if ( Proc.GetProcStatus() == STILL_ACTIVE ) {
		 std::cout<<"stiil active"<<std::endl;
		 }
		else 
		 std::cout<<"no active"<<std::endl;

	 Proc.ResumeProcess();
		std::cout<<"resume"<<std::endl;
}

void test_get_information( std::wstring tmpWstr )
{
	LoggerStart();

	MyProcess Proc( tmpWstr, NULL );
	std::cout<<std::endl<<"HANDLE : "<<Proc.GetProcHandle()<<std::endl;
	std::cout<<"ID : "<<Proc.GetProcId()<<std::endl;
}



/////////////////////////CallBack functions test /////////////

void test_call_back_start( std::wstring tmpWstr )
{
	MyProcess Proc( tmpWstr, NULL );
	Proc.OnProcStart();
}

void test_call_back_restart( std::wstring tmpWstr )
{
	MyProcess Proc( tmpWstr, NULL );
	Proc.OnProcRestart();
}

void test_call_back_stop( std::wstring tmpWstr )
{
	MyProcess Proc( tmpWstr, NULL );
	Proc.OnProcManuallyStopped();
}

void test_call_back_exit( std::wstring tmpWstr )
{
	MyProcess Proc( tmpWstr, NULL );
	Sleep( 3000 );
	Proc.OnProcExit();
}


///////// Watch /////////////////

void test_watch()
{
	MyProcess Proc( L"c:\\WINDOWS\\system32\\calc.exe", NULL );
	WatchProcess Watch( Proc.GetProcId() );
	std::cout<<std::endl<<"HANDLE   "<<Watch.GetProcHandle()<<std::endl;

	if ( Watch.GetProcStatus() == STILL_ACTIVE )
		 std::cout<<"STILL ACTIVE"<<std::endl;
	 else 
		 std::cout<<"NOT ACTIVE"<<std::endl;

	std::cout<<"COMMAND LINE:  "<<Watch.GetCommLine()<<std::endl;
}