#ifndef JIRAFA_H
  #define JIRAFA_H
  #include <stdio.h>
  #include <stdlib.h>
  #include "../../observer/observer.h"
  #include "../../observer/subject.h"

  typedef enum __jirafa_event
  {
    SPEAK
  } JirafaEvent;

  typedef struct __jirafa
  {
    char* name;
    void (*destroy)(struct __jirafa*);

    JirafaEvent event;
    JirafaEvent (*getEvent)(struct __jirafa*);

    void (*speak)(struct __jirafa*);

    Subject * subject;
    int (*registerObserver)(struct __jirafa*, Observer*);
    int (*unregisterObserver)(struct __jirafa *, Observer*);
  } Jirafa;
  Jirafa* JIRAFA_create(char *);

#endif