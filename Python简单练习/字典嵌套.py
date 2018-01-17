users={'Tom':{
'first':'Dage',
'last':'SB',
'location':'Heilongjiang'
}
,
'Ben':
{
'first':'ERGE',
'last':'CHUN',
'lovstion':'ShanDong'}
}

for name,value in users.items():
	print("Name:"+" "+name)
	for a,b in value.items():
		print(a +" "+b)
