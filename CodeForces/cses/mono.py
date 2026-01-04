import random 
alpha = "abcdefghijklmnopqrstuvwxyz"
def encrypt(plaintext : str) : 
	l = list(alpha)
	random.shuffle(l)
	key = "".join(l)
	ct = []

	for x in plaintext:
		if x.lower() in alpha:
			y = key[alpha.index(x.lower())]
			if x.isupper():
				y = y.upper()
			ct.append(y)
		else:
			ct.append(X)

	return ["".join(ct),key]


ch = int(input('-----------------\n1. Encrypt\n2. Decrypt\n3. Exit\n-----------------\nEnter your choice: '))
if ch == 1:
	pt = input("enter plain text")
	ct = encrypt(pt)
	print(f'Ciphertext: {ct[0]}\nKey: {ct[1]}')
else :
	exit(0)