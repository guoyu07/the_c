/**
 * http://bbs.chinaunix.net/thread-130156-1-1.html
 */
#include <stdio.h>
#include <stdlib.h>

struct cow_s {
	int age;
	struct cow_s *next;
};
typedef struct cow_s cow_t;

#define BORN_AGE 4
static cow_t *head, *tail;
static int count;

void
grow(cow_t *cow)
{
	cow_t *c;

	cow->age++;
	if(cow->age >= BORN_AGE){
		c = (cow_t *) malloc(sizeof(cow_t));
		c->age = 0;
		c->next = NULL;

		tail->next = c;
		tail = c;
		count++;
	}
}

int
main()
{
	cow_t cow, *c, *tmp;
	int year = 10, n=0;

	cow.age = 0;
	cow.next = NULL;
	head = tail = &cow;
	count = 1;

	for(n = 0; n < year; n++) {
		for(c = head; c != NULL; c = c->next) {
			grow(c);
		}
	}

	printf("\n year %d, count %d", year, count);

	c = head->next;
	while(c != NULL) {
		tmp = c->next;
		free(c);
		c = tmp;
	}
	exit(0);
}
