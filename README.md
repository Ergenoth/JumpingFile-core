# JumpingFile-core
JumpingFile is a open core document management system.\
The project aims to be a simple solution for private users or corporate use.\
\
For private users there is no open source document management system which can be simply installed on the machine of the user. Rather more for every open souce document management system, aimed for private users, needs to install a server in a docker environemtn or generally a server environment. But the default private user is not able to set up a server side component to use the doucment management system. Additionally the configuration of such a system is not easy and not the favourite task of private users. Therefore JumpingFile aims to keep those requirements as low as possible to set the focus on managing documents!\
\
But JumpingFile does not ignore the coprate usage of a document management system. When Jumpingfile is used in a coproation environemtn, the core component can be installed as server component to be accessed by all users.\
\
JumpingFile is in it's early stages! Stay tuned for more information as the project develops!

## Dependencies
During development the dependencies need to be installed/compiled directly on the machine where the installation/development runs:
- crow (https://github.com/CrowCpp/Crow)
    - Needs to be cloned from the repository and build as instructed on the github page
    - Self compiled from the main branch
- boost / boos beast / boos asio
    - Version 1.74
- Catch2 (https://github.com/catchorg/Catch2)
    - For test cases only. When only the application should be built, this dependecy can be ignore. Needs to be cloned from the repository and build as instructed on the github page
    - Self compiled from the main branch
- PThread

## Building the project
For building the core application (and test cases) for Release follow these steps:
- Create directories "build/release" in the root directory of the project
- Call <code>cmake -DCMAKE_BUILD_TYPE=RELEASE ../..</code>
- Call <code>cmake --build . --target JumpingFile-core</code>
- (If you want to execute the test cases) Call <code>cmake --build . --target JumpingFile-core-Test</code>

For building the core application (and test cases) for debugging follow these steps:
- Create directories "build/debug" in the root directory of the project
- Call <code>cmake -DCMAKE_BUILD_TYPE=DEBUG ../..</code>
- Call <code>cmake --build . --target JumpingFile-core</code>
- (If you want to execute the test cases) Call <code>cmake --build . --target JumpingFile-core-Test</code>apt-c