// Alex Augello, Vlady Salazar, Altin Ame

// C & Unix Project -- Phonebook

// libraries used
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


void add(); // function prototypes
void search();
void sort();
void deleterow();
void update();
void view();
void clearall();

// start main
int main()
{
	printf("\t\t\t  Welcome to the Phonebook\n");
    char response[2];

    do // start do while loop to ask for repeat input
    {
   	 	char answer[20];
   	 	printf("Phonebook Options:\n1. View(view);\n2. Add(add);\n3. Search(search);\n4. Delete(delete);\n5. Clear;\n6. Update;\nEnter Option: ");
   	 	scanf("%s", answer);
   	 	answer[0] = tolower(answer[0]); // make user input lowercase for easier string comparison
   	 	bool theanswer = true; // variable to control invalid/valid inputs

   	 	// when the bool value is true the user entered an invalid input and the program asks the user to retry
   	 	// when the bool value is false the user entered a correct input and the program continues

   	 	if(strcmp(answer, "add") == 0) // strcmp compares response to "add". If user types in "add" strcomp returns 0
   	 	{
     	   	theanswer = false; // set the bool value to false to skip over while loop and continue
   	 	}
    	if(strcmp(answer, "view") == 0)
   	 	{
        	theanswer = false;
   	 	}
    	if(strcmp(answer, "search") == 0)
   	 	{
        	theanswer = false;
   	 	}
    	if(strcmp(answer, "delete") == 0)
   	 	{
        	theanswer = false;
   	 	}
    	if(strcmp(answer, "clear") == 0)
   	 	{
        	theanswer = false;
   	 	}
    	if(strcmp(answer, "update") == 0)
   	 	{
        	theanswer = false;
   	 	}

   	 	// while loop with the condition "true" aka invalid input entered

   	 	while(theanswer) 
   	 	{
   	 		printf("Invalid input\nEnter option: ");
   	 		scanf("%s", answer);
   	 		answer[0] = tolower(answer[0]);

   	 	// reenter input, same logic as above

    		if(strcmp(answer, "add") == 0) 
   	 		{
        		theanswer = false; // valid response entered, exit out of loop
   	 		}	
    		if(strcmp(answer, "view") == 0)
   	 		{
        		theanswer = false;
   	 		}
    		if(strcmp(answer, "search") == 0)
   	 		{
        		theanswer = false;
   	 		}
    		if(strcmp(answer, "delete") == 0)
   	 		{	
        		theanswer = false;
   	 		}
    		if(strcmp(answer, "clear") == 0)
   	 		{
        		theanswer = false;
   	 		}
    		if(strcmp(answer, "update") == 0)
   	 		{
        		theanswer = false;
   	 		}
   	 	} // end while(theanswer)


   	 	// valid input was entered
   	 	if(strcmp(answer, "add") == 0) // if user types "add"
   	 	{
   		 	add(); // run add function
   		 	sort(); // run sort function after the user adds a new entry
   	 	}

		if(strcmp(answer, "search") == 0) // if user types "search"
   	 	{
   		 	search(); // run search function
   	 	}
   	 	else if(strcmp(answer, "delete") == 0) // if user types "delete"
   	 	{
         	printf("Viewing the phonebook for reference: \n"); 
   		 	view(); // run view function for easy deletion
   		 	deleterow(); // run deleterow function
   	 	}

   	 	else if(strcmp(answer, "update") == 0) // if user types "update"
   	 	{
   		 	printf("Viewing the phonebook for reference: \n");
   		 	view(); // run view function for easy updating
   		 	update(); // run update function
   		 	sort(); // run sort after user updates the phonebook
   	 	}

   	 	else if(strcmp(answer, "view") == 0) // if user types "view"
   	 	{
   		 	view(); // run view function
   	 	}
   	 	else if(strcmp(answer, "clear") == 0) // if user types "clear"
   	 	{
   			clearall(); // run the clearall function which wipes the phonebook
   	 	}

	   	printf("Run again? (y/n)\n"); // prompt user to run phonebook program again
	   	scanf(" %s", response);
	   	response[0] = toupper(response[0]); // set users response to uppercase letter for easier comparison
	   	bool check = true; // same logic as previous. bool variable to control valid/invalid input

	   	if(strcmp(response, "Y") == 0) // if user types Y
	   	 	{
	        	check = false; // set check variable to false to skip over while loop
	   	 	}
	   	else if(strcmp(response, "N") == 0) // if user types 'N'
	   	 	{
	        	check = false; // set check variable to false to skip over while loop
	   	 	}


	   	 while(check) // while check variable is "true" -- invalid input was entered
	   	 {
	        printf("Invalid input. Enter (y/n): \n"); // prompt user for response
	        scanf(" %s", response);
	        response[0] = toupper(response[0]); // set their response to uppercase character
	    
	     	if(strcmp(response, "Y") == 0) // if user types Y
	   	 	{
	        	check = false; // set check variable to false to exit out of this check loop
	   	 	}
	   	 	else if(strcmp(response, "N") == 0) // if user types 'N'
	   	 	{
	        	check = false; // set check variable to false to exit out of this check loop
	   	 	}
	   	 }

    }while(strcmp(response, "Y") == 0); // re-run program if response is Y

    printf("Exiting the Phonebook\n"); // otherwise exit and end program
    return 0;
}

