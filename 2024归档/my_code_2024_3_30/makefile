# makefile
http_server:http_server.cpp
	g++ -o $@ $^ -std=c++11 -lpthread

.PHONY:clean
clean:
	rm -rf http_server log_dir 