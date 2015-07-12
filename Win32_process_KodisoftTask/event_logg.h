/***********************************************************************
"event_logg.h" contains class that log all events to files. First file 
to write call/exit functions , second - to write events.

Copyright (c) Tribel Artem.
*************************************************************************/
#pragma once

#include <fstream>
#include "stdafx.h"

class EventLogger {
private:
	std::ofstream eventFile; // to write events only 
	std::ofstream dbgFile;   // to write call/exit functions 
	
	std::string funcName;
	int  lineNumb;
	
	static std::string indent; //to create indent in dbgFile
	static int flag;

public:
	EventLogger() {};
	EventLogger( std::string funcName,int lineNumber );
	~EventLogger();

	void SetDateTime();

};


#define LOG_TRACE EventLogger EventLogger( __FUNCTION__, __LINE__ );



