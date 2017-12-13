objects = main.o draw.o control.o point.o line.o

painter: $(objects) control.h draw.h status.h data.h
	clang++ -o painter $(objects) -framework OpenGL -framework GLUT -framework Foundation
	./painter

main.o: data.h
draw.o: draw.h data.h
control.o: control.h data.h 
point.o: draw.h
line.o: draw.h

.PHONY: clean
clean:
	-rm $(objects)