// clearall function deletes the phonebook
void clearall()
{
    FILE *Ph;
    Ph = fopen("Phonebook.txt", "w"); // opening an existing file in "w" mode wipes all of its contents
    fclose(Ph); // close the file

}

// view function prints out the contents of the phonebook text file to the user
void view()
{

    FILE *Ph; // file 
    Ph = fopen("Phonebook.txt", "r"); // open function in read mode
    char line[1000]; // line array to print contents of each line
    char q = 0; // line number variable
    if(!Ph) // error checking if file failed to open
    {
   	 	fprintf(stderr, "Error: failed to open file\n");
    }

    else
    {
   	 while(fgets(line, sizeof line, Ph) != NULL) // when not at end of file
   	 {
   		 q++; // increment line counter
   		 printf("%d. %-s", q, line); // print out the line
   	 }
    }
    fclose(Ph); // close the file
}

// add function adds an entry to the phonebook
void add()
{
    FILE *Ph; // file
    Ph = fopen("Phonebook.txt", "a+"); // opening the file in both read and write mode
    if(!Ph) // error checking if file failed to open
    {
   	 	fprintf(stderr, "Error: failed to open file\n");
    }

    char first[40]; // character array that stores the first name
    char last[40]; // character array that stores the last name
    char num[40]; // character array that stores the phone number
   	

    printf("Enter first name: "); // prompt the user to enter the first name
    scanf("%s", first);
    puts("");

    printf("Enter last name: "); // prompt the user to enter last name
    scanf("%s", last);
    puts("");

    printf("Enter phone number: "); // prompt the user to enter phone number
    scanf("%s", num);
    while (strlen(num) !=10)
    {
    	printf("Please Enter Valid 10-digit Phone Number: "); // checks that the phone number is a 10 length number 
    	scanf("%s", num);
    }
	puts("");

    first[0] = toupper(first[0]); // set first letter to uppercase
    last[0] = toupper(last[0]); // set first letter to uppercase

    char line3[1000]; // character buffer array
    char *aptr1; // will hold token
    char *aptr2; // will hold token
    char *aptr3; // will hold token
    int x = 0; // flag variable

    while(fgets(line3, sizeof(line3), Ph) != NULL) // when not at end of file (line by line)
    {
		char *aptr = strtok(line3, " \n"); // token delimiter is " " or "\n"
		aptr1 = aptr; // set first token(first name) to aptr1
		aptr = strtok(NULL, " \n"); // set aptr to NULL to get next token

		aptr2 = aptr; // set second token(last name) to aptr2
		aptr = strtok(NULL, " \n"); // set aptr to NULL to get next token

		aptr3 = aptr; // set third token(number) to aptr3
		while(aptr != NULL) // nested while loop
		{
  	  		if(strcmp(aptr3, num) == 0) // if aptr3 and number are the same, this will return 0
  	  		{
  	  			// number is already in file
  	  			x = 1; // flag variable
  	  			printf("Number already in phonebook!\n"); // tell user number is already in file
  	  		}

  	  		aptr = strtok(NULL, " \n"); // break out of nested loop and start new set of tokens (next line)
		}
	}

if(x!=1) // if flag variable is not 1, number was not already in phonebook
{
	fprintf(Ph, "%-12s %-12s %-12s\n", first, last, num); // print the first name, last name, and number to file
}

    fclose(Ph); // close file
}

