#ifndef API_H
#define API_H

// Some useful imports so you do not have to do this yourself
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

typedef struct Person {
    char *first_name; // pointer to a string representing the first name
    char *last_name;  // pointer to a string representing the first name
    char male;        // 1 for male, 0 for female
    char wizard;      // 1 for wizard, 0 for muggle
    uint32_t age;     // 32 bits unsigned int representing the age
    float latitude;   // latitude of his last know residence
    float longitude;  // longitude of his last know residence
} Person;

/** Data structure holding the content of the database. */
typedef struct DB DB;

/** ID of a person  64bits integer. */
typedef int64_t pid ;

/** Initializes the database with the 'num_elements' persons given in the array. */
DB* db_init(Person* persons_array, int num_elements);

/** Frees all memory used by the database. */
void db_free(DB *);

/** Returns the person with the given id */
Person db_get(DB *db, pid person_id);

/** Returns the number of males in the database. */
uint32_t db_count_male(DB * db);

/** Returns the age of the oldest person. */
uint32_t db_max_age(DB * db);

/** Returns the ID of the oldest person. If multiple person have the same age, this should return the one with the highest ID. */
pid db_oldest(DB * db);

/** Return ID of the closest person in the database. */
pid db_closest(DB *db, float lat, float lon);

/** Counts the number of female muggles in the database.  */
uint32_t db_count_female_muggles(DB *db);







#endif