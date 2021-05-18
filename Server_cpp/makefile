CC = g++

.PHONY = clean
TEST = 0

server: Src/ErrWrap_cpp.cpp Src/Server_cpp.cpp
	$(CC) $^ -o $@ -pthread

client: Src/ErrWrap_cpp.cpp Src/Client_cpp.cpp
	$(CC) $^ -o $@

client_test1: Src/ErrWrap_cpp.cpp Src/Client_cpp.cpp Src/Client1_cpp_test.cpp
	$(CC) $^ -o $@ -pthread
#Must be executed first:
client_test2: Src/ErrWrap_cpp.cpp Src/Client_cpp.cpp Src/Client2_cpp_test.cpp
	$(CC) $^ -o $@ -pthread
clean:
	rm -rf client server


 