
function countVowels(word) {
    let vowels = 0;
    const lowerWord = word.toLowerCase();

    for (let i = 0; i < lowerWord.length; i++) {
        if ("aeiou".includes(lowerWord[i])) {
            vowels++;
        }
    }

    return vowels;
}
