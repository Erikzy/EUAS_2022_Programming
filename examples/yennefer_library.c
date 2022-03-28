#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Book{
    char  title[50];
    char  author[50];
    char  description[200];
    int year;
} book_t;

book_t * books[100];
int books_stored = 0;
int running = 1;

void print_menu();
void get_user_choice();
void print_the_library();
void start_add_prompt();
void store_book(book_t * book);

int main(){
    //present the user with a menu with 2 options
    // b) list all books
    while (running > 0)
    {
           print_menu();
           get_user_choice();
    }
  
}

void print_menu(){
    printf("\nHello!  Please select eiter (a)dd or (l)list or (q)uit !");
}

void get_user_choice(){
    char choice;
    scanf(" %c", &choice);
    if(choice == 'a'){
      start_add_prompt();  
    }else if(choice == 'l'){
      print_the_library();
    }else if(choice == 'q'){
        running = 0;
    }
}

void start_add_prompt(){
    char  input[50];
    int year = 0;
    book_t * book = malloc(sizeof(book_t));
    
    printf("Please enter the title: ");
    scanf(" %s", (char *)&input);
    strcpy(book->title, input);

    printf("Please enter the author: ");
    scanf(" %s", (char *)&input);
    strcpy(book->author, input);

    printf("Please enter the description: ");
    scanf(" %s", (char *)&input);
    strcpy(book->description, input);

    printf("Please enter the year: ");
    scanf(" %d", &year);
    book->year = year;

    store_book(book);
}

void store_book(book_t * ptr){
    books[books_stored] = ptr;
    books_stored++;
}

void print_the_library(){
    for(int i = 0; i < books_stored; i++){
        printf("\n%d) %s by %s released on %d",
         i,
         books[i]->title,
         books[i]->author,
         books[i]->year
        );        
    }
}