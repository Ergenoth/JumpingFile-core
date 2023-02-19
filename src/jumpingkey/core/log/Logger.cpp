#include "Logger.h"

#include <boost/log/sources/logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include "JumpingFileLogger.h"

void Logger::addLogger(std::string moduleName, JumpingFileLogger* logger) {
    loggers.insert({moduleName, logger});
}

void Logger::debug(std::string logger, std::string message) {
    JumpingFileLogger* jumpingFileLogger = loggers.find(logger)->second;
    boost::log::sources::logger loggerObject = jumpingFileLogger->getLogger();
    boost::log::record rec = loggerObject.open_record();
    if (rec)
    {
        boost::log::record_ostream strm(rec);
        strm << message;
        strm.flush();
        loggerObject.push_record(boost::move(rec));
    }
}