import random

# For the lab, complete modexp(), RSA_enc(), and RSA_dec().
# HW 2 will allow you to submit the fully completed code from the lab,
#   as well as egcd(), mulinv(), and keygen(), for extra credit on the
#   assignment.
# You must work independently since this assignment will be part of HW 2.

# test constants
test_p = 23
test_q = 47
test_e =  35
test_d = 347
message = "Hello, World!"

def calc_n(p, q):
    # do not modify!
    return p * q

def calc_phi(p, q):
    # do not modify!
    return (p - 1) * (q - 1)

def modexp(b, e, m):
    # returns b^e % m efficiently
    # use the binary modular exponentiation algorithm explained in the lab slides
    # Complete this part during the lab
    val = 1
    base = b
    if modulus == 1:
        return 0

    while e > 0:
        if e % 2 == 1:
            val = (val * base) % m
        e = e >> 1
        base = (base * base) % m
        
    return val

def RSA_enc(plaintext, key):
    cipher = []
    key1, e = key
    for char in plaintext:
        cipher.append(int((ord(char) ** e) % key1))
    return cipher
    # key should be a tuple (n, e)
    # the ord() function will be useful here
    # we recommend extracting the components of the key from the tuple for efficiency purposes
    # return a list of integers
    # Complete this part during the lab
    

def RSA_dec(ciphertext, key):
    # key should be a tuple (n, e)
    # the chr() function will be useful here
    # we recommend extracting the components of the key from the tuple for efficiency purposes
    # return a string
    # Complete this part during the lab
    # cipher = ""
    # pt = ""
    # plain = []
    # for digit in ciphertext:
    #     cipher = cipher + str(digit)
    # key1, n = key
    # for char in cipher:
    #     plain.append(((ord(char) ** key1) % n))
    # for digit in plain:
    #     pt = pt + str(digit)
    # return pt
    plain = ""
    p = []
    key1, d = key
    print("KEY",key)
    for digit in ciphertext:
        print("DIGIT:",digit)
        val = (digit ** d) % key1
        p.append(chr(val))
    plain = ''.join(p)
    return plain

def test():
    # do not modify!
    n       = calc_n(test_p, test_q)
    private = [n, test_d]
    public  = [n, test_e]
    print("n",n)
    print("Public key:",public)
    print("Private key:",private)
    
    ciphertext = RSA_enc(message,public)
    ccc = str(ciphertext)
    print("Cipher", ccc)
    plaintext  = RSA_dec(ciphertext,private)

    print("Original message:",message)
    print("Encrypted message:",ciphertext)
    print("Decrypted message:",plaintext)

# === Below this comment is the portions of this assignment that contribute to HW 2 ===

def egcd(b, n):
    # runs the extended Euclidean algorithm on b and n
    # returns a triple (g, x, y) s.t. bx + ny = g = gcd(b, n)
    # review the extended Euclidean algorithm on Wikipedia
    # Complete for HW 2 extra credit
    if b == 0:
        return (b, 0, 1)
    else:
        g, x, y = egcd(b % a, a)
        z = x * (y - (b // a))
        return (g, z, x)
    return 0

def mulinv(e, n):
    # returns the multiplicative inverse of e in n
    # make use of the egcd above
    # Complete for HW 2 extra credit
    g, x, y = egcd(e, n)
    if g == 1:
        return x % n
    return 0

def checkprime(n, size):
    # do not modify!
    # determine if a number is prime
    if n % 2 == 0 or n % 3 == 0: return False
    i = 0

    # fermat primality test, complexity ~(log n)^4
    while i < size:
        if modexp(random.randint(1, n - 1), n - 1, n) != 1: return False
        i += 1

    # division primality test
    i = 5
    while i * i <= n:
        if n % i == 0: return False
        i += 2
        if n % i == 0: return False
        i += 4
    return True

def primegen(size):
    # do not modify!
    # generates a <size> digit prime
    if(size == 1): return random.choice([2, 3, 5, 7])
    lower = 10 ** (size - 1)
    upper = 10 ** size - 1
    p = random.randint(lower, upper)
    p -= (p % 6)
    p += 1
    if p < lower: p += 6
    elif p > upper: p -= 6
    q = p - 2
    while p < upper or q > lower:
        if p < upper:
            if checkprime(p, size): return p
            p += 4
        if q > lower:
            if checkprime(q, size): return q
            q -= 4
        if p < upper:
            if checkprime(p, size): return p
            p += 2
        if q > lower:
            if checkprime(q, size): return q
            q -= 2
        

def keygen(size):
    # generate a random public/private key pair
    # size is the digits in the rsa modulus, approximately. must be even, >2
    # return a tuple of tuples, [[n, e], [n, d]]
    # Complete this for HW 2 extra credit
    assert(size % 2 == 0 and size > 2) # keep this line!
    p = primegen(size/2)
    q = primegen(size/2)
    print("P=",p)
    print("Q=",q)
    n = p * q
    phi = (p - 1) * (q - 1)
    e = random.randrange(3, phi)
    gcde, x1, y1 = egcd(e, phi)
    while gcde != 1:
        e = random.randrange(3, phi)
        gcde, x1, y1 = egcd(e, phi)
    d = mulinv(e, phi)

    return ((n, e), (n, d))


def customkeytest(text, size):
    keypair = keygen(size)
    
    print("Public key:",keypair[0])
    print("Private key:",keypair[1])
    
    ciphertext = RSA_enc(text,keypair[0])
    plaintext  = RSA_dec(ciphertext,keypair[1])

    print("Original message:",text)
    print("Encrypted message:",ciphertext)
    print("Decrypted message:",plaintext)

test()