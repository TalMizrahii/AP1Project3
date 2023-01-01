all:
	g++ -std=c++11 *.cpp ./Distances/*.cpp ./flowAndData/*.cpp -o a.out
	
run: a.out
	./a.out datasets/iris/iris_classified.csv 12345

run-beans: a.out
	./a.out datasets/beans/beans_Classified.csv 12345
	
run-iris: a.out
	./a.out datasets/iris/iris_classified.csv 12345

run-wine: a.out
	./a.out datasets/wine/wine_Classified.csv 12345

clean: a.out
	rm -f a.out
