#include "com_test_Test.h"
#include <stdio.h>

JNIEXPORT void JNICALL Java_com_test_Test_hi(JNIEnv *env, jobject obj) {
	printf("Hi, there, Jonathan!\n");	
}
