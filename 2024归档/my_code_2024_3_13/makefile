# makefile(远程操作程序)
.PHONY:all
all:udp_client udp_server

udp_client:udp_client.cpp
	g++ -o $@ $^ -std=c++11
udp_server:udp_server.cpp
	g++ -o $@ $^ -std=c++11	
	
.PHONY:clean
clean:
	rm -f udp_client udp_server