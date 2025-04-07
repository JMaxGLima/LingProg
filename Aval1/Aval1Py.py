import math

print("Operations on a number:")
num = int(input("Type a number: "))
factorial = float(1)
for i in range(1,num+1,1):
    factorial *= i
square_root = math.sqrt(num)
power = pow(num, 2)
print(f"The factorial of the number is: {factorial:.2f}")
print(f"The square root of the number is: {square_root:.2f}")
print(f"The number raised to the power of 2 is: {power:.2f}")