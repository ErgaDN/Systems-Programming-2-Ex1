#include "AdptArray.h"
#include "book.h"
#include "Person.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


int main() {

	pbook b1 = creat_book("Tom & Jerry",11111) ;
	pbook b2= creat_book("Probability 1", 22222) ;
    pbook b3= creat_book("Probability 2", 33333) ;

	PAdptArray mybooks = CreateAdptArray(copy_book,delete_book,print_book);
    
	SetAdptArrayAt(mybooks,3,b1);
	SetAdptArrayAt(mybooks,5,b2);
	printf("Size = %d\n",GetAdptArraySize(mybooks));

    SetAdptArrayAt(mybooks,5,b3);
    printf("Size = %d\n",GetAdptArraySize(mybooks));

	pbook b = GetAdptArrayAt(mybooks,4);
	assert(b==NULL);
    
	b = GetAdptArrayAt(mybooks,3);
	printf("the book is %s\n",b->name); //should print "Harry Potter"
	PrintDB(mybooks);

	
	DeleteAdptArray(mybooks);
	delete_book(b1);
	delete_book(b2);
    delete_book(b3);
	delete_book(b);
	return 0;
}
