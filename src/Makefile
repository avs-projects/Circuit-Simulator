CPP=g++ --std=c++11
CFLAGS= -Wall

all : main 

main : main.o Gate.o InputGate.o OutputGate.o AndGate.o NAndGate.o NegateGate.o OrGate.o NOrGate.o XOrGate.o NXOrGate.o ConvertExp.o Node.o SaveFile.o Trunk.o ExpGate.o 
	$(CPP) $(CFLAGS) -o $@ $^

main.o : main.cpp
	$(CPP) $(CFLAGS) -c $<

TestsPortes.o : TestsPortes.cpp
	$(CPP) $(CFLAGS) -c $<

TestsExpSave.o : TestsExpSave.cpp
	$(CPP) $(CFLAGS) -c $<

Gate.o : Gate.cpp Gate.hpp
	$(CPP) $(CFLAGS) -c $<

InputGate.o : gates/InputGate.cpp gates/InputGate.hpp
	$(CPP) $(CFLAGS) -c $<

OutputGate.o : gates/OutputGate.cpp gates/OutputGate.hpp
	$(CPP) $(CFLAGS) -c $<
	
AndGate.o : gates/AndGate.cpp gates/AndGate.hpp
	$(CPP) $(CFLAGS) -c $<

NAndGate.o : gates/NAndGate.cpp gates/NAndGate.hpp
	$(CPP) $(CFLAGS) -c $<

NegateGate.o : gates/NegateGate.cpp gates/NegateGate.hpp
	$(CPP) $(CFLAGS) -c $<

OrGate.o : gates/OrGate.cpp gates/OrGate.hpp
	$(CPP) $(CFLAGS) -c $<

NOrGate.o : gates/NOrGate.cpp gates/NOrGate.hpp
	$(CPP) $(CFLAGS) -c $<

XOrGate.o : gates/XOrGate.cpp gates/XOrGate.hpp
	$(CPP) $(CFLAGS) -c $<
	
NXOrGate.o : gates/NXOrGate.cpp gates/NXOrGate.hpp
	$(CPP) $(CFLAGS) -c $<

ConvertExp.o : ConvertExp.cpp ConvertExp.hpp
	$(CPP) $(CFLAGS) -c $<

Node.o : Node.cpp Node.hpp
	$(CPP) $(CFLAGS) -c $<

SaveFile.o : SaveFile.cpp SaveFile.hpp
	$(CPP) $(CFLAGS) -c $<

Trunk.o : Trunk.cpp Trunk.hpp
	$(CPP) $(CFLAGS) -c $<

ExpGate.o : ExpGate.cpp ExpGate.hpp
	$(CPP) $(CFLAGS) -c $<


clean :
	rm *.o


