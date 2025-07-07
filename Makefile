

build-client: src/rpc-client-dck/client.cpp 
	g++ \
	-Ithird_party/_deps/rpclib-src/include \
	src/rpc-client-dck/client.cpp \
	third_party/_deps/rpclib-src/build/librpc.a	\
	-o build/executables/client-dck \
	-pthread

build-server: src/rpc-server-dck/server.cpp 
	g++ \
	-Ithird_party/_deps/rpclib-src/include \
	src/rpc-server-dck/server.cpp \
	third_party/_deps/rpclib-src/build/librpc.a \
	-o build/executables/server-dck \
	-pthread