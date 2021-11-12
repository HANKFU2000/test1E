#include "tldlist.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "date.h"
#include <stdio.h>
/*
Name: James Sharma
Login: 2469702s
Assignment: SP Exercise 1a
This is my own work as defined in the Academic Ethics agreeement I have signed
*/

struct tldlist
{
    long count;
    TLDNode *root;
    Date *startDate;
    Date *endDate;
};
struct tldnode
{
    long count;
    char *tld;
    TLDNode *left;
    TLDNode *right;
    
};
struct tlditerator
{
    long top;
    unsigned size;
    TLDNode **array;
    //parent not needed for iterator as stack made
};

/*
 * tldlist_create generates a list structure for storing counts against
 * top level domains (TLDs)
 *
 * creates a TLDList that is constrained to the `begin' and `end' Date's
 * returns a pointer to the list if successful, NULL if not
 */
TLDList *tldlist_create(Date *begin, Date *end)
{

    Date *newbegin = date_duplicate(begin);
    Date *newend = date_duplicate(end);

    //make root null along with left and rights, set count to 0

    TLDList *list = malloc(sizeof(TLDList));
    if (list)
    {
        list->startDate = newbegin;
        list->endDate = newend;
        list->root = NULL;
        list->count = 0;
    }
   return list;
}

/*
 * tldlist_destroy destroys the list structure in `tld'
 *
 * all heap allocated storage associated with the list is returned to the heap
 */
void tldlist_destroy(TLDList *tld)
{
    if (tld)
    {
        free(tld);
    }
    return;
    
}

static TLDNode* recursive_add(TLDList *list, char *tld, TLDNode *node)
{
    //if there's nothing there we need to set one up
    if (!node)
    {
        node = malloc(sizeof(TLDNode));
        if (!node)
        {
            free(node);
            return NULL;
        }
        else
        {
            node->tld = malloc(sizeof(char)*(strlen(tld)+1)); 
            strcpy(node -> tld, tld);
            node->count = 1;
            node->left = NULL;
            node->right = NULL;
        }
        list->root = node;
        return node;
    }

    if (strcmp(tld, node->tld) > 0)
    {
        node->right = recursive_add(list, tld, node->right);
    }
    else if (strcmp(tld, node->tld) < 0)
    {
        node->left = recursive_add(list, tld, node->left);
        
    }
    else
    {
        node->count++;
    }

    return node;
}

/*
 * tldlist_add adds the TLD contained in `hostname' to the tldlist if
 * `d' falls in the begin and end dates associated with the list;
 * returns 1 if the entry was counted, 0 if not
 */
int tldlist_add(TLDList *tld, char *hostname, Date *d)
{


    if (date_compare(tld->startDate, d) > 0 || date_compare(tld->endDate, d) < 0){

    

        return 0;
    }

    char *tldstr = NULL;
    char delimiter= '.';

    tldstr = strrchr(hostname,delimiter)+1;

    if (!tldstr)
    {
        //error, no dots found

        return 0;
    }

    tld->root = recursive_add(tld, tldstr, tld->root);
    tld->count++;

    return 1;
}

/*
 * tldlist_count returns the number of successful tldlist_add() calls since
 * the creation of the TLDList
 */
long tldlist_count(TLDList *tld)
{

    if (!tld)
        return 0;
    return tld->count;
}

static void traverse(TLDIterator *iter, TLDNode *node)
{
    if (!node)
        return;

    // first recur on left
    traverse(iter, node->left);

    iter->array[++iter->top] = node;

    //recur on right child
    traverse(iter, node->right);
}

/*
 * tldlist_iter_create creates an iterator over the TLDList; returns a pointer
 * to the iterator if successful, NULL if not
 */
TLDIterator *tldlist_iter_create(TLDList *tld)
{
    //make a stack thing

    TLDIterator *iter = malloc(sizeof(TLDIterator));
    if (!iter) return NULL;

    iter->size = tld->count;
    iter->top = -1;
    iter->array = malloc(iter->size * sizeof(TLDNode*));

    //need to do an inorder traversal here
    traverse(iter, tld->root);

    return iter;
}

/*
 * tldlist_iter_next returns the next element in the list; returns a pointer
 * to the TLDNode if successful, NULL if no more elements to return
 */
TLDNode *tldlist_iter_next(TLDIterator *iter)
{
    //just pop off stack
    if (iter->top <0)
        return NULL;

    //need to return a pointer
    return iter->array[iter->top--];
}

/*
 * tldlist_iter_destroy destroys the iterator specified by `iter'
 */
void tldlist_iter_destroy(TLDIterator *iter)
{
    free(iter->array);
    free(iter);
}

/*
 * tldnode_tldname returns the tld associated with the TLDNode
 */
char *tldnode_tldname(TLDNode *node)
{
    return node->tld;
}

/*
 * tldnode_count returns the number of times that a log entry for the
 * corresponding tld was added to the list
 */
long tldnode_count(TLDNode *node)
{
    return node->count;
}