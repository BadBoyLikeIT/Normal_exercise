def add_end(L=None):
	if L is None:
		L = []
	L.append('END')
	return L
def fact(n):
	if n==1:
		return 1
	return n * fact(n - 1)
L = ['Michael','Sarah','Tracy','Bob','Jack']
def find(n):
	#Slice 数组切片
	print(L[0:n])
L1 = {'a':1,'b':2,'c':3}
def find1():
	for key in L1:
		print(key)
def create1():
	L2 = []
	for x in range(1,11):
		L2.append(x * x)
	return L2
def add(x,y,f):
	#f = ads
	return f(x) + f(y)

#map 与 reduce
def f(x):
	return x * x
def f1():
	r = map(f,[1,2,3,4,5,6,7,8,9])
	return list(r)
#str2num
#2018/1/8
from functools import reduce
def f2(x,y):
	return x*10 + y
def f3():
	return reduce(f2,[1,3,5,7,9])
def char2num(s):
	digits = {'0':0,'1':1,'2':2,'3':3,'4':4,'5':5,
	'6':6,'7':7,'8':8,'9':9}
	return digits[s]
def  str2int(s):
	return reduce(f2,map(char2num,s))

#正则匹配
import re
def test1(xx):
	if re.match(r'^\d{3}\-\d{3,8}$',xx):
		print('ok')
	else:
		print('faild')
#urllib
from urllib import request

def  testurl():
	 with request.urlopen('https://api.douban.com/v2/book/2129650') as f:
	 	data = f.read()
	 	print('Status:',f.status,f.reason)
	 	for k,v in f.getheaders():
	 		print('%s: %s'% (k,v))
	 	print('Data',data.decode('utf-8'))

