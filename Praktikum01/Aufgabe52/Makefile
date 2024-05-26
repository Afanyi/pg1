.PHONY: all
all: aufgabe52

aufgabe52: main5.o func1.o func2.o
	clang++ main5.o func1.o func2.o -o aufgabe52

main5.o: main5.cpp
	clang++ -c main5.cpp -o main5.o
       
func1.o: func1.cpp
	clang++ -c func1.cpp -o func1.o

func2.o: func2.cpp
	clang++ -c func2.cpp -o func2.o

.PHONY: clean
clean:
	rm -f main5.o
	rm -f func1.o
	rm -f func2.o
	rm -f aufgabe52
