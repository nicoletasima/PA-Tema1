build:
	g++ -std=c++11 bani.cpp -o bani
	g++ -std=c++11 gard.cpp -o gard
	g++ -std=c++11 bomboane.cpp -o bomboane
run-p1:
	./bani
run-p2:
	./gard
run-p3:
	./bomboane
clean:
	rm -f *.o bani gard bomboane
