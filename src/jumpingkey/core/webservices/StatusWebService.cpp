#include "StatusWebService.h"

// Constructor to create the routess this web service will provide
StatusWebService::StatusWebService(crow::SimpleApp* app) {
    localApp = app;

    // Add the routes to the app
    CROW_ROUTE((*localApp), "/status/overallStatus")(getOverallStatus);
}

// Provides the overall status of the server
// TODO: Check at the single components if everything is fine
void StatusWebService::getOverallStatus(crow::response& res) {
    res.end("All up and running");
}