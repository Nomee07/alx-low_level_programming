#include <stddef.h>
#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - Initializes a variable type of struct dog.
 * @d: A pointer to initialize.
 * @name: A name to initialize.
 * @age: The age to initialize.
 * @owner: The owner to initialize.
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		d = malloc(sizeof(struct dog));
	d->name = name;
	d->age = age;
	d->owner = owner;
}
