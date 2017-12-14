objects = main.o draw.o control.o point.o line.o rectangle.o circle.o oval.o bezier.o fill.o

painter: $(objects) control.h draw.h data.h
	clang++ -o painter $(objects) -framework OpenGL -framework GLUT -framework Foundation
	./painter

main.o: data.h
draw.o: draw.h data.h
control.o: control.h data.h 
point.o: draw.h
line.o: draw.h
rectangle.o: draw.h
circle.o: draw.h
oval.o: draw.h
bezier.o: draw.h
fill.o: draw.h

.PHONY: run
run:
	./painter

.PHONY: clean
clean:
	-rm $(objects)
