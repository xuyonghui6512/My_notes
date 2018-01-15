alien_0={'color':'black','points':5}
print(alien_0['color'])
print(alien_0['points'])

print("the alien's color is "+alien_0['color']+" and it has "+str(alien_0['points'])+" points")

alien_0['The lover']='that girl'
alien_0['dage']='SB'
print(alien_0)

#create an empty dictionary
alien_1={}
alien_1['color']='yellow'
alien_1['points']=5
alien_1['numbers']=12
alien_1['dage']='WangMingYang'
alien_1['apple']='Big'
print(alien_1)

#delete an element in a dictionary
del(alien_1['color'])
print(alien_1)

#travel all keys and values in a dictionary
for key,value in alien_1.items():
	print("KEY:"+key)
	print("Value:"+str(value))
print('\n')
#travel all keys in a dictionary (using keys() is really convenient)
for key in alien_1.keys():
	print('Key:'+ key)
print('')
for key in sorted(alien_1.keys()):
	print('Key:' +key) 
