#include <stdio.h>
#include "models/hiena.h"
#include "models/jirafa.h"

int main(int argc, char const *argv[])
{

	Hiena* chester = HIENA_create("Chester");
	Jirafa* pepe = JIRAFA_create("Pepe");

	chester->attack(chester, pepe);
	pepe->speak(pepe);

	pepe->destroy(pepe);
	chester->destroy(chester);

	return 0;
}
