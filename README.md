### Simple JNI example
2 functions are exported, one creates a Java object and initializes with some values from C, and the other just displays something.

There is a Makefile in there with the following targets:
1. default - builds both the dynamic library with native code and the Java example classes which will use the library  
   `make` -> will build the java classes and the C library (.so)
2. clean - deletes the library, class files, object file and temp files  
   `make clean` -> cleans the dll, java .class, .o, .so
3. run - runs the example  
   `make run` -> runs the example from *com/test/Test.class*

### Prerequisites
1. gcc compiler
2. Java JDK 1.8 (but probably it will work with any version greater than 5)
3. make utilitary
4. Unix environment (I tested in WSL2)
5. have the JAVA_HOME environment variable set up correctly

### Updating the header file when native interface changes
`javah com.test.Test`
