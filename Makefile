all:
	g++ src/System.cpp -c -Wall 
	g++ src/Flow.cpp -c -Wall
	g++ src/Model.cpp -c -Wall
	mv -f *.o obj/

funct_tests:
	make
	g++ tests/functional_tests/src/Exponencial.cpp -c -Wall
	g++ tests/functional_tests/src/Logistical.cpp -c -Wall
	g++ tests/functional_tests/src/Functional_tests.cpp -c -Wall
	g++ tests/functional_tests/src/main.cpp -c -Wall
	mv -f *.o tests/functional_tests/obj/
	
run:
	make funct_tests
	g++ obj/*.o tests/functional_tests/obj/*.o -o bin/exec.exe
	./bin/exec.exe

clean:
	clear
	rm bin/*.exe obj/*.o tests/functional_tests/obj/*.o