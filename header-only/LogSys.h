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

private:
	std::ofstream	file;
	std::string		fileName;



public:
	LogSys() {};
	~LogSys() {};



	/**
	 *	Initialize file to log.
	 * 
	 * @param std::string
	 * @return bool 
	 */
	bool init(std::string fileName = "") {
		if (fileName == "") { return false; }

		file.open(fileName, std::ios::out | std::ios::app);

		if (!file.is_open()) return false;

		this->setFileName(fileName);

		return true;
	}



	/**
	 * Log info message to file.
	 * 
	 * @param std::string
	 * @return bool
	 */
	bool infoFile(std::string message) {

		try {
			this->file << INFO_MESSAGE_LOG << this->getCurrentTime().c_str() << message.c_str() << std::endl;
		} catch (const std::exception&)	{
			return false;
		}

		return true;
	}



	/**
	 * Log success message to file.
	 * 
	 * @param std::string
	 * @return bool
	 */
	bool successFile(std::string message) {

		try {
			this->file << SUCCESS_MESSAGE_LOG << this->getCurrentTime().c_str() << message.c_str() << std::endl;
		}
		catch (const std::exception&) {
			return false;
		}

		return true;
	}



	/**
	 * Log warning message to file.
	 * 
	 * @param std::string
	 * @return bool
	 */
	bool warningFile(std::string message) {

		try {
			this->file << WARNING_MESSAGE_LOG << this->getCurrentTime().c_str() << message.c_str() << std::endl;
		}
		catch (const std::exception&) {
			return false;
		}

		return true;
	}



	/**
	 * Log error message to file.
	 * 
	 * @param std::string
	 * @return bool
	 */
	bool errorFile(std::string message) {

		try {
			this->file << ERROR_MESSAGE_LOG << this->getCurrentTime().c_str() << message.c_str() << std::endl;
		}
		catch (const std::exception&) {
			return false;
		}

		return false;
	}



	/**
	 * Log info message to standard output.
	 * 
	 * @param std::string
	 * @return bool
	 */
	bool info(std::string message, std::string option = "") {

		std::string textToPrint(INFO_MESSAGE_LOG);

		if (option == "withTime") { textToPrint += this->getCurrentTime().c_str(); }

		textToPrint += message.c_str();
		
		std::cout << textToPrint << std::endl;

		if (this->fileName != "") {
			this->infoFile(message);
		}

		return true;
	}



	/**
	 * Log success message to standard output.
	 * 
	 * @param std::string
	 * @return bool
	 */
	bool success(std::string message, std::string option = "") {

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



	/**
	 * Log warning message to standard output.
	 * 
	 * @param std::string
	 * @return bool
	 */
	bool warning(std::string message, std::string option = "") {
		
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



	/**
	 * Log error message to standard output.
	 * 
	 * @param std::string
	 * @return bool
	 */
	bool error(std::string message, std::string option = "") {

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


	/**
	 * Set the name of the file to log.
	 * 
	 * @param std::string
	 * @return void
	 */
	void setFileName(std::string fileName) { this->fileName = fileName; }



	/**
	 * Get the current computer time.
	 * 
	 * @return std::string
	 */
	std::string getCurrentTime() {
		std::string currentTime;
		time_t tt;

		std::chrono::system_clock::time_point today = std::chrono::system_clock::now();

		tt = std::chrono::system_clock::to_time_t(today);
		currentTime = ctime(&tt);


		return currentTime;
	}
};

