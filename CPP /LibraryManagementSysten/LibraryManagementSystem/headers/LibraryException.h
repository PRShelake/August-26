#ifndef LIBRARYEXCEPTION_H
#define LIBRARYEXCEPTION_H

#include <exception>
#include <string>

namespace LibrarySystem
{

class LibraryException : public std::exception
{
protected:
    std::string message;

public:
    LibraryException(const std::string& msg,
                     const char* functionName,
                     int line)
    {
        message = msg + " | Function: " +
                  functionName +
                  " | Line: " +
                  std::to_string(line);
    }

    const char* what() const noexcept override
    {
        return message.c_str();
    }
};

class BookNotFoundException : public LibraryException
{
public:
    BookNotFoundException(const std::string& msg,
                          const char* functionName,
                          int line)
        : LibraryException(msg, functionName, line) {}
};

class MemberNotFoundException : public LibraryException
{
public:
    MemberNotFoundException(const std::string& msg,
                            const char* functionName,
                            int line)
        : LibraryException(msg, functionName, line) {}
};

class BookNotAvailableException : public LibraryException
{
public:
    BookNotAvailableException(const std::string& msg,
                              const char* functionName,
                              int line)
        : LibraryException(msg, functionName, line) {}
};

class MaxBooksExceededException : public LibraryException
{
public:
    MaxBooksExceededException(const std::string& msg,
                              const char* functionName,
                              int line)
        : LibraryException(msg, functionName, line) {}
};

}

#endif
