import os

# Load the dictionary from yawl.txt
def load_words(file_path):
    with open(file_path, "r") as file:
        words = set(word.strip().upper() for word in file)
    words.update({"I", "A"})  # Add single-letter words that are missing
    return words

# Generate all "children" words by removing one letter at a time
def generate_children(word):
    return {word[:i] + word[i+1:] for i in range(len(word))}

# Check if a word is reducible (Memoized for efficiency)
def is_reducible(word, words, memo):
    if word in memo:  # Already computed
        return memo[word]
    if word in {"I", "A"}:  # Base case: Single-letter words
        return True
    
    # Check if any child word is reducible
    memo[word] = any(is_reducible(child, words, memo) for child in generate_children(word) if child in words)
    return memo[word]

# Find the longest reducible word from the given choices
def find_longest_reducible(choices, words):
    memo = {}  # Memoization dictionary
    longest_word = ""
    max_length = 0
    word_reduction_counts = {}

    for word in choices:
        if is_reducible(word, words, memo):
            reduction_count = count_reductions(word, words, memo)
            word_reduction_counts[word] = reduction_count
            if len(word) > max_length:
                max_length = len(word)
                longest_word = word

    return longest_word, word_reduction_counts

# Count the number of valid words derived from a given word
def count_reductions(word, words, memo):
    if word in {"I", "A"}:
        return 1  # Base case

    children = [child for child in generate_children(word) if child in words and is_reducible(child, words, memo)]
    return 1 + max((count_reductions(child, words, memo) for child in children), default=0)

# File path for yawl.txt (Ensure it's in the same directory or adjust the path)
file_path = "bonus/yawl.txt"

# List of candidate words
candidate_words = {
    "AUSTRINGERS", "BREASTFEEDS", "CARABINEERS", "CARABINEROS", 
    "CARABINIERS", "COMPLECTING", "HOUSELLINGS", "STREAMLINGS", "UNPREACHING"
}

# Load the dictionary and find the longest reducible word
words = load_words(file_path)
longest_word, word_reduction_counts = find_longest_reducible(candidate_words, words)

# Print the results
print(f"Longest reducible word: {longest_word}")
print(f"Number of words derived from {longest_word}: {word_reduction_counts.get(longest_word, 0)}")
print("\nAll reducible words and their derived counts:")
for word, count in sorted(word_reduction_counts.items(), key=lambda x: -x[1]):
    print(f"{word}: {count}")


'''
1,117,065
73,682
LAZZEZZA
tried: streamlings, caribineros
425,185
'''