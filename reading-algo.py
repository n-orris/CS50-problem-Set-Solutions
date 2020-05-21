from cs50 import get_string
# takes text from reader to use
text = get_string("enter passage:")
# letters,words,sentences per 100 

words = text.count(" ")+1
letters = ((len(text)-(text.count("'")+text.count(".")+text.count("!")+text.count("?")+text.count(" ")+text.count(",")+text.count('"'))) / words ) * 100
sentences = ((text.count(".")+text.count("!")+text.count("?")) / words) * 100

index = round((0.0588 * letters) - (0.296 * sentences) - 15.8)

if (index >= 16):
    print("Grade 16+")
elif (index < 1):
    print("Before Grade 1")
else:
    print("Grade ",index)
