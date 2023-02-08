#include <catch2/reporters/catch_reporter_event_listener.hpp>
#include <catch2/reporters/catch_reporter_registrars.hpp>
#include <spawn.h>
#include <signal.h>

extern char **environ;

class testRunListener : public Catch::EventListenerBase {
private:
    pid_t childProcess;
public:
    using Catch::EventListenerBase::EventListenerBase;

    void testRunStarting(Catch::TestRunInfo const&) override {
        // Start JumpingFile server for testing
        // TODO: Take care of the different environments such as Linux, Windows or Mac
        char *argv[] = {"/projects/JumpingFile-core/build/JumpingFile-core", NULL};
        posix_spawnp(&childProcess, "/projects/JumpingFile-core/build/JumpingFile-core", NULL, NULL, argv, environ);
    }

    void testRunEnded(Catch::TestRunStats const& testRunStats ) override {
        // Kill the process of the JumpingFile server after testing
        kill(childProcess, SIGTERM);
    }
};

CATCH_REGISTER_LISTENER(testRunListener)