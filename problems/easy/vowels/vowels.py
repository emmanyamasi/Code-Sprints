def count_vowels(word):
    vowels = 0
    for letter in word.lower():
        if letter in "aeiou":
            vowels += 1
    return vowels
