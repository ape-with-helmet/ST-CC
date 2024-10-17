'''
Write a python program to show the working of RSA. Take 2 inputs for prime numbers and then take message input after which 2 encrypted message and the decrypted message must be shown
'''

def gcd(a,b):
    '''
    Computes the greatest common divisor (GCD) of two numbers using the Euclidean algorithm.
    
    Input:
        a: First integer.
        b: Second integer.
        
    Output:
        Returns the GCD of a and b.
    '''
    while b!=0:
        a,b = b,a%b
    return a

def modinv(e,phi):
    '''
    Computes the modular inverse of e mod phi using the extended Euclidean algorithm.
    
    Input:
        e: The public exponent.
        phi: Euler's totient function of n.
        
    Output:
        Returns the modular inverse of e mod phi, which serves as the private key exponent.
    '''
    d,x1,x2,y1 = 0,0,1,1
    temp_phi = phi
    while e>0:
        temp1, temp2 = divmod(temp_phi,e)
        temp_phi,e = e,temp2
        x = x2-temp1*x1
        y = d-temp1*y1
        x2,x1 = x1,x
        d,y1 = y1,y
        if temp_phi == 1:
            return d+phi

def generate_keypair(p,q):
    '''
    Generates RSA public and private key pairs from two prime numbers.
    
    Input:
        p: A prime number.
        q: Another prime number.
        
    Output:
        Returns a tuple containing the public key (e, n) and the private key (d, n).
    '''
    n = p*q
    phi = (p-1)*(q-1)
    e = 17
    g = gcd(e,phi)
    while g!=1:
        e+=1
        g = gcd(e,phi)
    d = modinv(e,phi)
    return ((e,n),(d,n))

def encrypt(pk,plaintext):
    '''
    Encrypts a plaintext message using the public key.
    
    Input:
        pk: A tuple containing the public key (e, n).
        plaintext: The message to be encrypted.
        
    Output:
        Returns a list of integers representing the encrypted message.
    '''
    key,n = pk
    cipher = [pow(ord(char), key, n) for char in plaintext]
    return cipher

def decrypt(pk,ciphertext):
    '''
    Decrypts an encrypted message using the private key.
    
    Input:
        pk: A tuple containing the private key (d, n).
        ciphertext: A list of integers representing the encrypted message.
        
    Output:
        Returns the decrypted message as a string.
    '''
    key,n = pk
    plain = [chr(pow(char,key,n)) for char in ciphertext]
    return ''.join(plain)

if __name__ == '__main__':
    '''
    Main execution block. 
    
    Steps:
        1. Input two prime numbers, p and q.
        2. Generate the public and private keys using the generate_keypair() function.
        3. Input a message to encrypt.
        4. Encrypt the message using the public key.
        5. Decrypt the encrypted message using the private key.
        
    Outputs:
        - Prints the generated public and private keys.
        - Prints the encrypted and decrypted messages.
    '''
    
    p = int(input("Enter a prime number (p):"))
    q = int(input("Enter another prime number (q):"))
    
    public,private = generate_keypair(p,q)
    print(f"Public Key: {public}")
    print(f"Private Key: {private}")
    
    message = input("Enter the message to be encrypted: ")
    
    encrypted_message = encrypt(public,message)
    print(f"Encrypted Message: {encrypted_message}")
    
    decrypted_message = decrypt(private,encrypted_message)
    print(f"Decrypted Message: {decrypted_message}")