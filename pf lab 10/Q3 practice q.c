#include <stdio.h>
#include <string.h>
struct Book {
    char title[100];
    char author[100];
    char isbn[20];
    int publicationYear;
    int isAvailable; 
};
void addBook(struct Book* library, int* bookCount) {
    printf("Enter book title: ");
    fgets(library[*bookCount].title, sizeof(library[*bookCount].title), stdin);
    library[*bookCount].title[strcspn(library[*bookCount].title, "\n")] = 0; 
    printf("Enter author name: ");
    fgets(library[*bookCount].author, sizeof(library[*bookCount].author), stdin);
    library[*bookCount].author[strcspn(library[*bookCount].author, "\n")] = 0; 
    printf("Enter ISBN: ");
    fgets(library[*bookCount].isbn, sizeof(library[*bookCount].isbn), stdin);
    library[*bookCount].isbn[strcspn(library[*bookCount].isbn, "\n")] = 0; 
    printf("Enter publication year: ");
    scanf("%d", &library[*bookCount].publicationYear);
    getchar(); 
    library[*bookCount].isAvailable = 1;
    (*bookCount)++;

    printf("Book added successfully!\n\n");
}

void searchBook(struct Book* library, int bookCount, const char* searchTerm) {
    int found = 0;
    printf("Searching for books matching '%s'...\n", searchTerm);

    for (int i = 0; i < bookCount; i++) {
        if (strstr(library[i].title, searchTerm) != NULL || strstr(library[i].author, searchTerm) != NULL) {
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("ISBN: %s\n", library[i].isbn);
            printf("Publication Year: %d\n", library[i].publicationYear);
            printf("Availability: %s\n\n", library[i].isAvailable ? "Available" : "Checked Out");
            found = 1;
        }
    }

    if (!found) {
        printf("No books found matching the search term.\n\n");
    }
}
void updateAvailability(struct Book* library, int bookCount, const char* isbn, int availability) {
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].isbn, isbn) == 0) {
            library[i].isAvailable = availability;
            printf("Book '%s' has been %s.\n\n", library[i].title, availability ? "returned" : "checked out");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No book found with ISBN: %s\n\n", isbn);
    }
}

int main() {
    struct Book library[100]; 
    int bookCount = 0; 
    int choice;
    while (1) {
        printf("Library Menu:\n");
        printf("1. Add a new book\n");
        printf("2. Search for a book by title or author\n");
        printf("3. Update availability status (check out/return)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2: {
                char searchTerm[100];
                printf("Enter title or author to search for: ");
                fgets(searchTerm, sizeof(searchTerm), stdin);
                searchTerm[strcspn(searchTerm, "\n")] = 0;
                searchBook(library, bookCount, searchTerm);
                break;
            }
            case 3: {
                char isbn[20];
                int availability;
                printf("Enter the ISBN of the book: ");
                fgets(isbn, sizeof(isbn), stdin);
                isbn[strcspn(isbn, "\n")] = 0; // Remove newline
                printf("Enter availability (1 for return, 0 for checkout): ");
                scanf("%d", &availability);
                getchar(); 
                updateAvailability(library, bookCount, isbn, availability);
                break;
            }
            case 4:
                printf("Exiting the library system.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }

    return 0;
}
