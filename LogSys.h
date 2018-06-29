#include <iostream>
#include <fstream>
#include <ctime>
#include <ratio>
#include <chrono>


#define INFO_MESSAGE_LOG	"[INFO] "
#define SUCCESS_MESSAGE_LOG	"[OK]"
#define WARNING_MESSAGE_LOG	"[WARNING]"
#define ERROR_MESSAGE_LOG	"[ERROR] "

#define COLOR_RED			"\033[1;31m"
#define COLOR_YELLOW		"\033[1;33m"
#define COLOR_GREEN			"\033[1;32m"
#define COLOR_RESET			"\033[0m"

class LogSys {

public:
	LogSys();
	~LogSys();


	std::ofstream	file;
	std::string		fileName;



	bool init(std::string fileName = "");

	// Messages
	bool infoFile		(std::string message);
	bool successFile	(std::string message);
	bool warningFile	(std::string message);
	bool errorFile		(std::string message);

	bool info		(std::string message, std::string option = "");
	bool success	(std::string message, std::string option = "");
	bool warning	(std::string message, std::string option = "");
	bool error		(std::string message, std::string option = "");

	//Getters & Setters
	void setDebugMode	(unsigned char debugMode);
	void setFileName	(std::string fileName);
	std::string getCurrentTime();
};

