![minitalk](https://github.com/user-attachments/assets/6063f90f-0705-415b-b134-fa48d8f47667)



# **minitalk**
Creating a small data exchange program using UNIX signals

## **Project overview**
The **minitalk** project is an integral part of the **42 curriculum**.
It tasks students with creating a communication program consisting of a client and a server, using UNIX signals for data exchange.
This project aims to enhance understanding of inter-process communication, signal handling, and efficient coding practices in C.

#### **Objective**
- **Create Client and Server Programs**: Develop a client and a server program for data exchange using UNIX signals.
- **Signal Handling**: Implement robust signal handling to ensure reliable communication between the client and server.
- **Error Handling**: Ensure thorough error handling to prevent unexpected crashes (segmentation faults, bus errors, etc.).
- **Memory Management**: Properly manage dynamic memory allocation to avoid memory leaks.
- **Bonus**: Implement additional features such as server acknowledgment of messages and support for Unicode characters.

#### **Key features**
- **Client-Server Communication**: Implement communication between a client and a server using only the `SIGUSR1` and `SIGUSR2` signals.
- **PID Management**: The server prints its PID on startup, and the client uses this PID to send messages to the server.
- **String Transmission**: The client sends a string to the server, which then prints the received string.
- **Multiple Clients**: The server can handle strings from multiple clients sequentially without needing a restart.
- **Bonus Features**:
  - **Acknowledgment**: The server sends a signal back to the client to acknowledge each received message.
  - **Unicode Support**: Support for sending and receiving Unicode characters.

#### **Compiling the Project**
The minitalk project includes a Makefile for easy compilation.
Simply run:
```bash
make
```
This will generate the client and server executables.

#### **Running the Project**
To start the server, run:
```bash
./server
```
The server will print its PID.
Use this PID to send a message from the client:
```bash
./client <server_pid> "Hello, world!"
```

#### 🛠 Skills
- c
- Signal handling
- Inter-process communication
- Memory management

#
💬 **Ask Me About:**
- Anything you need related to this project!

#
📫 **How to Reach Me:**
- **42 Students:** Contact me on Slack (smontuor)
- **Others:** Email me at smontuor@student.42firenze.it
