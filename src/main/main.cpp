#include <iostream>
#include <crow.h>
#include "StatusWebService.h"
#include <boost/log/utility/setup.hpp>

// Temp - needs to be removed
#include <boost/log/sinks.hpp>
#include "JumpingFileLogger.h"
#include "Logger.h"

int main(int argc, char *argv[]) {
    Logger* logger = new Logger();

    boost::shared_ptr<boost::log::v2_mt_posix::sinks::text_file_backend> backend = boost::make_shared< boost::log::sinks::text_file_backend > (
        boost::log::keywords::file_name = "/projects/JumpingFile-core/build/test.log",
        boost::log::keywords::rotation_size = 10 * 1024 * 1023,
        boost::log::keywords::time_based_rotation = boost::log::sinks::file::rotation_at_time_point(0, 0, 0),
        boost::log::keywords::format = "[%TimeStamp%]: %Message$"
    );

    JumpingFileLogger* testLogger = new JumpingFileLogger(backend, "TestLogger");
    logger->addLogger("TestLogger", testLogger);
    logger->debug("TestLogger", "Hallo Welt");
    
    // Load the configuration
    // The loaded configuration, as long as it is stored within then file, will be provided to all necessary components
    // Usually the configuration of other modules is stored within the database

    crow::SimpleApp app;
    CROW_ROUTE(app, "/")([](){
        return "Hello World";
    });

    // Add additional webservices
    new StatusWebService(&app);

    app.run();

    //return EXIT_SUCCESS;
}