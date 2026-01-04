def dh():
    n = int(input('Enter n (a prime number): '))
    g = int(input('Enter g (a prime number): '))
    print("\n")

    x_user1 = int(input('Enter a random number(Private Key of User1): '))
    A_user1 = pow(g, x_user1, n)
    print(f"A received by attacker: {A_user1}")
    print("\n")

    xy_attacker = int(
        input('Enter a random number(Private Key for Attacker(imitating as User1)): '))
    AB_attacker = pow(g, xy_attacker, n)
    print(f"A (Attacker imitating as User1) received by User2: {AB_attacker}")
    print("\n")

    y_user2 = int(input('Enter a random number(Private Key of User2): '))
    B_user2 = pow(g, y_user2, n)
    print(f"B received by attacker: {B_user2}")
    print("\n")

    print(f"B (Attacker imitating as User2) received by User1: {AB_attacker}")
    print("\n")

    User1_Shared = pow(AB_attacker, x_user1, n)
    User1_Attacker = pow(A_user1, xy_attacker, n)

    print(f"Shared Key for User1 with Attacker: {User1_Shared}")
    print(f"Shared Key for Attacker with User1: {User1_Attacker}")
    print("\n")

    User2_Shared = pow(AB_attacker, y_user2, n)
    User2_Attacker = pow(B_user2, xy_attacker, n)

    print(f"Shared Key for User2 with Attacker: {User2_Shared}")
    print(f"Shared Key for Attacker with User1: {User2_Attacker}")
    print("\n")

    return


dh()