from collections import Counter

# Example list
data = ['apple', 'banana', 'apple', 'orange', 'banana', 'apple']

# Creating a counter object
counter = Counter(data)

# Getting the two most common elements
most_common = counter.most_common(2)
counter["apple"] = -1
print (counter)
# print(most_common)