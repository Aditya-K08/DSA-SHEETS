import hashlib

def calculate_sha1():
    # Read the message
    message = input("Enter the message: ")
    
    # Calculate SHA-1 hash
    sha1_hash = hashlib.sha1(message.encode())
    
    # Print the hash in hexadecimal format
    print(f"SHA-1 Hash: {sha1_hash.hexdigest()}")

if __name__ == "__main__":
    calculate_sha1()
