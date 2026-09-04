#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

namespace LibrarySystem
{

enum class BookStatus
{
    AVAILABLE,
    ISSUED,
    UNAVAILABLE
};

enum class BookGenre
{
    PROGRAMMING,
    DATA_STRUCTURE,
    DATABASE,
    NETWORKING,
    OTHER
};

class Book
{
private:
    int bookId;
    std::string title;
    std::string author;
    std::string isbn;

    BookStatus status;
    BookGenre genre;

    int quantity;
    int availableCopies;

public:

    Book()
    {
        bookId = 0;
        title = "";
        author = "";
        isbn = "";

        status = BookStatus::AVAILABLE;
        genre = BookGenre::OTHER;

        quantity = 0;
        availableCopies = 0;
    }

    Book(int id,
         std::string title,
         std::string author,
         std::string isbn,
         int quantity,
         BookGenre genre = BookGenre::OTHER)
    {
        this->bookId = id;
        this->title = title;
        this->author = author;
        this->isbn = isbn;

        this->quantity = quantity;
        this->availableCopies = quantity;

        this->genre = genre;

        updateStatus();
    }

    int getId() const
    {
        return bookId;
    }

    std::string getTitle() const
    {
        return title;
    }

    std::string getAuthor() const
    {
        return author;
    }

    std::string getISBN() const
    {
        return isbn;
    }

    int getQuantity() const
    {
        return quantity;
    }

    int getAvailableCopies() const
    {
        return availableCopies;
    }

    BookStatus getStatus() const
    {
        return status;
    }

    BookGenre getGenre() const
    {
        return genre;
    }

    void setStatus(BookStatus status)
    {
        this->status = status;
    }

    void issueCopy()
    {
        if (availableCopies > 0)
        {
            availableCopies--;
            updateStatus();
        }
    }

    void returnCopy()
    {
        if (availableCopies < quantity)
        {
            availableCopies++;
            updateStatus();
        }
    }

    void updateStatus()
    {
        if (availableCopies == 0)
            status = BookStatus::ISSUED;
        else
            status = BookStatus::AVAILABLE;
    }

    std::string statusString() const
    {
        switch (status)
        {
        case BookStatus::AVAILABLE:
            return "AVAILABLE";

        case BookStatus::ISSUED:
            return "ISSUED";

        case BookStatus::UNAVAILABLE:
            return "UNAVAILABLE";
        }

        return "UNKNOWN";
    }

    std::string genreString() const
    {
        switch (genre)
        {
        case BookGenre::PROGRAMMING:
            return "PROGRAMMING";

        case BookGenre::DATA_STRUCTURE:
            return "DATA_STRUCTURE";

        case BookGenre::DATABASE:
            return "DATABASE";

        case BookGenre::NETWORKING:
            return "NETWORKING";

        default:
            return "OTHER";
        }
    }

    // Pre-increment
    Book& operator++()
    {
        quantity++;
        availableCopies++;
        updateStatus();

        return *this;
    }

    // Post-increment
    Book operator++(int)
    {
        Book temp = *this;

        quantity++;
        availableCopies++;
        updateStatus();

        return temp;
    }

    // Pre-decrement
    Book& operator--()
    {
        if (quantity > 0)
        {
            quantity--;

            if (availableCopies > quantity)
                availableCopies = quantity;
        }

        updateStatus();

        return *this;
    }

    // == operator
    bool operator==(const Book& other) const
    {
        return bookId == other.bookId;
    }

    // < operator
    bool operator<(const Book& other) const
    {
        return title < other.title;
    }

    // > operator
    bool operator>(const Book& other) const
    {
        return quantity > other.quantity;
    }

    // [] operator
    std::string operator[](int index) const
    {
        switch (index)
        {
        case 0:
            return std::to_string(bookId);

        case 1:
            return title;

        case 2:
            return author;

        case 3:
            return isbn;

        case 4:
            return statusString();

        case 5:
            return std::to_string(quantity);

        case 6:
            return std::to_string(availableCopies);

        case 7:
            return genreString();

        default:
            return "Invalid index";
        }
    }

    friend std::ostream& operator<<(std::ostream& out,
                                    const Book& book)
    {
        out << book.bookId << " | "
            << book.title << " | "
            << book.author << " | "
            << book.isbn << " | "
            << book.statusString() << " | "
            << book.quantity << " | "
            << book.availableCopies;

        return out;
    }

    friend std::istream& operator>>(std::istream& in,
                                    Book& book)
    {
        in >> book.bookId
           >> book.title
           >> book.author
           >> book.isbn
           >> book.quantity
           >> book.availableCopies;

        book.updateStatus();

        return in;
    }
};

}

#endif
