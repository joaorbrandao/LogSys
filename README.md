# LogSys 
[![GitHub license](https://img.shields.io/github/license/joaorbrandao/LogSys.svg)](https://github.com/joaorbrandao/LogSys/blob/master/LICENSE)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/29b028337fb74d6a9873eac03591f1e0)](https://www.codacy.com/project/joaorbrandao/LogSys/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=joaorbrandao/LogSys&amp;utm_campaign=Badge_Grade_Dashboard)


**A C++ logger for people.**


## Getting Started

To use this project, choose one of the following options to get started:
* Download the latest release
* Fork this repository on GitHub



## How to use

1) Add the downloaded folder to your project
2) Add *LogSys.cpp* to your build script/command

### Setup

```cpp
#include "LogSys.h"

// ...

LogSys logger;

// Call init if you want to log to a file too
logger.init("test.log");
```



### Use
Messages:
* info
* success
* warning
* error

```cpp
logger.info("Hello wordl!");
```



## Test
```console
./test.out
```
![alt text](https://github.com/joaorbrandao/LogSys/blob/master/img/test_result.png "Test result.")



## Bugs and Issues

Have a bug or an issue with this library? [Open a new issue](https://github.com/joaorbrandao/LogSys/issues) here on GitHub or leave a comment on there.



## Creator

This project was created by :<br>
[**João Brandão**](https://joaorbrandao.github.io)



## Copyright and License

MIT
