def rev_sentence(sentence):

    words = sentence.split(" ")
    reverse_sentence = " ".join(reversed(words))
    return reverse_sentence


string = input("Enter a sentence: ")
print(rev_sentence(string))
