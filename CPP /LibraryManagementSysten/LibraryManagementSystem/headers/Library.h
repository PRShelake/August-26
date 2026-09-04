#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Member.h"
#include "Transaction.h"
#include "Container.h"
#include "LibraryException.h"

#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <ctime>

namespace LibrarySystem
{

class Library
{
private:
    Container<Book> books;
    Container<Member> members;

    std::vector<Transaction> transactions;

    std::map<int, int> issuedBooks;

public:

    Library()
    {
    }

    void addBook(const Book& book)
    {
        if (books.find(book.getId()) != nullptr)
        {
            std::cout << "Book already exists.\n";
            return;
        }

        books.add(book);

        std::cout << "Book added successfully.\n";
    }

    void removeBook(int bookId)
    {
        Book* book = books.find(bookId);

        if (book == nullptr)
        {
            throw BookNotFoundException(
                "Book not found",
                __FUNCTION__,
                __LINE__);
        }

        if (issuedBooks.find(bookId) != issuedBooks.end())
        {
            throw BookNotAvailableException(
                "Book is currently issued",
                __FUNCTION__,
                __LINE__);
        }

        books.removeById(bookId);

        std::cout << "Book removed successfully.\n";
    }

    void searchBook(int bookId)
    {
        Book* book = books.find(bookId);

        if (book == nullptr)
        {
            throw BookNotFoundException(
                "Book not found",
                __FUNCTION__,
                __LINE__);
        }

        std::cout << "\nBook found:\n";
        std::cout << *book << "\n";
    }

    void searchBook(const std::string& title)
    {
        for (int i = 0; i < books.getSize(); i++)
        {
            if (books[i].getTitle() == title)
            {
                std::cout << books[i] << "\n";
                return;
            }
        }

        throw BookNotFoundException(
            "Book not found",
            __FUNCTION__,
            __LINE__);
    }

    void displayBooks()
    {
        if (books.getSize() == 0)
        {
            std::cout << "No books available.\n";
            return;
        }

        std::cout << "\n========== ALL BOOKS ==========\n";

        for (int i = 0; i < books.getSize(); i++)
        {
            std::cout << books[i] << "\n";
        }
    }

    void registerMember(const Member& member)
    {
        if (members.find(member.getId()) != nullptr)
        {
            std::cout << "Member already exists.\n";
            return;
        }

        members.add(member);

        std::cout << "Member registered successfully.\n";
    }

    void removeMember(int memberId)
    {
        Member* member = members.find(memberId);

        if (member == nullptr)
        {
            throw MemberNotFoundException(
                "Member not found",
                __FUNCTION__,
                __LINE__);
        }

        if (member->getIssuedCount() > 0)
        {
            std::cout << "Member has issued books.\n";
            return;
        }

        members.removeById(memberId);

        std::cout << "Member removed successfully.\n";
    }

    void searchMember(int memberId)
    {
        Member* member = members.find(memberId);

        if (member == nullptr)
        {
            throw MemberNotFoundException(
                "Member not found",
                __FUNCTION__,
                __LINE__);
        }

        member->displayInfo();
    }

    void searchMember(const std::string& name)
    {
        Member* member = members.find(name);

        if (member == nullptr)
        {
            throw MemberNotFoundException(
                "Member not found",
                __FUNCTION__,
                __LINE__);
        }

        member->displayInfo();
    }

    void displayMembers()
    {
        if (members.getSize() == 0)
        {
            std::cout << "No members registered.\n";
            return;
        }

        std::cout << "\n========== ALL MEMBERS ==========\n";

        members.displayAll();
    }

    std::string getCurrentDate()
    {
        time_t now = time(nullptr);
        tm* local = localtime(&now);

        char buffer[11];

        strftime(buffer, sizeof(buffer),
                 "%Y-%m-%d", local);

        return std::string(buffer);
    }

    std::string getDueDate(int days)
    {
        time_t now = time(nullptr);

        now += days * 24 * 60 * 60;

        tm* future = localtime(&now);

        char buffer[11];

        strftime(buffer, sizeof(buffer),
                 "%Y-%m-%d", future);

        return std::string(buffer);
    }

    void issueBook(int memberId, int bookId)
    {
        Member* member = members.find(memberId);

        if (member == nullptr)
        {
            throw MemberNotFoundException(
                "Member not found",
                __FUNCTION__,
                __LINE__);
        }

        Book* book = books.find(bookId);

        if (book == nullptr)
        {
            throw BookNotFoundException(
                "Book not found",
                __FUNCTION__,
                __LINE__);
        }

        if (book->getAvailableCopies() <= 0)
        {
            throw BookNotAvailableException(
                "Book is not available",
                __FUNCTION__,
                __LINE__);
        }

        member->addBook(bookId);

        book->issueCopy();

        int transactionMember = memberId;
        int transactionBook = bookId;

        Transaction transaction(
            transactionMember,
            transactionBook,
            getCurrentDate(),
            getDueDate(14));

        transactions.push_back(transaction);

        issuedBooks[bookId] = memberId;

        std::cout << "\nBook issued successfully.\n";
        std::cout << "Due Date: "
                  << transaction.getDueDate()
                  << "\n";
    }

