// "test_run" created for testing classes and their methods
// from "win32_process" , "watch_process" and "event_logg"



#include "watch_process.h"
#include "win32_process.h"
#include "event_logg.h"

void test_create( std::wstring tmpWstr );
	//only created the process

void test_create_restart( std::wstring tmpWstr );
void test_create_exit( std::wstring tmpWstr );
void test_suspend_resume ( std::wstring tmpWstr );
void test_get_information( std::wstring tmpWstr );

//////Call back function///////

void test_call_back_start( std::wstring tmpWstr );
void test_call_back_restart( std::wstring tmpWstr );
void test_call_back_stop( std::wstring tmpWstr );
void test_call_back_exit( std::wstring tmpWstr );


///////////Watch class////////////////

void test_watch();

