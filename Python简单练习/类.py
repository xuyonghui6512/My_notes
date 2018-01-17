class Dog(object):
	def _init_(self,name,age):
		self.name=name
		self.age=age
	def sit(self):
		print(self.name.title()+" is now sitting.")
	def roll_over(self):
		print(self.name.title()+" rolled over!")

my_dog = Dog('WangMingyang',6)
print("My dog name is "+my_dog.name.title() +" .")
print("Mt dog's age is "+str(my_dog.age)+" .")

