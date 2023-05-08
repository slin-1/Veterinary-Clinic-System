#Allows for removal of files in Windows OS
ifeq ($(OS),Windows_NT) 
RM = del /Q /F
CP = copy /Y
else
RM = rm -rf
CP = cp -f
endif


vet:	Control.o View.o Time.o Date.o Animal.o Appt.o Schedule.o
	g++ -o vet Control.o View.o Time.o Date.o Animal.o Appt.o Schedule.o

Control.o:	Control.cc Control.h defs.h CompareBehaviour.h List.h
	g++ -c Control.cc

View.o:	View.cc View.h
	g++ -c View.cc

Time.o: Time.cc Time.h
	g++ -c Time.cc

Date.o: Date.cc Date.h
	g++ -c Date.cc

Animal.o: Animal.cc Animal.h
	g++ -c Animal.cc

Appt.o: Appt.cc Appt.h
	g++ -c Appt.cc

Schedule.o: Schedule.cc Schedule.h
	g++ -c Schedule.cc

clean:
	$(RM) -f *.o vet.*