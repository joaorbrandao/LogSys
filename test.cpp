#include <iostream>
#include "LogSys.h"

int main() {

  LogSys logger = LogSys();
  
  logger.init("test.log");
  logger.info("Hello World! :)");

  return 0;
}
