#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>
#include <ctime>

namespace LibrarySystem
{

class Transaction
{
private:
    int transactionId;
    int memberId;
    int bookId;

    std::string issueDate;
    std::string dueDate;
    std::string returnDate;

    double fineAmount;

    static int nextTransactionId;

    static const double FINE_RATE_PER_DAY;

public:

    Transaction()
    {
        transactionId = nextTransactionId++;
        memberId = 0;
        bookId = 0;

        issueDate = "";
        dueDate = "";
        returnDate = "";

        fineAmount = 0;
    }

    Transaction(int memberId,
                int bookId,
                std::string issueDate,
                std::string dueDate)
    {
        transactionId = nextTransactionId++;

        this->memberId = memberId;
        this->bookId = bookId;

        this->issueDate = issueDate;
        this->dueDate = dueDate;

        returnDate = "";
        fineAmount = 0;
    }

    int getTransactionId() const
    {
        return transactionId;
    }

    int getMemberId() const
    {
        return memberId;
    }

    int getBookId() const
    {
        return bookId;
    }

    std::string getIssueDate() const
    {
        return issueDate;
    }

    std::string getDueDate() const
    {
        return dueDate;
    }

    std::string getReturnDate() const
    {
        return returnDate;
    }

    double getFineAmount() const
    {
        return fineAmount;
    }

    void setReturnDate(const std::string& date)
    {
        returnDate = date;
    }

    void calculateFine()
    {
        if (returnDate.empty())
            return;

        std::tm due = {};
        std::tm returned = {};

        int y, m, d;

        sscanf(dueDate.c_str(), "%d-%d-%d", &y, &m, &d);

        due.tm_year = y - 1900;
        due.tm_mon = m - 1;
        due.tm_mday = d;

        sscanf(returnDate.c_str(), "%d-%d-%d", &y, &m, &d);

        returned.tm_year = y - 1900;
        returned.tm_mon = m - 1;
        returned.tm_mday = d;

        time_t dueTime = mktime(&due);
        time_t returnTime = mktime(&returned);

        double seconds = difftime(returnTime, dueTime);

        int daysLate = static_cast<int>(seconds / (60 * 60 * 24));

        if (daysLate > 0)
            fineAmount = daysLate * FINE_RATE_PER_DAY;
        else
            fineAmount = 0;
    }

    void display() const
    {
        std::cout << "\nTransaction ID : " << transactionId;
        std::cout << "\nMember ID      : " << memberId;
        std::cout << "\nBook ID        : " << bookId;
        std::cout << "\nIssue Date     : " << issueDate;
        std::cout << "\nDue Date       : " << dueDate;
        std::cout << "\nReturn Date    : " << returnDate;
        std::cout << "\nFine           : " << fineAmount;
        std::cout << "\n";
    }

    // Used while loading from file
    static void setNextId(int id)
    {
        nextTransactionId = id;
    }
};

}

#endif
