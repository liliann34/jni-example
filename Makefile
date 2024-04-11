CC = gcc
FPIC = -fPIC
SHARED = -shared
LINKER = -lc
 
all: libngdump.so java_dep

java_dep: j_test j_task

j_test: com/test/Test.java
	javac $<

j_task: com/task/Task.java
	javac $<

libngdump.so: com_test_Test.o
	$(CC) $(SHARED) $(FPIC) $(LINKER) $< -o $@
 
com_test_Test.o: com_test_Test.c com_test_Test.h
	$(CC) $(FPIC) -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux -c $<
 
.PHONY: clean run
clean:
	rm -f *.o *.so *.gch
	find . -name *.class -delete

run:
	java -Djava.library.path=. com.test.Test
