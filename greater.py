import math 

def findGreater(a, b, n): 

	if ((n & 1) > 0): 

		a = abs(a); 
		b = abs(b); 
	if (a == b): 
		print("a^n is equal to b^n"); 

	elif (a > b): 
		print("a^n is greater than b^n"); 

	else: 
		print("b^n is greater than a^n"); 

a = 12; 
b = 24; 
n = 5; 
findGreater(a, b, n); 

