all:
	g++ src/SystemIMP.cpp -c 
	g++ src/FlowIMP.cpp -c
	g++ src/ModelIMP.cpp -c
	mv -f *.o obj/

funct_tests:
	make
	g++ tests/functional_tests/src/Exponencial.cpp -c
	g++ tests/functional_tests/src/Logistical.cpp -c
	g++ tests/functional_tests/src/Functional_tests.cpp -c
	g++ tests/functional_tests/src/main.cpp -c
	mv -f *.o tests/functional_tests/obj/
	g++ obj/*.o tests/functional_tests/obj/*.o -o bin/exec.exe
	
run:
	make funct_tests
	./bin/exec.exe

clean:
	clear
	rm bin/*.exe obj/*.o tests/functional_tests/obj/*.o