#ifndef Logger_h
#define Logger_h

#include <string>
#include <boost/log/sinks.hpp>
#include "JumpingFileLogger.h"

class Logger {
    private:
        std::map<std::string, JumpingFileLogger> loggers;
    public:
        Logger();
        static void debug(std::string logger, std::string debugMessage);
        static void info(std::string logger, std::string debugMessage);
        static void warn(std::string logger, std::string debugMessage);
        static void trace(std::string logger, std::string debugMessage);
        static void error(std::string logger, std::string debugMessage);
};

#endif