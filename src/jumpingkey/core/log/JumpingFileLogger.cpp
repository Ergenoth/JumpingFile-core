#include "JumpingFileLogger.h"
#include <boost/log/expressions.hpp>

namespace logging = boost::log;
namespace sinks = boost::log::sinks;

BOOST_LOG_ATTRIBUTE_KEYWORD (module_name, "Module Name", std::string);

JumpingFileLogger::JumpingFileLogger(boost::shared_ptr< sinks::text_file_backend > backend, std::string moduleName) {
    // Create the sink from the provided backend configuration
    typedef sinks::synchronous_sink< sinks::text_file_backend > fileSink;
    boost::shared_ptr<fileSink> sink(new fileSink(backend));

    // Add the filter to the sink to only write to the sink, when the module name is equal as stated when creating this logger definition
    sink->set_filter(module_name == moduleName);

    // Add the sink to the core to be able to write to the sink
    logging::core::get()->add_sink(sink);
}

boost::log::sources::logger JumpingFileLogger::getLogger() {
    return lg;
}