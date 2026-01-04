import os
import random

def min_moves(n):
    return (n + 2) // 3

# Target numbers of test cases per category
categories = {
    "Basic": 4,
    "Corner": 2,
    "Default": 2,
    "Necessary": 2,
    "TimeComplexity": 2
}

# Step range for each category
ranges = {
    "Basic": range(1, 20),
    "Corner": [999999999, 1000000000],
    "Default": [50, 100],
    "Necessary": [25, 26, 27, 28, 29, 30],
    "TimeComplexity": [10**9 - 1, 10**9]
}

used_outputs = set()
used_inputs = set()
test_dir = "Test cases"
os.makedirs(test_dir, exist_ok=True)

counter = {k: 1 for k in categories}

def save_case(category, val):
    global counter
    out = min_moves(val)
    input_file = os.path.join(test_dir, f"{category}Input{counter[category]}.txt")
    output_file = os.path.join(test_dir, f"{category}Output{counter[category]}.txt")
    with open(input_file, "w") as f_in:
        f_in.write(f"{val}\n")
    with open(output_file, "w") as f_out:
        f_out.write(f"{out}\n")
    counter[category] += 1
    used_outputs.add(out)
    used_inputs.add(val)

for category, count in categories.items():
    domain = list(ranges[category])
    random.shuffle(domain)

    attempts = 0
    while counter[category] <= count and attempts < 1000:
        if category == "TimeComplexity":
            val = random.randint(10**9 - 100, 10**9)
        else:
            if not domain:
                break
            val = domain.pop()

        if val in used_inputs:
            attempts += 1
            continue
        out = min_moves(val)
        if out in used_outputs:
            attempts += 1
            continue
        save_case(category, val)
        attempts = 0  # reset on success

print("✅ Unique test cases generated successfully in 'Test cases/' folder.")
