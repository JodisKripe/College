import nltk
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize
from nltk.stem import PorterStemmer, WordNetLemmatizer

nltk.download("punkt")
nltk.download("stopwords")
nltk.download("wordnet")


def preprocess_text(text):
    tokens = word_tokenize(text.lower())
    stop_words = set(stopwords.words("english"))
    filtered_tokens = [word for word in tokens if word not in stop_words]
    stemmer = PorterStemmer()
    stemmed_tokens = [stemmer.stem(word) for word in filtered_tokens]
    lemmatizer = WordNetLemmatizer()
    lemmatized_tokens = [lemmatizer.lemmatize(word) for word in filtered_tokens]
    return tokens, filtered_tokens, stemmed_tokens, lemmatized_tokens


text = (
    "Hi I am Siddharth Johri and this is an input text for Natural Language Processing"
)
tokens, filtered_tokens, stemmed_tokens, lemmatized_tokens = preprocess_text(text)
print(" The tokens:")
print(tokens)
print("\n After Removing Stop words:")
print(filtered_tokens)
print("\nStemmed Tokens:")
print(stemmed_tokens)
print("\nLemmatized Tokens:")
print(lemmatized_tokens)
