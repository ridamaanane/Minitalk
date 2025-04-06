# 📡 Minitalk

**Minitalk** is a 42/1337 school project focused on inter-process communication using UNIX signals. The objective is to implement a simple messaging system between a client and a server using only `SIGUSR1` and `SIGUSR2`.

---

## 🧠 Project Overview

The project consists of two programs:

- **Server**: Waits for incoming signals from the client, reconstructs the characters, and prints the message.
- **Client**: Sends a string to the server, bit by bit, using signals.

Characters are converted into binary and transmitted bit-by-bit:
- `SIGUSR1` represents a binary `0`
- `SIGUSR2` represents a binary `1`

---

## 📁 File Structure

- `client.c`: Sends messages to the server using signals.
- `server.c`: Receives signals and prints the received message.
- `minitalk.h`: Header file containing function prototypes and includes.
- `Makefile`: Automates compilation of both programs.

---

## ⚙️ Compilation

To compile both programs, simply run:

```bash
make
```

This will generate two executables: `server` and `client`.

---

## ▶️ Usage

### 1. Start the server

```bash
./server
```

You’ll see the server’s **PID** printed. You’ll need this to send messages.

### 2. Send a message from the client

```bash
./client [PID] [message]
```

**Example:**

```bash
./client 12345 "Hello, World!"
```

> The client will encode and send the message to the server using signals.

---

## 🛠 How it works

### Client

- `ft_atol`: Converts the PID string to a long and checks for validity.
- `send_char`: Sends each bit of a character to the server using `kill()`.
- `send_string`: Loops through the full string and sends it character by character.

### Server

- `signal_handler`: Builds characters from incoming signals (bits) and prints them when complete.
- `pause()`: Keeps the server running, waiting for signals.

---

## ✅ Bonus Ideas (if implemented)

Unicode characters support

Unicode characters are supported both by the client and the server.

---

## 🌐 Bonus: Unicode Support with UTF-8

To extend the functionality of `minitalk`, I implemented **Unicode character transmission** using the **UTF-8 encoding** scheme.

### 📘 What is UTF-8?

**UTF-8 (8-bit Unicode Transformation Format)** is a variable-length character encoding for Unicode, capable of encoding all 1,112,064 valid character code points in Unicode using one to four 8-bit bytes.

It is **backward-compatible with ASCII**, and it's the **most widely used encoding** on the web and across platforms.

---

### 🔣 UTF-8 Encoding Format

Here is how Unicode code points are encoded into UTF-8 byte sequences:

| Unicode Range              | Binary Format                                 | Byte Count |
|---------------------------|-----------------------------------------------|------------|
| U+0000 to U+007F          | `0yyyzzzz`                                     | 1 byte     |
| U+0080 to U+07FF          | `110xxxyy` `10yyzzzz`                          | 2 bytes    |
| U+0800 to U+FFFF          | `1110wwww` `10xxxxyy` `10yyzzzz`               | 3 bytes    |
| U+10000 to U+10FFFF       | `11110uvv` `10vvwwww` `10xxxxyy` `10yyzzzz`    | 4 bytes    |

> Note: Each `x`, `y`, `z`, `w`, `u`, `v` represents a bit from the binary representation of the Unicode code point.

---

### ⚙️ How it works in `minitalk`

To support Unicode:
- Characters are first converted to their **UTF-8 byte representation**.
- Each byte is then sent using the existing signal-based transmission logic (bit-by-bit).
- On the server side, bytes are reconstructed and printed as UTF-8.

---

### ✅ Benefits

- Enables support for **emojis**, **Arabic**, **Chinese**, **symbols**, and any other Unicode characters.
- Fully compatible with existing ASCII-based communication.

---

### 📌 Example

If the client sends "emoji alien': `👽`  
UTF-32 (decimal)	: 128,125  
Binary code : 11111010001111101  
We will work in this range : U+10000 to U+10FFFF       | `11110uvv` `10vvwwww` `10xxxxyy` `10yyzzzz`    | 4 bytes  
Binary sent over signals:  

```
1111... that mean we will work in 4 bytes
11110uvv 10vvwwww 10xxxxyy 10yyzzzz
add 11110000 (4 bytes)  - (add 10 and 0 to complet 8 bit 11111 ) - 010001  - 111101
11110000 10011111 10010001 10111101
0b11110000 0b10011111 0b10010001 0b10111101
```
```
int main()
{
	int alien[] = {0b11110000, 0b10011111 ,0b10010001 ,0b10111101};
	for (int i = 0; i <= 3; i++)
		write(1, &alien[i], 1);
}
--> Output : 👽
```
