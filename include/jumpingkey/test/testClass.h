#ifndef testClass_h
#define testClass_h

#include <string>

class testClass {
    private:
        std::string testHost = "0.0.0.0";
        std::string testPort = "80";
    public:
        std::string serverStartup();
};

#endif