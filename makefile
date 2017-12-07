test_io: headers/io.h source/io.cpp tests/main_io.cpp
	@make obj_io
	@g++ tests/main_io.cpp objects/io.o objects/coords.o -o tests/main_io.exe -std=c++11

obj_io: source/io.cpp headers/io.h
	@make obj_coords
	@echo "Compiling $@ ..."
	@g++ -c source/io.cpp objects/coords.o -o objects/io.o -std=c++11
	@echo "Compilation of $@ done."

obj_coords: source/coords.cpp headers/coords.h
	@g++ -c source/coords.cpp -o objects/coords.o -std=c++11