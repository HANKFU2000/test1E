/* Authership Statement 

 * Andrew Wyllie
 * 2462111W
 * SP Exercise 1a
 *
 * This is my own work as defined in the Academic Ethics Agreement I have signed
 */

 #include <stdio.h>
 #include <string.h>

struct node 
{
    int date;
    struct node *rightchild;
    struct node *leftchild;
}

date_create(char *datestr);
{
    struct Date 
    {
        int d, m, y
    }
    return data
}

date_duplicate(Date *d)
{
    Date *ptr;
    
    ptr = d;

    return ptr;
}

date_compare(date1,date2)
{

    if (date1.y > date2.y){
        return ">0"
    }
    if (date1.y < date2.y){
        return "<0"
    }
    if (date1.y == date2.y){
        if (date1.m > date2.m){
            return ">0"
        }
        if (date1.m < date2.m){
            return "<0"
        }
        if (date1.m == date2.m){
            if (date1.y > date2.y){
                return ">0"
            }
            if (date1.y < date2.y){
                return "<0"
            }
            if (date1.y == date2.y){
                return "0"
            }
        }
    }

}

date_destroy(d)
{
    while(d != NULL)
	{
		printf("'%s'\n", d);
		d = strtok(NULL, delim);
	}
}