// search function
void search()
{
    FILE *Ph = fopen("Phonebook.txt", "r"); // open file in read mode
    if(!Ph) // error check if file failed to open
    {
   	 	fprintf(stderr, "Error: failed to open file\n");
    }
    char first[100]; // first name character array
    char last[100]; // last name character array
    char number[100]; // phone number character array

    char searchby[20]; // user input variable

    printf("Search Options:\n1. First Name(first);\n2. Last Name(last);\n3. Both Names(both);\n4. Number(number);\nEnter Option: ");
    scanf("%s", searchby);
    searchby[0] = tolower(searchby[0]); // make input lowercase for easier comparison

	bool ifbool = true; // bool variable set to true
	if(strcmp(searchby, "first") == 0) // if the user types "first"
	{
		ifbool = false; // set bool variable to false
	}
	else if(strcmp(searchby, "last") == 0) // if the user types "last"
	{
		ifbool = false; // set bool variable to false
	}
	else if(strcmp(searchby, "number") == 0) // if the user types "number"
	{
		ifbool = false; // set bool variable to false
	}
	else if(strcmp(searchby, "both") == 0) // if the user types "both"
	{
		ifbool = false; // set bool variable to false
	}

    while(ifbool) // while bool variable is true (aka invalid input)
    {
    printf("Invalid input\n");
    printf("Enter Option: ");
    scanf("%s", searchby); // ask user to reenter input

    searchby[0] = tolower(searchby[0]);

    // same logic as above
	if(strcmp(searchby, "first") == 0)
	{
		ifbool = false;
	}
	else if(strcmp(searchby, "last") == 0)
	{
		ifbool = false;
	}
	else if(strcmp(searchby, "number") == 0)
	{
		ifbool = false;
	}
	else if(strcmp(searchby, "both") == 0)
	{
		ifbool = false;
	}

	}

    if(strcmp(searchby, "first") == 0) // if user entered first
    {
    printf("Enter first name: \n"); // ask user to input first name
    scanf("%s", first);
	first[0] = toupper(first[0]);
    char linez[300]; // character buffer array
    char *qptr1;
    char *qptr2;
    char *qptr3;
    int x = 0;
    bool tobreak = false;
	while(fgets(linez, sizeof linez, Ph)!=NULL)
    {
    	char *qptr = strtok(linez, " \n"); // token delimiters are spaces and newlines
    	qptr1 = qptr;
    	qptr = strtok(NULL, " \n");
    	qptr2 = qptr;
    	qptr = strtok(NULL, " \n");
    	qptr3 = qptr;

    	while(qptr != NULL)
    	{
        	if(strcmp(qptr1, first) == 0) // if name is in phonebook
        	{
   		 		x = 1; // flag variable to indicate name is in phonebook
   		 		tobreak = true;
   		 		break;
        	}
        	qptr = strtok(NULL, " \n"); // break out of loop and start on next line
    	}
    	if(tobreak) // break out of loop since name is in phonebook
        	break;
    }
    if(x == 0)
    {
    	printf("First name not found!\n"); // First name is not in phonebook
    }
    else if(x == 1)
    {
	rewind(Ph); // reset file pointer back to start of file
    printf("All numbers with the first name of %s\n", first); // print all numbers with the first name entered
    char line3[1000];
    char *aptr1;
    char *aptr2;
    char *aptr3;
    
    while(fgets(line3, sizeof(line3), Ph) != NULL)
    {
	char *aptr = strtok(line3, " \n"); // split each line into file into tokens
	aptr1 = aptr; // this token holds the first name
	aptr = strtok(NULL, " \n");
	aptr2 = aptr; // this token holds the last name
	aptr = strtok(NULL, " \n");
	aptr3 = aptr; // this token holds the phone number
	while(aptr != NULL)
	{
  	  if(strcmp(aptr1, first) == 0) // if first token equals first name
  	  {
  	  printf("%s %s %s\n", aptr1, aptr2, aptr3); // print out all numbers with the given first name
      puts("");
  	  }
  	  aptr = strtok(NULL, " \n");
	}
    }

	}	
    }


    if(strcmp(searchby, "last") == 0)
    {
    printf("Enter last name: \n");
    scanf("%s", last);
    last[0] = toupper(last[0]); // set first name 

	char linec[300];
    char *rptr1;
    char *rptr2;
    char *rptr3;
    int y = 0;
    bool tobreak = false;
	while(fgets(linec, sizeof linec, Ph)!=NULL)
    {
    	char *rptr = strtok(linec, " \n"); // token delimiters are spaces and newlines
    	rptr1 = rptr; // first name token
    	rptr = strtok(NULL, " \n"); // get next token
    	rptr2 = rptr; // last name token
    	rptr = strtok(NULL, " \n"); // get next token
    	rptr3 = rptr; // phone number token

    	while(rptr != NULL)
    	{
        	if(strcmp(rptr2, last) == 0) // if inputted last name == token
        	{
   		 		y = 1; // set flag variable to 1, means last name is in phonebook
   		 		tobreak = true;
   		 		break;
        	}
        	rptr = strtok(NULL, " \n"); // break out and start next line 
    	}
    	if(tobreak) // break out of loop since name is in phonebook
        	break;
    }
    if(y == 0) // if flag variable is 0 the last name is not in phonebook
    {
    	printf("Last name not found!\n"); // last name isn't in phone book
    }
    else if(y == 1)
    {
    rewind(Ph); // restart pointer at beginning of file
    printf("All numbers with the last name of %s\n", last);
    char line3[1000];
    char *aptr1;
    char *aptr2;
    char *aptr3;
    int x = 0;
    while(fgets(line3, sizeof(line3), Ph)!=NULL)
    {
	char *aptr = strtok(line3, " \n"); // token delimiters are spaces and newlines
	aptr1 = aptr; // first name token
	aptr = strtok(NULL, " \n");
	aptr2 = aptr; // last name token
	aptr = strtok(NULL, " \n");
	aptr3 = aptr; // phone number token
	while(aptr != NULL)
	{
  	  if(strcmp(aptr2, last) == 0) // if 2nd token == last name
  	  {
  	  	printf("%s %s %s\n", aptr1, aptr2, aptr3); // print this line
  	  }
  	  aptr = strtok(NULL, " \n"); // repeat process on next line
	}
    }

}
    }


    if(strcmp(searchby, "number") == 0)
    {
    printf("Enter number: \n");
    scanf("%s", number);

	char linep[300];
    char *pptr1;
    char *pptr2;
    char *pptr3;
    int p = 0;
    bool tobreak = false;
	while(fgets(linep, sizeof linep, Ph) != NULL) // go through entire file
    {
    	char *pptr = strtok(linep, " \n"); // get next token
    	pptr1 = pptr; // first name token
    	pptr = strtok(NULL, " \n"); // get next token
    	pptr2 = pptr; // last name token
    	pptr = strtok(NULL, " \n"); // get next token
    	pptr3 = pptr; // phonenum token

    	while(pptr != NULL)
    	{
        	if(strcmp(pptr3, number) == 0) // if third token == inputted number
        	{
   		 		p = 1; // set flag variable to 1, means number was found in phonebook
   		 		tobreak = true;
   		 		break;
        	}
        	pptr = strtok(NULL, " \n");
    	}
    	if(tobreak)
        	break;
    }
    if(p == 0) // if flag variable == 0 the number was not found
    {
    	printf("Number not found!\n");
    }
    else if(p == 1) // number was found
    {
    rewind(Ph); // reset back to beginning of file

    char line3[1000];
    char *aptr1;
    char *aptr2;
    char *aptr3;
    int x = 0;
    while(fgets(line3, sizeof(line3), Ph) != NULL)
    {
	char *aptr = strtok(line3, " \n"); // token delimiters are spaces and newlines
	aptr1 = aptr; // first name token
	aptr = strtok(NULL, " \n");
	aptr2 = aptr; // last name token
	aptr = strtok(NULL, " \n");
	aptr3 = aptr; // phone num token
	while(aptr != NULL)
	{
  	  if(strcmp(aptr3, number) == 0) // if third token == inputted number
  	  {
  	  printf("%s belongs to %s %s\n\n", aptr3, aptr1, aptr2); // print out this line
  	  }
  	  aptr = strtok(NULL, " \n"); // get next line
	}
    }

}
    }

    if(strcmp(searchby, "both") == 0)
    {
    printf("Enter first name: \n");
    scanf("%s", first);
    printf("Enter last name: \n");
    scanf("%s", last);
    first[0] = toupper(first[0]);
    last[0] = toupper(last[0]);


	char lined[300];
    char *dptr1;
    char *dptr2;
    char *dptr3;
    int z = 0;
    bool tobreak = false;
	while(fgets(lined, sizeof lined, Ph) != NULL)
    {
    	char *dptr = strtok(lined, " \n"); // token delimiters are spaces and newlines
    	dptr1 = dptr; // first name
    	dptr = strtok(NULL, " \n");
    	dptr2 = dptr; // last name
    	dptr = strtok(NULL, " \n");
    	dptr3 = dptr; // phonenum

    	while(dptr != NULL)
    	{
        	if(strcmp(dptr1, first) == 0)
        	{
   		 		z = 1; // first name was found so set flag to 1
   		 		tobreak = true;
   		 		break;
        	}
        	dptr = strtok(NULL, " \n");
    	}
    	if(tobreak)
        	break;
    }
    if(z == 0) // if flag == 0 name was not found
    {
    	printf("First name not found!\n");
    }
    rewind(Ph); // reset back to beginning

	char linew[300];
    char *wptr1;
    char *wptr2;
    char *wptr3;
    int w = 0;
    bool tobreak1 = false;
	while(fgets(linew, sizeof linew, Ph) != NULL)
    {
    	char *wptr = strtok(linew, " \n"); // token delimiters are spaces and newlines
    	wptr1 = wptr;
    	wptr = strtok(NULL, " \n");
    	wptr2 = wptr;
    	wptr = strtok(NULL, " \n");
    	wptr3 = wptr;

    	while(wptr != NULL)
    	{
        	if(strcmp(wptr2, last) == 0)
        	{
   		 		w = 1;
   				tobreak1 = true;
   		 		break;
        	}
        	wptr = strtok(NULL, " \n");
    	}
    	if(tobreak1)
        	break;
    }
    if(w == 0) // name wasn't found
    {
    	printf("Last name not found!\n");
    }

    else if(z == 1 && w == 1) // both last and first name need to be found
    {
	rewind(Ph);

    char line3[1000];
    char *aptr1;
    char *aptr2;
    char *aptr3;
    int x = 0;
    while(fgets(line3, sizeof(line3), Ph)!=NULL)
    {
	char *aptr = strtok(line3, " \n");
	aptr1 = aptr; // first name token
	aptr = strtok(NULL, " \n");
	aptr2 = aptr; // last name token
	aptr = strtok(NULL, " \n");
	aptr3 = aptr; // phone num token
	while(aptr != NULL)
	{
  	  if(strcmp(aptr1, first) == 0 && strcmp(aptr2, last) == 0) // if first token == first name AND second token == last name
  	  {
  	  	printf("%s belongs to %s %s\n\n", aptr3, aptr1, aptr2); // print this line
  	  }
  	  aptr = strtok(NULL, " \n"); // get next line
	}
    }


    }
}

    }


