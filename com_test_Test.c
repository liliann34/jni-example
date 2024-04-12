#include "com_test_Test.h"
#include <stdio.h>

JNIEXPORT void JNICALL Java_com_test_Test_hi(JNIEnv *env, jobject obj) {
	printf("Hi, there, Jonathan!\n");	
}


JNIEXPORT jobject JNICALL Java_com_test_Test_dummyTask(JNIEnv *env, jobject obj) {
	// Find the Task class
	jclass task_class = (*env)->FindClass(env, "com/task/Task");
	
	// Get the constructor method id
	jmethodID constructor = (*env)->GetMethodID(env, task_class, "<init>", "()V");
	
	// Create a new Task object
	jobject myObj = (*env)->NewObject(env, task_class, constructor);
	
	// Get the field ids
	jfieldID idField = (*env)->GetFieldID(env, task_class, "id", "I");
	jfieldID msgField = (*env)->GetFieldID(env, task_class, "desc", "Ljava/lang/String;");
	
	// Set the field values
	(*env)->SetIntField(env, myObj, idField, 1);
	(*env)->SetObjectField(env, myObj, msgField, (*env)->NewStringUTF(env, "hello"));
	
	return myObj;
}


JNIEXPORT jobject JNICALL Java_com_test_Test_dummyTasks(JNIEnv *env, jobject obj) {
	// fiund the array class
	jclass arrayListClass = (*env)->FindClass(env, "java/util/ArrayList");

	// find array constructor and add method
	jmethodID arrayListConstructor = (*env)->GetMethodID(env, arrayListClass, "<init>", "()V");
	jmethodID arrayListAdd = (*env)->GetMethodID(env, arrayListClass, "add", "(Ljava/lang/Object;)Z");

	// Create a new ArrayList
	jobject myList = (*env)->NewObject(env, arrayListClass, arrayListConstructor);

	// Find the Task class
	jclass task_class = (*env)->FindClass(env, "com/task/Task");

	// Get the constructor method id
	jmethodID constructor = (*env)->GetMethodID(env, task_class, "<init>", "()V");

	// Get the field ids
	jfieldID idField = (*env)->GetFieldID(env, task_class, "id", "I");
	jfieldID msgField = (*env)->GetFieldID(env, task_class, "desc", "Ljava/lang/String;");

	// Create a new Task object
	jobject myObj = (*env)->NewObject(env, task_class, constructor);

	// Set the field values
	(*env)->SetIntField(env, myObj, idField, 1);
	(*env)->SetObjectField(env, myObj, msgField, (*env)->NewStringUTF(env, "hello"));

	// Create a second Task object
	jobject mySecondObj = (*env)->NewObject(env, task_class, constructor);

	// Set the field values
	(*env)->SetIntField(env, mySecondObj, idField, 2);
	(*env)->SetObjectField(env, mySecondObj, msgField, (*env)->NewStringUTF(env, "bye"));

	// Add the objects to the ArrayList
	(*env)->CallBooleanMethod(env, myList, arrayListAdd, myObj);
	(*env)->CallBooleanMethod(env, myList, arrayListAdd, mySecondObj);

	return myList;
}
