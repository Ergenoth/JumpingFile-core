#include <iostream>
#include <crow.h>
#include "StatusWebService.h"

int main(int argc, char *argv[]) {
    crow::SimpleApp app;
    CROW_ROUTE(app, "/")([](){
        return "Hello World";
    });

    // Add additional webservices
    new StatusWebService(&app);

    app.run();

    //return EXIT_SUCCESS;
}