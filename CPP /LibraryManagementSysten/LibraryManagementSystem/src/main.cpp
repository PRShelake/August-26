#include <iostream>

#include "../headers/Library.h"
#include "../headers/Librarian.h"

using namespace std;
using namespace LibrarySystem;

void showMenu()
{
    cout << "\n";
    cout << "=====================================\n";
    cout << "       LIBRARY MANAGEMENT SYSTEM\n";
    cout << "=====================================\n";

    cout << "1.  Add New Book\n";
    cout << "2.  Remove Book\n";
    cout << "3.  Search Book\n";
    cout << "4.  Display All Books\n";
    cout << "5.  Register Member\n";
    cout << "6.  Remove Member\n";
    cout << "7.  Search Member\n";
    cout << "8.  Display All Members\n";
    cout << "9.  Issue Book\n";
    cout << "10. Return Book\n";
    cout << "11. View Overdue Books\n";
    cout << "12. Save Data\n";
    cout << "13. Load Data\n";
    cout << "0.  Exit\n";

    cout << "=====================================\n";
    cout << "Enter choice: ";
}

int main()
{
    Library library;

    /*
       Runtime Polymorphism Demonstration
    */

    cout << "\n===== Runtime Polymorphism Test =====\n";

    Person* p1 =
        new Member(1, "Praveen", "9876543210");

    Person* p2 =
        new Librarian(
            2,
            "Admin",
            "9999999999",
            5001,
            35000);

    p1->displayInfo();
    p2->displayInfo();

    delete p1;
    delete p2;

    int choice;

    do
    {
        showMenu();
        cin >> choice;

        try
        {
            switch (choice)
            {
            case 1:
            {
                int id;
                string title;
                string author;
                string isbn;
                int quantity;

                cout << "Enter Book ID: ";
                cin >> id;

                cin.ignore();

                cout << "Enter Title: ";
                getline(cin, title);

                cout << "Enter Author: ";
                getline(cin, author);

                cout << "Enter ISBN: ";
                getline(cin, isbn);

                cout << "Enter Quantity: ";
                cin >> quantity;

                Book book(
                    id,
                    title,
                    author,
                    isbn,
                    quantity,
                    BookGenre::PROGRAMMING);

                library.addBook(book);

                break;
            }

            case 2:
            {
                int id;

                cout << "Enter Book ID: ";
                cin >> id;

                library.removeBook(id);

                break;
            }

            case 3:
            {
                int id;

                cout << "Enter Book ID: ";
                cin >> id;

                library.searchBook(id);

                break;
            }

            case 4:
            {
                library.displayBooks();

                break;
            }

            case 5:
            {
                int id;
                string name;
                string phone;

                cout << "Enter Member ID: ";
                cin >> id;

                cin.ignore();

                cout << "Enter Name: ";
                getline(cin, name);

                cout << "Enter Phone: ";
                getline(cin, phone);

                Member member(
                    id,
                    name,
                    phone);

                library.registerMember(member);

                break;
            }

            case 6:
            {
                int id;

                cout << "Enter Member ID: ";
                cin >> id;

                library.removeMember(id);

                break;
            }

            case 7:
            {
                int id;

                cout << "Enter Member ID: ";
                cin >> id;

                library.searchMember(id);

                break;
            }

            case 8:
            {
                library.displayMembers();

                break;
            }

            case 9:
            {
                int memberId;
                int bookId;

                cout << "Enter Member ID: ";
                cin >> memberId;

                cout << "Enter Book ID: ";
                cin >> bookId;

                library.issueBook(
                    memberId,
                    bookId);

                break;
            }

            case 10:
            {
                int memberId;
                int bookId;

                cout << "Enter Member ID: ";
                cin >> memberId;

                cout << "Enter Book ID: ";
                cin >> bookId;

                library.returnBook(
                    memberId,
                    bookId);

                break;
            }

            case 11:
            {
                library.viewOverdueBooks();

                break;
            }

            case 12:
            {
                library.saveData();

                break;
            }

            case 13:
            {
                library.loadData();

                break;
            }

            case 0:
            {
                cout << "Exiting program...\n";
                break;
            }

            default:
            {
                cout << "Invalid choice!\n";
            }
            }
        }

        catch (const LibraryException& e)
        {
            cout << "\nERROR: "
                 << e.what()
                 << "\n";
        }

        catch (const exception& e)
        {
            cout << "\nStandard Error: "
                 << e.what()
                 << "\n";
        }

    } while (choice != 0);

    return 0;
}