// sort function uses bubble sort algorithm to sort the phonebook
void sort()
{
    FILE *Ph;
    FILE *temp;
    Ph = fopen("Phonebook.txt", "r");
    temp = fopen("temporary.txt", "w"); // we create a temporary text file
    char data[50][300]; // 2D array: first is line, second is characters in each line
    char temp1[300]; // character buffer array
    int line = 0;
    while(!feof(Ph) && !ferror(Ph)) // while not at end of file and file successfully opened
    {
	   	 if(fgets(data[line], 300, Ph) != NULL)
	   	 	line++; // increment line counter
    }

    if(line != 1) // if phonebook has more than 1 entry
    {
	    int i;
	    int j;
	    int count = line;

   
	    for(i = 0; i < count; i++) // loop over all lines
	    {
	   		if(count == 1)
	   	 		break;
		   	for(j = i + 1; j <= count - 1; j++)
		   	{
		   		if(strcmp(data[i], data[j]) > 0) // compare first element with second element
		   		 								  // by ASCII character value 
		   		{
		       		 strcpy(temp1, data[i]); // hold data[i] into temp1
		       		 strcpy(data[i], data[j]); // replace data[i] value w/ data[j] (swap)
		       		 strcpy(data[j], temp1); // set data[j] to temp1 (which was holding data[i])
		   		}

		   	}

	    }

	    for( i = 0; i < count; i++)
	    {
	   	 	fprintf(temp, "%s", data[i]); // print sorted phonebook into temp file
	    }

	    fclose(Ph); // close files
	    fclose(temp);
	    remove("Phonebook.txt"); // delete unsorted Phonebook
	    rename("temporary.txt", "Phonebook.txt"); // rename sorted text file to Phonebook
	}
    if(line == 1) // if only 1 line no sorting needed
    {
	    fclose(Ph); // close files
	    fclose(temp);
	    remove("temporary.txt"); // no sorting was needed so delete temp text file we created
	}
}


