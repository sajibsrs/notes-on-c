#ifndef PERSON_H
#define PERSON_H

typedef struct {
  int year;
  int month;
  int date;
} Date;

typedef struct {
  char* name;
  Date dob;
} Person;

// Constructs a new Date (Y/M/D).
Date date_construct(int y, int m, int d);

// Constructs a new Person.
Person* person_construct(char* n, int y, int m, int d);

// Creates a new copy of p1.
Person* person_copy(Person* p1);

// Assigns p2 to p1.
Person* person_assign(Person* p1, Person* p2);

// Removes a Person and cleanups.
void person_destruct(Person* p);

// Prints information of a Person.
void person_print(Person* p);

#endif
