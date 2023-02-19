#include <iostream>
#include <crow.h>
#include "StatusWebService.h"
#include <boost/log/utility/setup.hpp>

int main(int argc, char *argv[]) {
    // Initialize logging
    //boost::log::add_file_log();

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