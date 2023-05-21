![logo-no-background](https://github.com/sabdulmajid/Web-Server-CPP/assets/85283195/88001578-2ee9-4e34-98f1-5ae7c04c7f0c)

# C++ WebServus
This **C++ web server** is a powerful tool that can be used to serve static files and handle **FTP**, **SMTP**, **HTTP** & **HTTPS** requests. The server supports multiple **concurrent connections** and different protocol methods & status codes. It also has an **SQLite** user database, which is used for user authentication.

Some of the key features of this web server include:

  1. **Serving static files**: The server can be used to serve static files, such as HTML, CSS, and JavaScript files. This makes it ideal for hosting simple websites and web applications.
  2. **Handling HTTP requests**: The server can handle a variety of HTTP requests, including GET, POST, PUT, and DELETE. This allows it to be used to implement a wide range of web functionality.
  3. **Supporting multiple concurrent connections**: The server can support multiple concurrent connections, which makes it ideal for handling high-traffic websites and web applications.
  4. **Supporting different HTTP methods and status codes**: The server supports a wide range of HTTP methods and status codes, which makes it compatible with a wide range of web browsers and other clients.
  5. **Supporting different protocols**: The server supports FTP, SMTP, and more recently, HTTPS as well (using SSL Encryption)
  6. **Built-in user authentication**: The server uses an SQLite database to store user credentials, making it secure and safe to use.

In addition to these key features, the server also includes a number of other features that make it very powerful and adaptable:

  * **Error handling**: The server includes comprehensive error handling that ensures that errors are handled gracefully and that users are presented with informative error messages.
  * **Logging**: The server includes comprehensive logging that allows you to track the activity of the server and to troubleshoot any problems that may occur.
  * **Configuration**: The server is highly configurable, which allows you to customize the behavior of the server to meet your specific needs.

Overall, this advanced C++ web server is a powerful and versatile tool that can be used to serve static files and handle HTTP requests. The server supports multiple concurrent connections and different HTTP methods and status codes, which makes it a reliable solution for a wide range of web development needs.

## Features
  - Serves static files
  - Handles HTTP requests
  - Supports multiple concurrent connections
  - Supports different HTTP methods and status codes
  - Supports FTP, SMTP & HTTPS
  - Supports user authentication
  - Has built-in logging

## Authentication
  This is an explanation for how the web server uses an SQLite database to provide secure access. The ```User``` class represents a user in the application. It has three properties: ```username```, ```password```, and ```twoFactorCode```. The login function checks the user credentials against the database. If the user is found in the database and the passwords match, the function returns ```true```. Otherwise, the function returns ```false```.

The main function creates a database, creates a ```User``` object, and calls the login function. If the user is authenticated, the main function prints a welcome message and the user is given access to the server. Otherwise, the main function prints an error message and the user is denied access to the server.

As for the nitty-gritty details:

  - The **sqlite3** library is used to access the database.
  - The **sqlite3_prepare** function prepares a SQL statement for execution.
  - The **sqlite3_bind_text** function binds a string to a parameter in a SQL statement.
  - The **sqlite3_step** function executes a SQL statement and returns the results.
  - The **sqlite3_column_text** function returns the text value of a column in a result set.

Here is the code for my authentication method:
```js
   sqlite3 *db;
   int rc = sqlite3_open("database.db", &db);
   if (rc != SQLITE_OK) {
       cout << "Error opening database: " << sqlite3_errmsg(db) << endl;
   }

   User user;
   user.username = "username";
   user.password = "password";
   user.twoFactorCode = "twoFactorCode";

   bool isAuthenticated = login(user.username, user.password, user.twoFactorCode);
   if (!isAuthenticated) {
       cout << "Invalid username or password" << endl;
   }

   cout << "Welcome to the application, " << user.username << "!" << endl;

   sqlite3_close(db);

   if (isAuthenticated) {
       cout << "You are now authenticated and have access to the web server." << endl;
   } else {
       cout << "You are not authenticated and do not have access to the web server." << endl;
   }
```

## Logging
  I decided to add logging to the server to help debug any issues I ran into when trying to set up the server. Some other benefits of logging include reduced downtime, increased productivity and eventually, reduced costs. Here is the code snippet for my logging method:
```js
void log(string message) {
  ofstream logfile("log.txt");
  logfile << message << endl;
  logfile.close();
}

```

## Example code & uses

```js
std::cout << "HTTP request received" << std::endl;
std::string response_body = "<html><body><h1>Hello, welcome to this server!</h1></body></html>";
std::string response =
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html\r\n"
    "Content-Length: " + std::to_string(response_body.size()) + "\r\n"
    "\r\n" + response_body;
num_bytes = write(next_connection, response.c_str(), response.size());
```
  - **Hosting a personal website**: This web server can be used to host a personal website. You can use it to share your thoughts, photos, and videos with the world.
  - **Creating a web application**: This web server can be used to create a web application. You can use it to build a variety of applications, such as a blog, a forum, or an online store.
  - **Running a test server**: This web server can be used to run a test server. You can use it to test your web applications before you deploy them to a production server.
  - **Providing file sharing**: This web server can be used to provide file sharing. You can use it to share files with friends, family, or colleagues.
  - **Hosting a game server**: This web server can be used to host a game server. You can use it to host multiplayer games, such as Minecraft or Counter-Strike.
  
## Requirements
  - C++ compiler
  - GNU Make

## Getting Started
  1. Clone the repository
  2. ```cd``` into the repository
  3. Run ```make```
     * The server will listen on ```port 8080``` by default
      * You can then access the server by visiting ```http://localhost:8080``` in your web browser

## Serving
To serve the file ```index.html``` from the current directory, you can use the following command:

 - ```./server index.html```

To serve all files in the current directory, you can use the following command:

 - ```./server .```

## Troubleshooting
If you encounter any problems, please open an issue on the GitHub repository.

## Additional Information
This web server is still under development, but it is already a powerful tool that can be used to create a variety of web applications. If you have any suggestions for improvements, please feel free to open an issue on the GitHub repository.

Thank you for using this web server!
