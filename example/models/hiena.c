#include "hiena.h"

static void _destroy(Hiena* this)
{
	this->observer->destroy(this->observer);

	if (this != NULL){
		free(this);
		this = NULL;
	}
}
static void _attack(Hiena * this, Jirafa* jirafa)
{
	jirafa->registerObserver(jirafa, this->observer);
	printf("%s Just attacked %s\n", this->name, jirafa->name);
}
/**
 * Observer Method called upon the receiption of an incoming event.
 * @param type
 * @param subject
 */
static void _notify(Hiena* this, int numero, void* subject) {
	_handleJirafaEvent(this, (Jirafa*) subject);
}
Hiena* HIENA_create(char* hienasName)
{
	Hiena* this = (Hiena*) malloc(sizeof(*this));

	this->name = hienasName;
	this->attack = _attack;
	this->destroy = _destroy;
	this->observer = observerNew(this, (void (*)(void*, int, void*))_notify);
	return this;
}