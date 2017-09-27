objects = Main.o File.o

#compile file
Main: $(objects)
	cc -o Main $(objects)
Main.o: Main.c
	cc -c Main.c
File.o: File.c File.h
	cc -c File.c

# .PHONY: that's mean inform will execute although exist file.
.PHONY: Main.o File.o clean
clean:
	rm -f Main $(objects)
