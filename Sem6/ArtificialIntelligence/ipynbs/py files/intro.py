print("Hello World!", end="\n\t\t")
print("Hello, how are you?")

x = 2
y = 10
print(x / y)

a = int(input("Enter first number: "))
b = int(input("Enter second number: "))
print(a**b)

import numpy as np

list = [1, 1, 2, 3, 5, 8, 13, 21, 34, 55]
array = np.array(list)
print(array)


def factorial(num):
    result = 1
    if num == 0:
        return result
    else:
        for i in range(1, num + 1):
            result = i * result
        return result


print(factorial(5))


m = np.array([[1, 0], [0, 1]])
n = np.array([[2, 6], [9, 15]])
print(m @ n)

import matplotlib.pyplot as plt

x = np.linspace(1, 20, 20)
y = x**0.5
plt.plot(x, y, "r")
plt.xlabel("x-axis")
plt.ylabel("y-axis")
plt.title("Square Root Function")
plt.show()

import pandas as pd

dict = {
    "S.No.": [1, 2, 3, 4],
    "Name": ["Jacob", "Arthur", "Peacock", "Akira"],
    "Age": [27, 34, 56, 23],
}
df = pd.DataFrame(dict).set_index("S.No.")
print(df)


def hcf(num1, num2):
    cf = []
    if num1 == 0 | num2 == 0:
        return 1
    else:
        m = []
        for i in range(1, num1 + 1):
            if num1 % i == 0:
                m.append(i)
        n = []
        for i in range(1, num2 + 1):
            if num2 % i == 0:
                n.append(i)
        cf = set(m) & set(n)
        return max(cf)


print(hcf(63, 343))

X = [1, 2, 3, 4, 5, 6, 7, 8]
Y = [1, 2, 3, 4, 5, 6, 7, 8]
plt.plot(X, Y)
plt.show()

X = np.linspace(0, 10, 100)
Y = np.sin(X)
plt.plot(X, Y)
plt.show()

X = np.array([1, 2, 3, 4, 5, 6, 7, 8])
Y = np.array([7, 6, 5, 4, 3, 2, 1, 0])
plt.scatter(X, Y)
plt.show()

plt.hist(array)
plt.xlabel("Value")
plt.ylabel("Frequency")
plt.title("Histogram")
plt.show()

labels = ["A", "B", "C", "D", "E"]
sizes = [15, 30, 25, 10, 20]
plt.pie(sizes, labels=labels, autopct="%1.1f%%")
plt.title("Pie Chart")
plt.show()
