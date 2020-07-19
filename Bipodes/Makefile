build: ripser bipodes


all: bipodes ripser ripser-coeff ripser-debug

bipodes: bipodes.cpp
	c++ -std=c++11 -Wall bipodes.cpp -o bipodes -Ofast -D NDEBUG

ripser: ./ripser/ripser.cpp
	c++ -std=c++11 -Wall ./ripser/ripser.cpp -o ./ripser/ripser -Ofast -D NDEBUG

ripser-coeff: ./ripser/ripser.cpp
	c++ -std=c++11 -Wall ./ripser/ripser.cpp -o ./ripser/ripser-coeff -Ofast -D NDEBUG -D USE_COEFFICIENTS

ripser-debug: ./ripser/ripser.cpp
	c++ -std=c++11 -Wall ./ripser/ripser.cpp -o ./ripser/ripser-debug -g


clean:
	rm -f ./ripser/ripser ./ripser/ripser-coeff ./ripser/ripser-debug
