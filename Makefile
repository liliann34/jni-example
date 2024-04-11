CC = gcc
FPIC = -fPIC
SHARED = -shared
LINKER = -lc
 
all: libngdump.so

libngdump.so: com_test_Test.o
	$(CC) $(SHARED) $(FPIC) $(LINKER) $< -o $@
 
com_test_Test.o: com_test_Test.c com_test_Test.h
	$(CC) $(FPIC) -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux -c $<
 
.PHONY: clean
clean:
	rm -f *.o *.so
