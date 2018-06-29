#include "LogSys.h"



LogSys::LogSys(){}
LogSys::~LogSys(){}



/*
	Initializes the logger.

	@param std::string fileName
	@return bool
*/
bool LogSys::init(std::string fileName) {
	if (fileName == "") { return false; }

	file.open(fileName, std::ios::out | std::ios::app);

	if (!file.is_open()) return false;

	this->setFileName(fileName);

	return true;
}



/*
	Log info message to file.

	@param std::string message
	@return bool 
*/
bool LogSys::infoFile(std::string message) {

	try {
		this->file << INFO_MESSAGE_LOG << this->getCurrentTime().c_str() << message.c_str() << std::endl;
	} catch (const std::exception&)	{
		return false;
	}

	return true;
}



/*
	Log success message to file.

	@param std::string message
	@return bool
*/
bool LogSys::successFile(std::string message) {

	try {
		this->file << SUCCESS_MESSAGE_LOG << this->getCurrentTime().c_str() << message.c_str() << std::endl;
	}
	catch (const std::exception&) {
		return false;
	}

	return true;
}



/*
	Log warning message to file.

	@param std::string message
	@return bool
*/
bool LogSys::warningFile(std::string message) {

	try {
		this->file << WARNING_MESSAGE_LOG << this->getCurrentTime().c_str() << message.c_str() << std::endl;
	}
	catch (const std::exception&) {
		return false;
	}

	return true;
}



/*
	Log error message to file.

	@param std::string message
	@return bool
*/
bool LogSys::errorFile(std::string message) {

	try {
		this->file << ERROR_MESSAGE_LOG << this->getCurrentTime().c_str() << message.c_str() << std::endl;
	}
	catch (const std::exception&) {
		return false;
	}

	return false;
}



/*
	Log info message to console.

	@param std::string message
	@param std::string option
	@return bool
*/
bool LogSys::info(std::string message, std::string option) {

	std::string textToPrint(INFO_MESSAGE_LOG);

	if (option == "withTime") { textToPrint += this->getCurrentTime().c_str(); }

	textToPrint += message.c_str();
	
	std::cout << textToPrint << std::endl;

	if (this->fileName != "") {
		this->infoFile(message);
	}

	return true;
}



/*
	Log info success to console.

	@param std::string message
	@param std::string option
	@return bool
*/
bool LogSys::success(std::string message, std::string option) {

	std::string textToPrint(COLOR_GREEN);

	textToPrint += SUCCESS_MESSAGE_LOG;

	if (option == "withTime") { textToPrint += this->getCurrentTime().c_str(); }

	textToPrint += message.c_str();

	std::cout << textToPrint << COLOR_RESET << std::endl;

	if (this->fileName != "") {
		this->successFile(message);
	}

	return true;
}



/*
	Log warning message to console.

	@param std::string message
	@param std::string option
	@return bool
*/
bool LogSys::warning(std::string message, std::string option) {
	
	std::string textToPrint(COLOR_YELLOW);

	textToPrint += WARNING_MESSAGE_LOG;

	if (option == "withTime") { textToPrint += this->getCurrentTime().c_str(); }

	textToPrint += message.c_str();

	std::cout << textToPrint << COLOR_RESET << std::endl;

	if (this->fileName != "") {
		this->warningFile(message);
	}

	return true;
}



/*
	Log error message to console.

	@param std::string message
	@param std::string option
	@return bool
*/
bool LogSys::error(std::string message, std::string option) {

	std::string textToPrint(COLOR_RED);

	textToPrint += ERROR_MESSAGE_LOG;

	if (option == "withTime") { textToPrint += this->getCurrentTime().c_str(); }

	textToPrint += message.c_str();

	std::cout << textToPrint << COLOR_RESET << std::endl;

	if (this->fileName != "") {
		this->errorFile(message);
	}

	return true;
}



/*
	Set file name.

	@param std::string fileName
*/
void LogSys::setFileName(std::string fileName) { this->fileName = fileName; }



/*
	Get system current time.

	@return std::string currentTime
*/
std::string LogSys::getCurrentTime() {
	std::string currentTime;
	time_t tt;

	std::chrono::system_clock::time_point today = std::chrono::system_clock::now();

	tt = std::chrono::system_clock::to_time_t(today);
	currentTime = ctime(&tt);


	return currentTime;
}
