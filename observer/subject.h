#ifndef SUBJECT_H
	#define SUBJECT_H
	#include "observer.h"

	typedef struct __subject
	{
		int type;

		void (*destroy)(struct __subject *);

		void * impl;

		Observer * observers[MAX_OBSERVERS];

		int (*registerObserver)(struct __subject*, Observer*);

		int (*unregisterObserver)(struct __subject *, Observer*);

		void (*notifyObservers)(struct __subject*);
	} Subject;
	Subject * subjectNew(void*, int);

#endif
