lxcbk: lxcbk.o 
	gcc lxcbk.o -o lxcbk -O3
	
static: lxcbk
	gcc lxcbk.o -o lxcbk -O3 -static
	
clean:
	rm *.o