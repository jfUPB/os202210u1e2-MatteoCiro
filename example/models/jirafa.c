#include "jirafa.h"

static void _speak(Jirafa* this)
{
  printf("%s\n", this->name);
  printf("%s\n", "I am eating...:");
  printf("%s\n", "ÑamÑam");

	this->event = SPEAK;
	this->subject->notifyObservers(this->subject);
}

static void _destroy(Jirafa* this)
{
	this->subject->destroy(this->subject);

  if (NULL != this) {
    free(this);
    this = NULL;
  }
}

static JirafaEvent _getEvent(Jirafa* this)
{
	return this->event;
}

/**
 * Proxy method for Register an observer for the Jirafa object.
 * @param this
 * @param observer
 * @return
 */
static int _registerObserver(Jirafa* this, Observer* observer) {
  return this->subject->registerObserver(this->subject, observer);
}

/**
 * Proxy method for Unregister observer for the Cat object.
 * @param this
 * @param observer
 * @return
 */
static int _unregisterObserver(Jirafa * this, Observer* observer) {
  return this->subject->unregisterObserver(this->subject, observer);
}

Jirafa* Jirafa_create(char * name)
{
	Jirafa* this = (Jirafa *) malloc(sizeof(*this));
	this->name = name;
	this->destroy = _destroy;
	this->getEvent = _getEvent;
	this->speak = _speak;

	this->subject = subjectNew(this, 1);
	this->registerObserver = _registerObserver;
	this->unregisterObserver = _unregisterObserver;

	return this;
}