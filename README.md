# Python (Lite) Interpreter

### Simple implementation of python interpreter.

Base features:
- Prititives like int, float and str
- Loops (for / while) with break / continue statements
- Lists
- Functions (with recursion support)
- print(), input(), range()
- Error handling (incorrect statements, variable using and others)

[Sorting two arrays and merging them with unique values] Code example:
```python
a = [1, -4, 5, -5, 23]
b = [-3, -5, 5, 6, 100]
print(a)
for i in range(len(a)):
	for j in range(i+1, len(a)-1):
		if (a[i] > a[j]):
			tmp = a[i]
			a[i] = a[j]
			a[j] = tmp
print(a)
print(b)
for i in range(len(b)):
	for j in range(i+1, len(b)-1):
		if (b[i] > b[j]):
			tmp = b[i]
			b[i] = b[j]
			b[j] = tmp
print(b)
c = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
n = len(a) + len(b)
i = 0
j = 0
print(c)
while i + j < n:
	if i == len(a):
		c[i + j] = b[j]
		j = j + 1
		continue
	if j == len(b):
		c[i + j] = a[i]
		i = i + 1
		continue
	if i < len(a) && j < len(b) && a[i] <= b[j]:
		c[i + j] = a[i]
		i = i + 1
		continue
	if i < len(a) && j < len(b) && b[j] <= a[i]:
		c[i + j] = b[j]
		j = j + 1
		continue
print(c)
index = 1
result_index = 0
result = [c[0], 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
while index < len(c):
	if c[index] != result[result_index]:
		result[result_index + 1] = c[index]
		result_index = result_index + 1
	index = index + 1
print(result)
```

## How to run
#### Best choice - use Clion and import this project from version control

or just use pure cmake
```
cmake --build ..\python-lite-2\cmake-build-debug --target python_lite_2
```
### The source code of python-like code is located in input.txt
