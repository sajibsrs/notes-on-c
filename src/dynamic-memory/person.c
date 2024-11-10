#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// construct -> others operations -> destruct

Date date_construct(int y, int m, int d) {
    Date dob;

    dob.year = y;
    dob.month = m;
    dob.date = d;

    return dob;
}

Person *person_construct(char *n, int y, int m, int d) {
    Person *p;
    p = malloc(sizeof(Person));
    if (p == NULL) {
        printf("malloc fail\n");
        return NULL;
    }
    p->name = strdup(n); // malloc + strcpy
    p->dob = date_construct(y, m, d);

    if ((p->name) == NULL) {
        free(p);
        return NULL;
    }
    return p;
}

Person *person_copy(Person *p) {
    return person_construct(p->name, p->dob.year, p->dob.month, p->dob.date);
}

Person *person_assign(Person *p1, Person *p2) {
    free(p1->name);
    p1->dob = p2->dob;
    p1->name = strdup(p2->name);

    return p1;
}

void person_destruct(Person *p) {
    free(p->name);
    free(p);
}

void person_print(Person *p) {
    printf("Date of Birth: %d/%d/%d\n", p->dob.year, p->dob.month, p->dob.date);
    printf("Name: %s. \n", p->name);
}
