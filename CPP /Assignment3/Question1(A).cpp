#include <iostream>
#include <string>
using namespace std;

// Enum class for HTTP status codes
enum class HttpStatus {
    OK = 200,
    Created = 201,
    BadRequest = 400,
    Unauthorized = 401,
    NotFound = 404,
    ServerError = 500
};

// Function to handle HTTP response
void handleResponse(HttpStatus status, const string& endpoint)
{
    cout << "[" << endpoint << "] → " << static_cast<int>(status) << " "; 

    switch (status)
    {
        case HttpStatus::OK:
            cout << "OK : Request successful";
            break;

        case HttpStatus::Created:
            cout << "Created : Resource created successfully";
            break;

        case HttpStatus::BadRequest:
            cout << "Bad Request : Invalid request";
            break;

        case HttpStatus::Unauthorized:
            cout << "Unauthorized : Authentication required";
            break;

        case HttpStatus::NotFound:
            cout << "Not Found : Endpoint does not exist";
            break;

        case HttpStatus::ServerError:
            cout << "Server Error : Internal server error - retry later";
            break;
    }

    cout << endl;
}

int main()
{
    handleResponse(HttpStatus::OK, "/api/users");
    handleResponse(HttpStatus::Unauthorized, "/api/login");
    handleResponse(HttpStatus::NotFound, "/api/products/99");
    handleResponse(HttpStatus::ServerError, "/api/order");

    return 0;
}

