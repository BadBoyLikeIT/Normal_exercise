print('hello,world!');
#input
#name = input('please enter your name: ')
#output
#print('hello',name)
#条件判断
age = 20
if age>=18:
	print('your age is',age);
	print('adult')
#遍历1
name1 = ['Michael','Bob','Tracy']
for name in name1:
	print(name)
#遍历2 这种循环不带括号，靠对齐来判断是否在程序内
sum = 0
for x in range(101):
	sum = sum + x
print(sum)
#dict map
d = {'Michael':95,'Bob':75,'Tracy':85}
print(d['Michael'])
#set
#def
x = input('input the x: ')
def power(x):
	return x*x
y = power(int(x))
print(y)
