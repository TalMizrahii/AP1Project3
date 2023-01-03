all:
	g++ -std=c++11 ./Client/*.cpp  -o client.out
	g++ -std=c++11 ./Server/*.cpp ./Server/Distances/*.cpp ./Server/flowAndData/*.cpp -o server.out	
	
run-server: server.out
	./server.out ../datasets/iris/iris_classified.csv 12345
	
run-client: client.out
	./client.out 127.0.0.1 12345

run-beans: server.out
	./server.out ../datasets/beans/beans_Classified.csv 12345
	
run-iris: server.out
	./server.out ../datasets/iris/iris_classified.csv 12345

run-wine: server.out
	./server.out ../datasets/wine/wine_Classified.csv 12345

clean: server.out client.out
	rm -f a.out server.out client.out
