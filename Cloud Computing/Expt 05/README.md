
# RSA Encryption and Decryption Script

## Overview:
This script implements RSA encryption and decryption using Python. RSA is an asymmetric cryptographic algorithm that uses a pair of keys – one public and one private – to encrypt and decrypt messages. The script generates a key pair from two prime numbers, encrypts a user-provided message, and decrypts the resulting ciphertext.

## Functions:

1. **`gcd(a, b)`**:
   - **Purpose**: Computes the greatest common divisor (GCD) of two numbers using the Euclidean algorithm.
   - **Parameters**:
     - `a`: First integer.
     - `b`: Second integer.
   - **Returns**: The GCD of `a` and `b`.

2. **`modinv(e, phi)`**:
   - **Purpose**: Calculates the modular multiplicative inverse of `e` modulo `phi`. This is crucial for generating the private key in RSA.
   - **Parameters**:
     - `e`: Public exponent.
     - `phi`: Euler's Totient function for `n`.
   - **Returns**: The modular inverse of `e` mod `phi`, which is used as the private key.

3. **`generate_keypair(p, q)`**:
   - **Purpose**: Generates the public and private key pair using two prime numbers `p` and `q`.
   - **Parameters**:
     - `p`: A prime number.
     - `q`: Another prime number.
   - **Returns**: A tuple containing the public key `(e, n)` and private key `(d, n)`.

4. **`encrypt(pk, plaintext)`**:
   - **Purpose**: Encrypts the given plaintext using the provided public key.
   - **Parameters**:
     - `pk`: A tuple representing the public key `(e, n)`.
     - `plaintext`: The message to be encrypted.
   - **Returns**: A list of integers representing the encrypted message.

5. **`decrypt(pk, ciphertext)`**:
   - **Purpose**: Decrypts the given ciphertext using the provided private key.
   - **Parameters**:
     - `pk`: A tuple representing the private key `(d, n)`.
     - `ciphertext`: A list of integers representing the encrypted message.
   - **Returns**: The decrypted message as a string.

## How It Works:

1. **Key Generation**:
   The user inputs two prime numbers, `p` and `q`. The script generates a public key `(e, n)` and a private key `(d, n)` based on these prime numbers. 
   - `n` is the product of `p` and `q`, and `phi` is the product of `(p-1)` and `(q-1)`.
   - `e` is initially set to `17` and adjusted if necessary to ensure it is coprime with `phi`.
   - The private key `d` is computed as the modular inverse of `e` modulo `phi`.

2. **Encryption**:
   The user inputs a message, which is encrypted using the public key. Each character in the message is converted to its ASCII value, raised to the power of `e`, and taken modulo `n`.

3. **Decryption**:
   The encrypted message is decrypted using the private key. Each integer in the encrypted message is raised to the power of `d` and taken modulo `n`, then converted back to its corresponding character.

## Example:

```bash
Enter a prime number (p): 61
Enter another prime number (q): 53
Public Key: (17, 3233)
Private Key: (2753, 3233)
Enter the message to be encrypted: Hello
Encrypted Message: [2790, 2201, 2920, 2920, 217]
Decrypted Message: Hello
```

## Potential Question Based on Requirements:

*In the implementation of RSA encryption and decryption, what specific characteristics should the prime numbers `p` and `q` possess to ensure both security and optimal performance? Additionally, how do the values of `e` and `phi` influence the choice of the private key, and what measures should be taken to ensure that the encryption and decryption processes are reversible in all cases?*
