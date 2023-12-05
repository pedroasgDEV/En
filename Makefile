all:
	g++ src/SystemIMP.cpp -c -Wall -fpic
	g++ src/FlowIMP.cpp -c -Wall -fpic
	g++ src/ModelIMP.cpp -c -Wall -fpic
	g++ src/MyVensimIMP.cpp -c -Wall -fpic
	mv -f *.o obj/

Windows:
	make
	g++ obj/*.o -shared -o bin/MyVensim.dll -fpic

Linux:
	make
	g++ obj/*.o -shared -o bin/MyVensim.so -fpic

funct_tests:
	make Linux
	g++ tests/functional_tests/src/Exponencial.cpp -c -Wall
	g++ tests/functional_tests/src/Logistical.cpp -c -Wall
	g++ tests/functional_tests/src/Functional_tests.cpp -c -Wall
	g++ tests/functional_tests/src/main.cpp -c -Wall
	mv -f *.o tests/functional_tests/obj/
	g++ obj/*.o tests/functional_tests/obj/*.o -o bin/funct_tests.exe -Wall -L./bin/MyVensim 

run_funct_tests:
	make funct_tests
	g++ obj/*.o tests/functional_tests/obj/*.o -o bin/funct_tests.exe -Wall -L./bin/MyVensim 
	./bin/funct_tests.exe

unit_tests:
	make Linux
	g++ tests/unit_tests/src/unit_System.cpp -c -Wall
	g++ tests/unit_tests/src/unit_Flow.cpp -c -Wall
	g++ tests/unit_tests/src/unit_Model.cpp -c -Wall
	g++ tests/unit_tests/src/unit_MyVensim.cpp -c -Wall
	g++ tests/unit_tests/src/main.cpp -c -Wall
	mv -f *.o tests/unit_tests/obj/	

run_unit_tests:
	make unit_tests
	g++ obj/*.o tests/unit_tests/obj/*.o -o bin/unit_tests.exe -Wall
	./bin/unit_tests.exe

clean:
	clear
	rm bin/* obj/*.o tests/functional_tests/obj/*.o