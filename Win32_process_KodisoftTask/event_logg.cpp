
#include "event_logg.h"

std::string EventLogger::indent;
int EventLogger::flag;

EventLogger::EventLogger( std::string funcName, int  lineNumber )
{
	std::string tmpStrEvent = funcName.substr( 11, funcName.size() - 11 ); // 11 number of char "MyProcess::"
	if ( tmpStrEvent == "MyProcess" ){
		tmpStrEvent = "CreateProcess";
	}

	this->funcName = funcName;
	this->lineNumb = lineNumber;

	 eventFile.open( "event_logger.txt", std::ios::app );
	 if ( !eventFile.is_open() ) {
		std::cout<<"dont find event file"<<std::endl;
	 }
	 	 
	 dbgFile.open( "dbg_logger.txt", std::ios::app );
	 if ( !dbgFile.is_open() ) {
		 std::cout<<"not find dbg file"<<std::endl;
	 }

	 dbgFile<<indent<<"Entering  "<<this->funcName<<" : "<<lineNumb<<std::endl;
	 eventFile<<tmpStrEvent<<std::endl;

	 indent.append( "  " );
}

EventLogger::~EventLogger() 
{
	// in first calling destructor this code should not executed

	if ( EventLogger::flag == 1 ){
		indent.resize( indent.size() - 2 );
		dbgFile<<indent<<"Leaving  "<<this->funcName<<" : "<<lineNumb<<std::endl;
	}
	EventLogger::flag = 1;

	eventFile.close();
	dbgFile.close();
}

void EventLogger::SetDateTime() 
{
	eventFile.open( "event_logger.txt", std::ios::app );
	 if ( !eventFile.is_open() ) {
		std::cout<<"dont find event file"<<std::endl;
	 }

	 dbgFile.open( "dbg_logger.txt", std::ios::app );
	 if ( !dbgFile.is_open() ) {
		 std::cout<<"not find dbg file"<<std::endl;
	 }

	 eventFile<<std::endl<<"-----------"<<__DATE__<<"  "<<__TIME__<<"------------"<<std::endl;
	 dbgFile<<std::endl<<"-----------"<<__DATE__<<"  "<<__TIME__<<"------------"<<std::endl;

}