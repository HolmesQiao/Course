object = main.o

painter: $(object)
	clang++ -o painter $(object)

.PHONY: run
run:
	./painter
.PHONY: clean
clean:
	-rm $(object)
