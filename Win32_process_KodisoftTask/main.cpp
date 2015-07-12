#include "test_run.h"

using namespace std; 

int main( int argc, char *argv[] )
{   
	//YOU SHOULD UNCOMMENT ANY OF COMMENTED TEST FUNCTION AND 
	// COMMENT ANOTHER


	if ( argc < 2 ) {
		cout<<"Please , entered the process"<<endl;
		return 0;
	}

	 string tmpStr = argv[1];
	 wstring tmpWstr;
	 tmpWstr.assign( tmpStr.begin(), tmpStr.end() );
	 

	 //test_create( tmpWstr );
	 //test_create_restart( tmpWstr );
	 //test_get_information( tmpWstr );
	 //test_suspend_resume( tmpWstr );
	 //test_create_exit( tmpWstr );

	 //test_call_back_exit( tmpWstr );
	 //test_call_back_restart( tmpWstr );
	 //test_call_back_start( tmpWstr );
	 //test_call_back_stop( tmpWstr );

	 //test_watch();

	 return 0;	
}
