#include <iostream>

#include "../lib/civetweb_min/src/CivetServer.h"

class AHandler : public CivetHandler
{
  private:
	bool
	handleAll(const char *method,
	          CivetServer *server,
	          struct mg_connection *conn)
	{
		std::string s = "";
		mg_printf(conn,
		          "HTTP/1.1 200 OK\r\nContent-Type: "
		          "text/html\r\nConnection: close\r\n\r\n");
		mg_printf(conn, "<html><body>");
		mg_printf(conn, "<h2>This is the A handler for \"%s\" !</h2>", method);
		if (CivetServer::getParam(conn, "param", s)) {
			mg_printf(conn, "<p>param set to %s</p>", s.c_str());
		} else {
			mg_printf(conn, "<p>param not set</p>");
		}
		mg_printf(conn, "</body></html>\n");
		return true;
	}

  public:
	bool
	handleGet(CivetServer *server, struct mg_connection *conn)
	{
		return handleAll("GET", server, conn);
	}
	bool
	handlePost(CivetServer *server, struct mg_connection *conn)
	{
		return handleAll("POST", server, conn);
	}
};

int main(int argc, char** argv)
{
    std::vector<std::string> cpp_options;
    cpp_options.push_back("document_root");
    cpp_options.push_back(".");
    cpp_options.push_back("listening_ports");
    cpp_options.push_back("8080");

    CivetServer server(cpp_options);

    //IO io = IO(server); //make this a namespace, not a class
    //Planet mars = Planet("Mars", 5);
    //Rover rover = Rover(); //inject the
    std::cout<< "Works"<< std::endl;
}
