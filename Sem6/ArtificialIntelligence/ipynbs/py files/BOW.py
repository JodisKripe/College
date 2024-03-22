from sklearn.feature_extraction.text import CountVectorizer

corpus = [
    "This is a book",
    "This is my study table.",
    "And this is the third one.",
    "Is this okay?",
]
vectorizer = CountVectorizer()
X = vectorizer.fit_transform(corpus)
feature_names = vectorizer.get_feature_names_out()
print("Feature Names (Words):", feature_names)
# Bag of Words representation
print("Bag of Words Matrix:")
print(X.toarray())
