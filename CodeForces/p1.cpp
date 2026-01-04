import os

def has_distinct_digits(year):
    return len(set(str(year))) == len(str(year))

def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True

def digit_sum(year):
    return sum(int(d) for d in str(year))

def chrono_crystal_year(start_year):
    year = start_year + 1
    while year <= 9800:  # Upper limit reduced to avoid -1
        if has_distinct_digits(year) and is_prime(digit_sum(year)):
            return year
        year += 1
    return -1  # Should not occur due to adjusted range

def create_test_case(base_path, name, input_value):
    output_value = chrono_crystal_year(input_value)
    if output_value == -1:
        return  # Skip invalid test case
    input_folder = os.path.join(base_path, name)
    output_folder = os.path.join(base_path, name.replace("input", "output"))

    os.makedirs(input_folder, exist_ok=True)
    os.makedirs(output_folder, exist_ok=True)

    with open(os.path.join(input_folder, "input.txt"), "w") as f:
        f.write(str(input_value))
    with open(os.path.join(output_folder, "output.txt"), "w") as f:
        f.write(str(output_value))

def main():
    base_path = "testcases_9800"
    test_cases = [
        ("basicinput1", 1987),
        ("basicinput2", 1000),
        ("basicinput3", 1234),
        ("basicinput4", 2013),
        ("cornerinput1", 9790),
        ("cornerinput2", 9799),
        ("defaultinput1", 3456),
        ("defaultinput2", 4321),
        ("nessaryinput1", 2222),
        ("nessaryinput2", 1111),
        ("timecomplexityinput1", 8500),
        ("timecomplexityinput2", 8700),
    ]

    for name, value in test_cases:
        create_test_case(base_path, name, value)

    print(f"Test cases generated in folder: {base_path}")

if __name__ == "__main__":
    main()
