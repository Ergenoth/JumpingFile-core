#include <iostream>
#include <crow.h>

int main(int argc, char *argv[]) {
    crow::SimpleApp app;
    CROW_ROUTE(app, "/")([](){
        return "Hello World";
    });
    app.run();

    //return EXIT_SUCCESS;
}