// the deleterow function deletes an entry specified by the user
void deleterow()
{
    FILE *Ph;
    FILE *temp;
    Ph = fopen("Phonebook.txt", "r"); // open phonebook for reading
    temp = fopen("temporary.txt", "w"); // open temp text file for writing -- we will write every line but the line we want to delete into this file
    char line[1000];
    char num[20];
    printf("What number would you like to delete?\n"); // ask user what number they want to delete
    scanf("%s", num);


	char linet[300];
    char *tptr1;
    char *tptr2;
    char *tptr3;
    int t = 0;
    bool tobreak = false;
	while(fgets(linet, sizeof linet, Ph) != NULL)
    {
    	char *tptr = strtok(linet, " \n"); // token delimiters are spaces and newlines
    	tptr1 = tptr; // first name token
    	tptr = strtok(NULL, " \n");
    	tptr2 = tptr; // last name token
    	tptr = strtok(NULL, " \n");
    	tptr3 = tptr; // phone number token

    	while(tptr != NULL)
    	{
        	if(strcmp(tptr3, num) == 0) // if third token is the inputted number
        	{
   		 		t = 1; // set flag to 1 to indicate number was found
   		 		tobreak = true;
   		 		break;
        	}
        	tptr = strtok(NULL, " \n");
    	}
    	if(tobreak)
        	break;
    }
    if(t == 0) // number wasn't found
    {
    	printf("Number not found!\n"); 
    	fclose(Ph);
    	fclose(temp);
    	remove("temporary.txt"); // delete temporary file since it wasn't needed
    }
    else if(t == 1)
    {
		rewind(Ph); // restart back to beginning file
	    int i;
	    int x = 0;
	    char *ptr1;
	    char *ptr2;
	    char *ptr3;
	    while(fgets(line, sizeof line, Ph) != NULL)
	    {
			char *ptr = strtok(line, " \n");
			ptr1 = ptr; // first name token
			ptr = strtok(NULL, " \n");
			ptr2 = ptr; // last name token
			ptr = strtok(NULL, " \n");
			ptr3 = ptr; // phone num token

			while(ptr != NULL)
			{
			  	  if(strcmp(ptr3, num) != 0) // we print every line into the phonebook except for the line that holds the number we want to delete
			  	  {
			   		 fprintf(temp, "%-12s %-12s %-12s\n", ptr1, ptr2, ptr3); // print this line into temp file
			  	  }
			  	  ptr = strtok(NULL, " \n"); // next line
			}
		}


		fclose(Ph);
		fclose(temp);

		remove("Phonebook.txt");
		rename("temporary.txt", "Phonebook.txt");
	}
}

