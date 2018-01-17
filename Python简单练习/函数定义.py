def shut(username):
	print("Hello!"+username)
shut("dage")
shut("SB")

def body(hand='da',head='xiao'):
	print(hand+' '+head+'\n')
body()
body('sss','bbbb')
body(head='bbbb',hand='sss')

def get_formatted_name(first_name,last_name):
	full_name=first_name +" "+ last_name
	return full_name.title()
first_name=input("please input your first name: ")
last_name=input("please input your last name: ")
My_name=get_formatted_name(first_name,last_name)
print(My_name)

def create_dictionary(first,last):
	name={'first':first,'last':last}
	return name
first='dage'
last='xiaohai'
a=create_dictionary(first,last)
print(a)
def list_try(ao):
	for b in ao:
		print("hello! "+b)
o=['a','f','ssd','sd']
list_try(o)

def dododo(*lai):
	for a in lai:
		print(a)
dododo('sd')
dododo('as','sdd','sdfe')
