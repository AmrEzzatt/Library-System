#include <iostream>
#include <limits>
#include <string>
using namespace std;

const int MAX_BOOKS = 10; // Maximum number of books the library can hold

// Arrays to store book information
int BookId[MAX_BOOKS];
string BookTitle[MAX_BOOKS];
string BookAuthor[MAX_BOOKS];
bool bookAvailability[MAX_BOOKS];
int bookCount = 0; // Current number of books in the library

// Function to add a new book to the library
void AddNewBook()
{
    int bookid;
    string bookname, bookauthor;
    if (bookCount < MAX_BOOKS)
    {
        cout << "Enter Book ID : ";
        while (!(cin >> bookid)) // Validate input to ensure it's an integer
        {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a valid integer for Book ID : ";
        }
        cin.ignore(); // Ignore leftover newline character
        cout << "Enter Book Name : ";
        getline(cin, bookname); // Use getline to read the entire line
        cout << "Enter Book Author : ";
        getline(cin, bookauthor); // Use getline to read the entire line
        // Add book details to the arrays
        BookId[bookCount] = bookid;
        BookTitle[bookCount] = bookname;
        BookAuthor[bookCount] = bookauthor;
        bookAvailability[bookCount] = true; // Mark the book as available
        bookCount++; // Increment the book count
        cout << "Book is Added successfully.\n";
    }
    else
    {
        cout << "Sorry, the library is full\n";
    }
}

// Function to search for a book by ID
void SearchForBook()
{
    cout << "Enter book ID you want to search for please: ";
    int bookid;
    cin >> bookid;
    for (int i = 0; i < bookCount; ++i)
    {
        if (BookId[i] == bookid)
        {
            cout << "ID: " << BookId[i] << ", Title: " << BookTitle[i] << ", Author: " << BookAuthor[i] << ", Available: " << (bookAvailability[i] ? "Yes" : "No") << endl;
            return;
        }
    }
    cout << "Book not found.\n";
}

// Function to update a book in the library
void UpdateBook()
{
    int bookid;
    string bookname, bookauthor;
    cout << "Enter book ID you want to update please: ";
    cin >> bookid;

    // Loop through the list of books to find the book with the matching ID
    for (int i = 0; i < bookCount; ++i)
    {
        if (BookId[i] == bookid)
        {
            // Prompt for new book details
            cout << "Enter new Book ID: ";
            while (!(cin >> bookid)) // Validate input to ensure it's an integer
            {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Invalid input. Please enter a valid integer for Book ID : ";
            }
            cin.ignore(); // Ignore leftover newline character
            cout << "Enter new Book Name: ";
            getline(cin, bookname); // Use getline to read the entire line
            cout << "Enter new Book Author: ";
            getline(cin, bookauthor); // Use getline to read the entire line

            // Update book details in the arrays
            BookId[i] = bookid;
            BookTitle[i] = bookname;
            BookAuthor[i] = bookauthor;
            bookAvailability[i] = true; // Mark the book as available
            cout << "Book is updated successfully.\n";
            return; // Exit the function after updating the book
        }
    }
    // If the book ID is not found, print a message
    cout << "Book not found.\n";
}

// Function to remove a book by ID
void RemoveBook()
{
    cout << "Enter book ID you want to remove please: ";
    int bookid;
    cin >> bookid;
    for (int i = 0; i < bookCount; ++i)
    {
        if (BookId[i] == bookid)
        {
            for (int j = i; j < bookCount - 1; ++j)
            {
                BookId[j] = BookId[j + 1];
                BookTitle[j] = BookTitle[j + 1];
                BookAuthor[j] = BookAuthor[j + 1];
                bookAvailability[j] = bookAvailability[j + 1];
            }
            bookCount--; // Decrement the book count
            cout << "Book is removed successfully.\n";
            return; // Exit the function after removing the book
        }
    }
    cout << "Book not found.\n";
}

// Function to borrow a book by ID
void BorrowBook()
{
    cout << "Enter book ID you want to borrow please: ";
    int bookid;
    cin >> bookid;

    // Loop through the list of books to find the book with the matching ID
    for (int i = 0; i < bookCount; ++i)
    {
        if (BookId[i] == bookid)
        {
            // Check if the book is available
            if (bookAvailability[i])
            {
                bookAvailability[i] = false; // Mark the book as borrowed
                cout << "Book is borrowed successfully.\n";
            }
            else
            {
                cout << "Book is unavailable.\n";
            }
            return; // Exit the function after processing the book
        }
    }
    // If the book ID is not found, print a message
    cout << "Book not found.\n";
}

// Function to return a book by ID
void ReturnBook()
{
    cout << "Enter book ID you want to return please: ";
    int bookid;
    cin >> bookid;

    // Loop through the list of books to find the book with the matching ID
    for (int i = 0; i < bookCount; ++i)
    {
        if (BookId[i] == bookid)
        {
            // Check if the book is currently borrowed (unavailable)
            if (!bookAvailability[i])
            {
                bookAvailability[i] = true; // Mark the book as available
                cout << "Book is returned successfully.\n";
            }
            else
            {
                cout << "Book is already available.\n";
            }
            return; // Exit the function after processing the book
        }
    }
    // If the book ID is not found, print a message
    cout << "Book not found.\n";
}

// Function to print all books
void DisplayBooks()
{
    for (int i = 0; i < bookCount; ++i)
    {
        cout << "ID: " << BookId[i] << ", Title: " << BookTitle[i] << ", Author: " << BookAuthor[i] << ", Available: " << (bookAvailability[i] ? "Yes" : "No") << endl;
    }
}


int main()
{
    while (true)
    {
        int choice;
        char choice2;

        cout << "====================================\n";
        cout << "Please select the feature you want: \n1- To Add a book \n2- To Search for a book \n3- To Remove a book \n4- To Update a book \n5- To Borrow a book \n6- To Return a book \n7- To Display all books" << endl;
        cout << "====================================\n";
            while (!(cin >> choice)) // Validate input to ensure it's an integer
            {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Invalid input. Please enter a valid integer  : ";
            }

        switch (choice)
        {
            case 1:
                AddNewBook();
                break;
            case 2:
                SearchForBook();
                break;
            case 3:
                RemoveBook();
                break;
            case 4:
                UpdateBook();
                break;
            case 5:
                BorrowBook();
                break;
            case 6:
                ReturnBook();
                break;
            case 7:
                DisplayBooks();
                break;
            default:
                cout << "Sorry, invalid choice." << endl;
        }

        while (true)
        {
            cout << "\nIf you want to select any feature again, press 'y' and 'n' to exit\n";
            cin >> choice2;
            choice2 = tolower(choice2);
            if (choice2 == 'y')
            {
                break;
            }
            else if (choice2 == 'n')
            {
                return 0; // Exit the program
            }
            else
            {
                cout << "Invalid input. Please enter 'y' or 'n'.\n";
            }
        }
    }


    return 0;
}



























