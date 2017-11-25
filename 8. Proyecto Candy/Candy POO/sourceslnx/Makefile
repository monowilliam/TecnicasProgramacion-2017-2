CC=g++
CFLAGS=-I.
DEPS = Juego.h \
	   Ficha.h \
	   Tablero.h \
	   GeneradorSimbolos.h \
	   GeneradorEtiquetas.h \
	   Terminal.h \
	   Tablero.h 
OBJ = maincandyoo.o \
      Ficha.o \
	  GeneradorEtiquetas.o \
	  GeneradorSimbolos.o \
	  Juego.o \
	  Tablero.o \
	  Terminal.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

candy2.exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o *~ core  

