/*
 * esercizio-2020-05-23-thread-string.c
 *
 *  Created on: May 21, 2020
 *      Author: marco
 */


/***************TESTO ESERCIZIO***************
prendere la stringa di caratteri:

char * content = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Mattis rhoncus urna neque viverra justo nec ultrices. Pretium quam vulputate dignissim suspendisse in est ante. Vitae congue mauris rhoncus aenean. Blandit cursus risus at ultrices mi. Ut lectus arcu bibendum at varius vel pharetra vel. Etiam non quam lacus suspendisse faucibus interdum posuere. Eget sit amet tellus cras adipiscing enim eu turpis egestas. Lectus magna fringilla urna porttitor rhoncus dolor purus non. Sit amet consectetur adipiscing elit duis tristique sollicitudin nibh. Nec tincidunt praesent semper feugiat nibh. Sapien pellentesque habitant morbi tristique senectus et netus et malesuada.";

il processo crea tre threads; passa la stringa di caratteri content come parametro a ciascuno dei tre threads.

il primo thread conta il numero di vocali nella stringa e restituisce questo valore.

il secondo thread conta il numero di consonanti nella stringa e restituisce questo valore.

il terzo thread conta il numero di spazi e newline nella stringa e restituisce questo valore.

il thread principale aspetta il risultato dei tre threads e poi scrive su stdout i risultati.

*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#include <errno.h>
#include <pthread.h>

void * thread_function1(void * arg);
void * thread_function2(void * arg);
void * thread_function3(void * arg);

int main(int argc, char * argv[]) {
	char content[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Mattis rhoncus urna neque viverra justo nec ultrices. Pretium quam vulputate dignissim suspendisse in est ante. Vitae congue mauris rhoncus aenean. Blandit cursus risus at ultrices mi. Ut lectus arcu bibendum at varius vel pharetra vel. Etiam non quam lacus suspendisse faucibus interdum posuere. Eget sit amet tellus cras adipiscing enim eu turpis egestas. Lectus magna fringilla urna porttitor rhoncus dolor purus non. Sit amet consectetur adipiscing elit duis tristique sollicitudin nibh. Nec tincidunt praesent semper feugiat nibh. Sapien pellentesque habitant morbi tristique senectus et netus et malesuada.";
	pthread_t t1, t2, t3;
	int s;
	int * res;

	s = pthread_create(&t1, NULL, thread_function1, content);
	if (s != 0) {
		perror("pthread_create");
	}

	s = pthread_create(&t2, NULL, thread_function2, content);
	if (s != 0) {
		perror("pthread_create");
	}

	s = pthread_create(&t3, NULL, thread_function3, content);
	if (s != 0) {
		perror("pthread_create");
	}

	s = pthread_join(t1, &res);
	if (s != 0) {
		perror("pthread_join");
	}
	printf("Numero di vocali : %d\n", *res);

	s = pthread_join(t2, &res);
	if (s != 0) {
		perror("pthread_join");
	}
	printf("Numero di consonanti : %d\n", *res);

	s = pthread_join(t3, &res);
	if (s != 0) {
		perror("pthread_join");
	}
	printf("Numero di spazi e newline : %d\n", *res);

	printf("bye\n");

	return 0;
}

void * thread_function1(void * arg){
	int * cont;
	char * content;

	cont = calloc(1, sizeof(int));
	content = (char *) arg;


	for(int i = 0; i < strlen(content); i++){
		if(content[i] == 'a' || content[i] == 'e' || content[i] == 'i'
				|| content[i] == 'o' || content[i] == 'u'
				|| content[i] == 'A' || content[i] == 'E' || content[i] == 'I'
				|| content[i] == 'O' || content[i] == 'U')
			(*cont)++;
	}

	return cont;
}

void * thread_function2(void * arg){
	int * cont;
	char * content;

	cont = calloc(1, sizeof(int));
	content = (char *) arg;


	for(int i = 0; i < strlen(content); i++){
		if(content[i] == 'b' || content[i] == 'c' || content[i] == 'd'
				|| content[i] == 'f' || content[i] == 'g' || content[i] == 'h'
				|| content[i] == 'j' || content[i] == 'k' || content[i] == 'l'
				|| content[i] == 'm' || content[i] == 'n' || content[i] == 'p'
				|| content[i] == 'q' || content[i] == 'r' || content[i] == 's'
				|| content[i] == 't' || content[i] == 'v' || content[i] == 'w'
				|| content[i] == 'x' || content[i] == 'y' || content[i] == 'z'
				|| content[i] == 'B' || content[i] == 'C' || content[i] == 'D'
				|| content[i] == 'F' || content[i] == 'G' || content[i] == 'H'
				|| content[i] == 'J' || content[i] == 'K' || content[i] == 'L'
				|| content[i] == 'M' || content[i] == 'N' || content[i] == 'P'
				|| content[i] == 'Q' || content[i] == 'R' || content[i] == 'S'
				|| content[i] == 'T' || content[i] == 'V' || content[i] == 'W'
				|| content[i] == 'X' || content[i] == 'Y' || content[i] == 'Z')
			(*cont)++;
	}

	return cont;
}

void * thread_function3(void * arg){
	int * cont;
	char * content;

	cont = calloc(1, sizeof(int));
	content = (char *) arg;


	for(int i = 0; i < strlen(content); i++){
		if(content[i] == ' ' || content[i] == '\n')
			(*cont)++;
	}

	return cont;
}