    void returnBook(int memberId, int bookId)
    {
        Member* member = members.find(memberId);

        if (member == nullptr)
        {
            throw MemberNotFoundException(
                "Member not found",
                __FUNCTION__,
                __LINE__);
        }

        Book* book = books.find(bookId);

        if (book == nullptr)
        {
            throw BookNotFoundException(
                "Book not found",
                __FUNCTION__,
                __LINE__);
        }

        auto it = issuedBooks.find(bookId);

        if (it == issuedBooks.end())
        {
            std::cout << "This book is not issued.\n";
            return;
        }

        if (it->second != memberId)
        {
            std::cout << "This book was not issued to this member.\n";
            return;
        }

        member->removeBook(bookId);

        book->returnCopy();

        issuedBooks.erase(it);

        for (int i = transactions.size() - 1;
             i >= 0;
             i--)
        {
            if (transactions[i].getBookId() == bookId &&
                transactions[i].getMemberId() == memberId &&
                transactions[i].getReturnDate().empty())
            {
                transactions[i].setReturnDate(
                    getCurrentDate());

                transactions[i].calculateFine();

                std::cout << "\nBook returned successfully.\n";
                std::cout << "Fine: ₹"
                          << transactions[i].getFineAmount()
                          << "\n";

                break;
            }
        }
    }

    void viewOverdueBooks()
    {
        std::string today = getCurrentDate();

        bool found = false;

        std::cout << "\n========== OVERDUE BOOKS ==========\n";

        for (auto& transaction : transactions)
        {
            if (transaction.getReturnDate().empty() &&
                transaction.getDueDate() < today)
            {
                transaction.display();
                found = true;
            }
        }

        if (!found)
        {
            std::cout << "No overdue books.\n";
        }
    }

    void saveData()
    {
        std::ofstream bookFile(
            "data/books.txt");

        for (int i = 0; i < books.getSize(); i++)
        {
            Book& b = books[i];

            bookFile << b.getId() << "|"
                     << b.getTitle() << "|"
                     << b.getAuthor() << "|"
                     << b.getISBN() << "|"
                     << b.statusString() << "|"
                     << b.getQuantity() << "|"
                     << b.getAvailableCopies()
                     << "\n";
        }

        bookFile.close();

        std::ofstream memberFile(
            "data/members.txt");

        for (int i = 0; i < members.getSize(); i++)
        {
            Member& m = members[i];

            memberFile << m.getId() << "|"
                       << m.getName() << "|"
                       << m.getPhone() << "|"
                       << m.getIssuedCount();

            for (int j = 0;
                 j < m.getIssuedCount();
                 j++)
            {
                memberFile << "|"
                           << m.getIssuedBook(j);
            }

            memberFile << "\n";
        }

        memberFile.close();

        std::ofstream transactionFile(
            "data/transactions.txt");

        for (auto& t : transactions)
        {
            transactionFile
                << t.getTransactionId() << "|"
                << t.getMemberId() << "|"
                << t.getBookId() << "|"
                << t.getIssueDate() << "|"
                << t.getDueDate() << "|"
                << t.getReturnDate() << "|"
                << t.getFineAmount()
                << "\n";
        }

        transactionFile.close();

        std::ofstream issuedFile(
            "data/issued.txt");

        for (auto& pair : issuedBooks)
        {
            issuedFile << pair.first
                       << "|"
                       << pair.second
                       << "\n";
        }

        issuedFile.close();

        std::cout << "Data saved successfully.\n";
    }

    void loadData()
    {
        books = Container<Book>();
        members = Container<Member>();

        transactions.clear();
        issuedBooks.clear();

        // Load books
        std::ifstream bookFile(
            "data/books.txt");

        std::string line;

        while (getline(bookFile, line))
        {
            if (line.empty())
                continue;

            std::stringstream ss(line);

            std::string id;
            std::string title;
            std::string author;
            std::string isbn;
            std::string status;
            std::string quantity;
            std::string available;

            getline(ss, id, '|');
            getline(ss, title, '|');
            getline(ss, author, '|');
            getline(ss, isbn, '|');
            getline(ss, status, '|');
            getline(ss, quantity, '|');
            getline(ss, available, '|');

            Book book(
                std::stoi(id),
                title,
                author,
                isbn,
                std::stoi(quantity));

            int availableCopies =
                std::stoi(available);

            while (book.getAvailableCopies()
                   > availableCopies)
            {
                book.issueCopy();
            }

            while (book.getAvailableCopies()
                   < availableCopies)
            {
                book.returnCopy();
            }

            books.add(book);
        }

        bookFile.close();

        // Load members
        std::ifstream memberFile(
            "data/members.txt");

        while (getline(memberFile, line))
        {
            if (line.empty())
                continue;

            std::stringstream ss(line);

            std::string id;
            std::string name;
            std::string phone;
            std::string count;

            getline(ss, id, '|');
            getline(ss, name, '|');
            getline(ss, phone, '|');
            getline(ss, count, '|');

            Member member(
                std::stoi(id),
                name,
                phone);

            int bookCount = std::stoi(count);

            for (int i = 0;
                 i < bookCount;
                 i++)
            {
                std::string bookId;

                getline(ss, bookId, '|');

                member.addBook(
                    std::stoi(bookId));
            }

            members.add(member);
        }

        memberFile.close();

        // Load issued map
        std::ifstream issuedFile(
            "data/issued.txt");

        while (getline(issuedFile, line))
        {
            if (line.empty())
                continue;

            std::stringstream ss(line);

            std::string bookId;
            std::string memberId;

            getline(ss, bookId, '|');
            getline(ss, memberId, '|');

            issuedBooks[
                std::stoi(bookId)
            ] = std::stoi(memberId);
        }

        issuedFile.close();

        std::cout << "Data loaded successfully.\n";
    }
};

}

#endif
