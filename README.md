### Simple JNI example
2 functions are exported, one creates a Java object and initializes with some values from C, and the other just displays something.

There is a Makefile in there with the following targets:
1. default - builds both the dynamic library with native code and the Java example classes which will use the library
2. clean - deletes the library, class files, object file and temp files
3. run - runs the example
