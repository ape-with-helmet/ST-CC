
# Java Encrypted Messaging System

This project demonstrates a simple client-server architecture where messages are sent between a client and a server. The communication involves encryption and decryption of messages using AES (Advanced Encryption Standard) for secure data transfer.

## Features
- **Client-Server communication**: A basic server that listens for incoming connections and a client that sends encrypted messages to the server.
- **AES Encryption**: The messages are encrypted on the client side using AES encryption and decrypted on the server side.
- **Error Handling**: The server handles messages that it cannot decrypt by returning an appropriate response.

## Prerequisites
- Java Development Kit (JDK) 8 or above
- Basic knowledge of Java sockets and cryptography

## Files
### 1. `Server.java`
This file contains the code for the server which listens for incoming client connections on port 8080, decrypts incoming encrypted messages, and sends an acknowledgment back to the client.

### 2. `Client.java`
This file contains the client-side implementation. The client connects to the server, encrypts a message using AES, and sends it to the server.

### 3. `AESEncryptionUtil.java`
A utility class responsible for AES encryption and decryption operations. It contains methods to encrypt and decrypt messages as well as to generate a symmetric AES key.

## How It Works
1. The **Server** starts and listens on port `8080`.
2. A **Client** connects to the server and sends an encrypted message using AES encryption.
3. The server decrypts the message and returns a response to the client confirming successful decryption. If the decryption fails, the server responds with an error message.

### Encryption Details
- **AES Encryption**: The encryption algorithm used is AES with a symmetric key. The key used for encryption is hardcoded in the `AESEncryptionUtil` class as `"1234567890123456"`.
  
## How to Run

### 1. Compile the Java files
```bash
javac Server.java Client.java AESEncryptionUtil.java
```

### 2. Start the server
```bash
java Server
```

### 3. Start the client in another terminal and send a message
```bash
java Client
```

Enter a message in the client terminal, which will be encrypted and sent to the server. The server will decrypt the message and print both the encrypted and decrypted versions.

### Example Interaction
**Client:**
```bash
java Client
Hello, Server!
```

**Output:**
```
Encrypted Message: (Encrypted message in Base64 format)
Server response: Message received and decrypted successfully
```

**Server:**
```
Server is running...
Client connected.
Received encrypted message: (Encrypted message in Base64 format)
Decrypted message: Hello, Server!
```

## Improvements
- **Dynamic Key Handling**: Instead of hardcoding the AES key, dynamically generating and securely sharing the key between client and server would improve security.
- **Multi-client Handling**: Currently, the server handles one client at a time. Using threads to handle multiple clients would make the server more scalable.
  
## Dependencies
- **Java Cryptography Extension (JCE)**: This program uses Java's built-in cryptography libraries, no external libraries are needed.
