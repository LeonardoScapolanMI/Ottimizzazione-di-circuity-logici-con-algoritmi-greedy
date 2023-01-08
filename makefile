OPTION = -Wall -Wfatal-errors

driver.exe: driver.o Componente.o Circuito.o Gate.o Segnale.o Config.o
	g++ -o driver.exe driver.o Componente.o Circuito.o Gate.o Segnale.o Config.o

driver.o: driver.cpp Componente.hpp Circuito.hpp Gate.hpp Config.hpp Segnale.hpp
	g++ -c $(OPTION) driver.cpp

Circuito.o: Circuito.cpp Circuito.hpp Componente.hpp Gate.hpp Config.hpp Segnale.hpp
	g++ -c $(OPTION) Circuito.cpp
	
Gate.o: Gate.cpp Gate.hpp Componente.hpp Segnale.hpp
	g++ -c $(OPTION) Gate.cpp
	
Componente.o: Componente.cpp Componente.hpp Config.hpp
	g++ -c $(OPTION) Componente.cpp

Segnale.o: Segnale.cpp Segnale.hpp
	g++ -c $(OPTION) Segnale.cpp

Config.o: Config.cpp Config.hpp Circuito.hpp Componente.hpp Gate.hpp
	g++ -c $(OPTION) Config.cpp
