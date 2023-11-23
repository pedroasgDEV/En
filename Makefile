all:
	g++ src/SystemIMP.cpp -c -Wall
	g++ src/FlowIMP.cpp -c -Wall
	g++ src/ModelIMP.cpp -c -Wall
	mv -f *.o obj/

funct_tests:
	make
	g++ tests/functional_tests/src/Exponencial.cpp -c -Wall
	g++ tests/functional_tests/src/Logistical.cpp -c -Wall
	g++ tests/functional_tests/src/Functional_tests.cpp -c -Wall
	g++ tests/functional_tests/src/main.cpp -c -Wall
	mv -f *.o tests/functional_tests/obj/
	g++ obj/*.o tests/functional_tests/obj/*.o -o bin/funct_tests.exe -Wall
	./bin/funct_tests.exe	

unit_tests:
	make
	g++ tests/unit_tests/src/unit_System.cpp -c -Wall
	g++ tests/unit_tests/src/unit_Flow.cpp -c -Wall
	g++ tests/unit_tests/src/unit_Model.cpp -c -Wall
	g++ tests/unit_tests/src/main.cpp -c -Wall
	mv -f *.o tests/unit_tests/obj/
	g++ obj/*.o tests/unit_tests/obj/*.o -o bin/unit_tests.exe -Wall
	./bin/unit_tests.exe	

clean:
	clear
	rm bin/*.exe obj/*.o tests/functional_tests/obj/*.o