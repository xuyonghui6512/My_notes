a=[1,3,5,7,9,11,13]
if(2 in a):
	print("DAGE")
if(3 in a):
	print("dage")
if(2 not in a):
	a.insert(1,2)
print(a)
age1=[1,15,18,19,25,13,5,7]
for age in age1:
	if(age>18):
		print("you are too old")
	elif(10<age<19):
		print("you are so young")
	else:
		print("you are a baby")
