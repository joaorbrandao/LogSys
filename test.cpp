#include <iostream>
//#include "LogSys.h"
#include "header-only/LogSys.h"

int main() {

  LogSys logger;
  
  logger.init("test.log");
  logger.info("Testing INFO         ...OK");
  logger.success("Testing SUCCESS   ...OK");
  logger.warning("Testing WARNING   ...OK");
  logger.error("Testing ERROR       ...OK");

  return 0;
}
