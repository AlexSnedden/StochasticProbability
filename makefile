stochastic_probability.o: stochastic_probability.cpp
	g++ -c stochastic_probability.cpp -o stochastic_probability.o

main.o: main.cpp
	g++ -c main.cpp -o main.o

main: main.o stochastic_probability.o
	g++ -o main main.o stochastic_probability.o
