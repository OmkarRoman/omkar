#include <iostream>
#include <string>
#include <vector>

class Book {
public:
    std::string title;
    std::string author;
    int year;
    bool borrowed;
    std::string publisher;
    std::string genre;
    std::string summary;

    Book(std::string title, std::string author, int year, std::string publisher, std::string genre, std::string summary)
        : title(title), author(author), year(year), publisher(publisher), genre(genre), summary(summary), borrowed(false) {}
};

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(std::string title, std::string author, int year, std::string publisher, std::string genre, std::string summary) {
        Book newBook(title, author, year, publisher, genre, summary);
        books.push_back(newBook);
    }

    void removeBook(std::string title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->title == title) {
                books.erase(it);
                return;
            }
        }
        std::cout << "Book not found!" << std::endl;
    }

    void borrowBook(std::string title) {
        for (auto &book : books) {
            if (book.title == title) {
                if (book.borrowed) {
                    std::cout << "Book is already borrowed!" << std::endl;
                } else {
                    book.borrowed = true;
                    return;
                }
            }
        }
        std::cout << "Book not found!" << std::endl;
    }

    void returnBook(std::string title) {
        for (auto &book : books) {
            if (book.title == title) {
                if (!book.borrowed) {
                    std::cout << "Book is not borrowed!" << std::endl;
                } else {
                    book.borrowed = false;
                    return;
                }
            }
        }
        std::cout << "Book not found!" << std::endl;
    }

    void listBooks() {
        for (const auto &book : books) {
            std::cout << book.title << " by " << book.author << " (" << book.year << ") - " << (book.borrowed ? "Borrowed" : "Available") << std::endl;
        }
    }
};

int main() {
    Library library;
    library.addBook("To Kill a Mockingbird", "Harper Lee", 1960, "J.B. Lippincott & Co.", "Fiction", "A classic novel about racial injustice in the Deep South.");
    library.addBook("1984", "George Orwell", 1949, "Secker and Warburg", "Dystopian", "A dystopian novel depicting a totalitarian future society.");
    library.addBook("Pride and Prejudice", "Jane Austen", 1813, "T. Egerton", "Romance", "A romantic novel about Elizabeth Bennet and Mr. Darcy's complicated relationship.");

    library.listBooks();

    library.borrowBook("To Kill a Mockingbird");
    library.listBooks();

    library.returnBook("To Kill a Mockingbird");
    library.listBooks();

    return 0;
}
