all: clean build


build-client: src/rpc-client-dck/client.cpp
	g++ -Ithird_party/reverseRPC/include \
	-Iinclude \
	include/rpc_hub.cpp \
	third_party/reverseRPC/include/rrpc.cpp \
	src/rpc-client-dck/client.cpp -o build/executables/client-dck


build-server : src/rpc-server-dck/server.cpp
	g++ -Ithird_party/reverseRPC/include \
	-Iinclude \
	third_party/reverseRPC/include/rrpc.cpp \
	include/rpc_hub.cpp \
	src/rpc-server-dck/server.cpp -o build/executables/server-dck
	


build: build-server build-client
	echo "Building client and server"


clean:
	rm -rf build/executables/*