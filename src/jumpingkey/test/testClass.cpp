#include <boost/beast.hpp>
#include "testClass.h"
#include <iostream>

namespace beast = boost::beast; // from <boost/beast.hpp>
namespace http = beast::http;   // from <boost/beast/http.hpp>
namespace net = boost::asio;    // from <boost/asio.hpp>
using tcp = net::ip::tcp;

std::string testClass::serverStartup() {
    // Checks if the server started correctly by calling the status api

    std::string target = "/";

    // The io_context is required for all I/O
    net::io_context ioc;

    // These objects perform our I/O
    tcp::resolver resolver(ioc);
    beast::tcp_stream stream(ioc);

    // Look up the domain name
    auto const results = resolver.resolve(testClass::testHost, testClass::testPort);

    // Make the connection on the IP address we get from a lookup
    stream.connect(results);

    // Set up an HTTP GET request message
    http::request<http::string_body> req;
    req.method(http::verb::get);
    req.target("/");
    req.set(http::field::host, testClass::testHost);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
    //req.set(http::field::content_type, "plain/text");
    //req.body() = {{"type", "test"}, {"content", "pure awesomeness"}};
    //req.prepare_payload();
    // Send the HTTP request to the remote host
    http::write(stream, req);
    
    // This buffer is used for reading and must be persisted
    beast::flat_buffer buffer;

    // Get the response
    http::response<http::string_body> res;

    // Receive the HTTP response
    http::read(stream, buffer, res);

    // Save the response in a variable
    std::string returnValue = res.body();
    //std::cout << res << std::endl;

    // Gracefully close the socket
    beast::error_code ec;
    stream.socket().shutdown(tcp::socket::shutdown_both, ec);

    //return returnValue;
    return returnValue;
}