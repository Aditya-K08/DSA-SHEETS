def count_sets(row):
    count_M = 0
    count_L = 0
    i = 0
    while i < len(row):
        if row[i] == 'M':
            count_M += 1
            while i < len(row) and row[i] == 'M':
                i += 1
        elif row[i] == 'L':
            count_L += 1
            while i < len(row) and row[i] == 'L':
                i += 1
        else:
            return -1
    sets_M = (count_M * (count_M - 1) * (count_M - 2)) // 6
    sets_L = (count_L * (count_L - 1) * (count_L - 2)) // 6
    return sets_M + sets_L

def find_winner():
    row1 = input().strip()
    row2 = input().strip()
    if any(tree not in ['M', 'L'] for tree in row1 + row2):
        print("Invalid input")
        return
    count_row1 = count_sets(row1)
    count_row2 = count_sets(row2)
    if count_row1 == -1 or count_row2 == -1:
        print("Invalid input")
    elif count_row1 > count_row2:
        print("Ashok" if 'M' in row1 or 'L' in row1 else "Draw")
    elif count_row2 > count_row1:
        print("Anand" if 'M' in row2 or 'L' in row2 else "Draw")
    else:
        print("Draw")

find_winner()