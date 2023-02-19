#ifndef JumpingFileLogger_h
#define JumpingFileLogger_h

#include <boost/log/sources/logger.hpp>
#include <boost/log/utility/value_ref_fwd.hpp>
#include <boost/log/sinks.hpp>
#include "string.h"

class JumpingFileLogger {
    private:
        boost::log::sources::logger lg;
        boost::shared_ptr< boost::log::sinks::text_file_backend > backend;
    public:
        JumpingFileLogger(boost::shared_ptr< boost::log::sinks::text_file_backend > backend, std::string moduleName);
};

#endif