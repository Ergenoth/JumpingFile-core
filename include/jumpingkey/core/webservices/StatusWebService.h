#ifndef StatusWebService_h
#define StatusWebService_h

#include <crow.h>

class StatusWebService {
    private:
        // Private fields
        crow::SimpleApp* localApp;

        // Private methods
        static void getOverallStatus(crow::response& res);
    public:
        StatusWebService(crow::SimpleApp* app);
};

#endif