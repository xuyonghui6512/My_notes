a=[1,2,3,4,5]
print(a)
print(a[0])
print(a[-1])#return the last element in the list a

#add / remove / revamp the element

a[0]=6
print(a)
a.append(8)
print(a)
b=[]
b.append(1)
b.append(2)
b.append(3)
print(b)
a.insert(3,3)
print(a)
#remove element
del a[0]
print(a)
#pop an element and you can use it
c=a.pop()
print(a)
print(c)
d=a.pop(2)
print(a)
print(d)
#you can remove the element according to its content by using the command "remove" and you can use the element that you have removed
test=['what','where','when','how']
r=test.remove('where')
print(r)
print(test)
#using sort() to sort the element
b=[2,1,9,7,6,8,5,4]
b.sort()
print(b)
b.sort(reverse=True)
print(b)
#using len() to gain the length of list
print(len(b))



