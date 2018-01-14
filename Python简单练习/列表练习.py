destination=['YanTai','TaiWan','BeiJing','ShangHai','Nanjing']
print(destination)
print(sorted(destination))
print(destination)
#destination.sort()
#print(destination)
destination.reverse()
print(destination)
destination.remove('ShangHai')
print(destination)
destination.reverse()
print(destination)
for place in destination:
	print(place)
	print(place+"is good to visit"+"\n")
for a in range(1,10):
	for b in range(1,2):
		print(a)
		print(b)
#list() can change range() into list
num=list(range(2,11,2))
print(num)
for a in num:
	print(a)
squares=[]
for i in range(1,5):
	squares.append(i**3)
print(squares)
print(squares[0:3])
print(squares[1:4])
print(sum(squares))
print(min(squares))
print(max(squares))
print(squares[2:])
a=squares
print(a)
