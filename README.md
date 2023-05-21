# C++ Web Server
This C++ web server is a powerful tool that can be used to serve static files and handle HTTP requests. The server supports multiple concurrent connections and different HTTP methods and status codes.

Some of the key features of this web server include:

  1. **Serving static files**: The server can be used to serve static files, such as HTML, CSS, and JavaScript files. This makes it ideal for hosting simple websites and web applications.
  2. **Handling HTTP requests**: The server can handle a variety of HTTP requests, including GET, POST, PUT, and DELETE. This allows it to be used to implement a wide range of web functionality.
  3. **Supporting multiple concurrent connections**: The server can support multiple concurrent connections, which makes it ideal for handling high-traffic websites and web applications.
  4. **Supporting different HTTP methods and status codes**: The server supports a wide range of HTTP methods and status codes, which makes it compatible with a wide range of web browsers and other clients.

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
## Requirements
  - C++ compiler
  - GNU Make

## Getting Started
  1. Clone the repository
  2. ```cd``` into the repository
  3. Run ```make```
     * The server will listen on ```port 8080``` by default
      * You can then access the server by visiting ```http://localhost:8080``` in your web browser

## Examples
To serve the file ```index.html``` from the current directory, you can use the following command:

 - ```./server index.html```

To serve all files in the current directory, you can use the following command:

 - ```./server .```

## Troubleshooting
If you encounter any problems, please open an issue on the GitHub repository.

## Additional Information
This web server is still under development, but it is already a powerful tool that can be used to create a variety of web applications. If you have any suggestions for improvements, please feel free to open an issue on the GitHub repository.
