
human.o: human.cpp human.h
	g++ -c -o human.o human.cpp  

stud.o: human.o student.h student.cpp
	g++ -c -o stud.o student.cpp 
lect.o: human.o lecturer.h lecturer.cpp
	g++ -c -o lect.o lecturer.cpp 
all: human.o stud.o lect.o postgrad.h postgrad.cpp
	g++ -o pg postgrad.cpp lect.o stud.o human.o


