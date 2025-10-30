class Book:
    def __init__(self, title, author, year):
        self.title = title
        self.author = author
        self.year = year
        self.borrowed = False

class Library:
    def __init__(self):
        self.books = []

    def add_book(self, title, author, year):
        new_book = Book(title, author, year)
        self.books.append(new_book)

    def remove_book(self, title):
        for book in self.books:
            if book.title == title:
                self.books.remove(book)
                return
        print("Book not found!")

    def borrow_book(self, title):
        for book in self.books:
            if book.title == title:
                if book.borrowed:
                    print("Book is already borrowed!")
                else:
                    book.borrowed = True
                    return
        print("Book not found!")

    def return_book(self, title):
        for book in self.books:
            if book.title == title:
                if not book.borrowed:
                    print("Book is not borrowed!")
                else:
                    book.borrowed = False
                    return
        print("Book not found!")

    def list_books(self):
        for book in self.books:
            print(f"{book.title} by {book.author} ({book.year}) - {'Borrowed' if book.borrowed else 'Available'}")

# Example usage:
library = Library()
library.add_book("To Kill a Mockingbird", "Harper Lee", 1960)
library.add_book("1984", "George Orwell", 1949)
library.list_books()
library.borrow_book("To Kill a Mockingbird")
library.list_books()
library.return_book("To Kill a Mockingbird")
library.list_books()
