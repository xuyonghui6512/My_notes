class Dog(object):
	def __init__(self,name,age):
		self.name=name
		self.age=age
	def sit(self):
		print(self.name.title()+" is now sitting.")
	def roll_over(self):
		print(self.name.title()+" rolled over!")

my_dog = Dog('WangXingyang',6)
print("My dog name is "+my_dog.name.title() +" .")
print("Mt dog's age is "+str(my_dog.age)+" .")

my_dog.sit();
my_dog.roll_over();

class Car(object):
	def __init__(self,make,model,year):
		self.make=make
		self.model=model
		self.year=year
		self.odometer_reading=0
	def read_odometer(self):
		print("this car has "+str(self.odometer_reading)+" miles on it.")
	def change_odometer(self,miles):
		self.odometer_reading=miles
		

my_new_car=Car('Audo','a4',2016)
my_new_car.change_odometer(25)
my_new_car.read_odometer()

