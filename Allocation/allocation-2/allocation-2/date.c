#include <string.h>
#include <ctype.h>
#include "date.h"
#include <stdlib.h>
#include <stdio.h>
/*
Name: James Sharma
Login: 2469702s
Assignment: SP Exercise 1a
This is my own work as defined in the Academic Ethics agreeement I have signed
*/

struct date
{

    int day;
    int month;
    int year;
    int datelength;
};

/*
 * date_create creates a Date structure from `datestr`
 * `datestr' is expected to be of the form "dd/mm/yyyy"
 * returns pointer to Date structure if successful,
 *         NULL if not (syntax error)
 */
Date *date_create(char *datestr)
{

    Date *date = malloc(sizeof(Date));
    date->datelength = strlen(datestr);

    //check if input is the right length
    if (date->datelength != 10)
    {
        free(date);

        return NULL;
    }

    //todo: check if right number of digits before each slash

    char *slashes;
    slashes = strtok(datestr, "/");
    int noofslashes = 0;
    
    //check correct formatting of input
    while (slashes)
    {
        noofslashes++;
        slashes = strtok(NULL, "/");
    }
    if (noofslashes != 3)
    {
        free(date);

        return NULL;
    }
    //char * result = malloc(sizeof(char*) * date -> datelength);

    //char* slash = strtok(datestr, "/");

    char charday[3] = {datestr[0],datestr[1]};
    char charmonth[3]={datestr[3],datestr[4]};
    char charyear[5]={datestr[6],datestr[7],datestr[8],datestr[9]};
    //need to either strip slashes or use it on each day/month/yr


    /*
    memcpy(charday, datestr,2);
    charday[3]='\0';
    memcpy(charmonth, &datestr[3],2);
    charmonth[3]='\0';
    memcpy(charyear, &datestr[6],4);
    charyear[5]='\0';
    printf("maybe gets here");
    printf("%s\n",charday);
    printf("%s\n",charmonth);
    printf("%s\n",charyear);
    */
    date -> day = atoi(charday);
    date -> month = atoi(charmonth);
    date -> year = atoi(charyear);

    //date->day = datestr[0] + datestr[1];
    //date->month = datestr[3] + datestr[4];
    //date->year = datestr[6] + datestr[7] + datestr[8] + datestr[9];
    //Constructor, needs to convert passed in string into a proper Date structure
    //need to use malloc for that

    /*date -> day = *datestr, *datestr+1 & 0xFF;
    datestr+=3;
    date  -> month = *datestr, *datestr+1 & 0xFF;
    datestr+=3;
    date -> year = *datestr, *datestr+2,*datestr+3, *datestr+4 & 0xFFFF;
    */
    return date;
}

/*
 * date_duplicate creates a duplicate of `d'
 * returns pointer to new Date structure if successful,
 *         NULL if not (memory allocation failure)
 */
Date *date_duplicate(Date *d)
{
    Date *date = malloc(sizeof(Date));
    //todo: check date memory allocated correctly
    if(!date){return NULL;}
    date->day = d->day;
    date->month = d->month;
    date->year = d->year;
    date->datelength = d->datelength;
    return date;
}

/*
 * date_compare compares two dates, returning <0, 0, >0 if
 * date1<date2, date1==date2, date1>date2, respectively
 */
int date_compare(Date *date1, Date *date2)
{

    if (date1->year < date2->year)
        return -1;

    else if (date1->year > date2->year)
        return 1;

    if (date1->month < date2->month)
        return -1;
    else if (date1->month > date2->month)
        return 1;
    else if (date1->day < date2->day)
        return -1;
    else if (date1->day > date2->day)
        return 1;
    else
        return 0;
}

/*
 * date_destroy returns any storage associated with `d' to the system
 */
void date_destroy(Date *d)
{
    free(d);
    //need to add more to this once tldlist is done
}

