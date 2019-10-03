def removeDulipcates(arr): 
	s = dict() 
	d = [] 

	for i in arr: 
		if i not in s.keys(): 
			
			# Adding elements to the dictionary 
			d.append(i) 
			s[i] = 1
	
	# Printing the dictionary 
	print(d) 

# Driver Code 
arr = [1, 2, 5, 1, 7, 2, 4, 2] 
removeDulipcates(arr)	 

