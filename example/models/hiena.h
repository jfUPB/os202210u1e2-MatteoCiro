#ifndef HIENA_H
	#define HIENA_H
 	#include <stdio.h>
	#include <stdlib.h>
	#include "../../observer/observer.h"
	#include "jirafa.h"

	typedef struct __hiena
	{
		char* name;
		void (*speak)(struct __hiena*);
		void (*destroy)(struct __hiena*);
		void (*attack)(struct __hiena*, Jirafa*);

		Observer* observer;
	} Hiena;
	Hiena* HIENA_create(char *);
#endif