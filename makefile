test_io: headers/io.h source/io.cpp tests/main_io.cpp
	@make obj_io
	@g++ tests/main.cpp objects/io.o -o tests/main_io.exe

obj_io: source/io.cpp headers/io.cpp
	@g++ -c source/io.cpp -o objects/io.o