/* Authership Statement
 *
 * Andrew Wyllie
 * 2462111W
 * Sp Exercise 1a
 *
 * This is my own work as defined in the Academic Ethics agreement I have signed
 */

 #include "date.c"

Date *highdate;
highdate->d = 31;
highdate->m = 12;
highdate->y = 2018;

Date *lowdate;
highdate->d = 01;
highdate->m = 12;
highdate->y = 2017;

tldlist_create(begin, end){
     
    struct node
    {
        char hostname, begin, end;
        node *rightchild;
        node *leftchild;
    }

}
tld_destroy(d){

    while(d != NULL)
	{
		printf("'%s'\n", d);
		d = strtok(NULL, delim);
	}

}
tldlist_add(tld, hostname, d){

    if(data_compare(Date *d, Date *highdate) == "<0"){
        if(data_compare(Date *d, Date *highdate) == "<0"){
            if(tld==NULL)
                return new_node(d);
            else if(d>tld->data)
                tld->right_child = tldlist_add(tld->right_child, d);
            else 
                tld->left_child = tldlist_add(tld->left_child,x);
            return root;
        }
    }

    

}
tldlist_count(){

}
tldlist_iter_create(){

}
tldlist_iter_next(){

}
tldnode_tldname(){

}
tldnode_count(){

}