// update function allows user to update a number in phonebook
// we ask the user to enter a numbe they want to update
// if this number is in the file, we print every line but this line into a new text file and make this file the "new" phonebook
// we then reopen the phonebook file and ask the user to re-enter the First, Last and number as a new entry into the phonebook
void update()
{

    FILE *Ph;
    FILE *temp;
    Ph = fopen("Phonebook.txt", "r"); // open phonebook for reading
    temp = fopen("temporary.txt", "w"); // open a temp text file for writing
    char num[20];
    printf("\nWhat number would you like to update?\n");
    scanf("%s", num);

	char linez[300];
    char *qptr1;
    char *qptr2;
    char *qptr3;
    int x = 0;
    bool tobreak = false;
	while(fgets(linez, sizeof linez, Ph) != NULL)
    {
    	char *qptr = strtok(linez, " \n");
    	qptr1 = qptr;
    	qptr = strtok(NULL, " \n");
    	qptr2 = qptr;
    	qptr = strtok(NULL, " \n");
    	qptr3 = qptr;

    	while(qptr != NULL)
    	{
        	if(strcmp(qptr3, num) == 0)
        	{
   		 		x = 1; // set flag to 1 to indicate number was found
   		 		tobreak = true; // set boolean variable to true to break out of while loops
   		 		break;
        	}
        	qptr = strtok(NULL, " \n");
    	}
    	if(tobreak)
        	break;
    }
    if(x == 0) // if flag variable == 0 the number wasn't found
    	printf("Number not found!\n");
   
    else if(x == 1) // number was found in phonebook, can start update process
    {
		rewind(Ph); // reset file pointer back to beginning of file
	    char line[300];
	    char *ptr1;
	    char *ptr2;
	    char *ptr3;
	    while(fgets(line, sizeof line, Ph)!=NULL)
	    {
			char *ptr = strtok(line, " \n"); // token delimiters are spaces and newline characters
			ptr1 = ptr; // first name token
			ptr = strtok(NULL, " \n");
			ptr2 = ptr; // last name token
			ptr = strtok(NULL, " \n");
			ptr3 = ptr; // phone num token

			while(ptr != NULL)
			{
		  	   if(strcmp(ptr3, num) != 0) // print every line but the one that needs updated into the temp file
		   		 fprintf(temp, "%-12s %-12s %-12s\n", ptr1, ptr2, ptr3);

		  	   ptr = strtok(NULL, " \n");
			}
		}

		rewind(Ph); // reset file pointer back to beginning of file
	    char *fptr1;
	    char *fptr2;
	    char *fptr3;
	    char *first;
	    char *last;
		bool broken = false;

		while(fgets(line, sizeof(line), Ph) != NULL)
		{
		  	 char *fptr = strtok(line, " \n"); // token delimiters are spaces and newlines
		   	 fptr1 = fptr; // first name token
		   	 fptr = strtok(NULL, " \n");
		   	 fptr2 = fptr; // last name token
		   	 fptr = strtok(NULL, " \n");
		   	 fptr3 = fptr; // phone num token

		   	 while(fptr != NULL)
		   	 {

		   		 if(strcmp(fptr3, num) == 0) 
		   		 {
		       		 first = fptr1; // set its first and last name tokens to variable "first" and "last"
		       		 last = fptr2;
		       		 broken = true; // set boolean variable to true to break out of loop
		       		 break;
		   		 }
		   		 fptr = strtok(NULL, " \n"); // next line
		   		 if(broken)
		       		 break;
		   	 }
		   	 if(broken)
		   		 break;
		}

	    fclose(Ph); // close the files
	    fclose(temp);

	    remove("Phonebook.txt");
	    rename("temporary.txt", "Phonebook.txt");

	    char newnum[20];
	    Ph = fopen("Phonebook.txt", "a+"); // reopen phonebook file for appending (which will add the number to the end of the file)
	    printf("Enter the new number: ");
	    scanf("%s", newnum);
        while (strlen(newnum) !=10)
    {
    	printf("Please Enter Valid 10-digit Phone Number: "); // checks that the phone number is a 10 length number 
    	scanf("%s", newnum);
    }

	    char line3[1000];
	    char *aptr1;
	    char *aptr2;
	    char *aptr3;
	    while(fgets(line3, sizeof(line3), Ph)!=NULL)
	    {
			char *aptr = strtok(line3, " \n"); // token delimiters are spaces and newline characters
			aptr1 = aptr; // first name token
			aptr = strtok(NULL, " \n");
			aptr2 = aptr; // last name token
			aptr = strtok(NULL, " \n");
			aptr3 = aptr; // number token

			while(aptr != NULL)
			{
			  	  while(strcmp(aptr3, newnum) == 0)
			  	  {
				  	  printf("Number already in phonebook!\n"); // the number they entered is already in phonebook
				  	  printf("Enter new number: ");
				  	  scanf("%s", newnum);
			  	  }
			  	  aptr = strtok(NULL, " \n"); // go to next line and repeat process
			}
		}
	printf("The new number for %s %s is %s\n", first, last, newnum);
	fprintf(Ph, "%-12s %-12s %-12s\n", first, last, newnum); // add the new number into the phonebook by appending it to the end of the phonebook
	fclose(Ph); // close the file
	}
}
