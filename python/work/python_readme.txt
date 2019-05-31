环境操作：
1.安装python，并手动配置环境变量。
2.在d:\kit\python\work编写相关的.py文件
3.在当前工作目录下打开cmd
4.交互模式：输入python;命令行模式：exit()
  4.1.python hello.py  //直接执行
  4.2.python -i lib.py  //交互模式输入 add_end() //注意一定要输入这个括号

输入和输出
1.print()
2.name = input()

数组
1.lsit
classmates = ['Michael','Bob','Tracy']
len(classmates) //获得数组个数
classmates.insert(1,'jack')  //数组插入
classmates.pop(2) //数组删除
classmates[1] = 'Sarah' //改变
2.tuple 一旦初始化就不可以改变
classmates = ('Michael','Bob','Tracy')  
3.dict 字典
d = {'Michael':95,'Bob':75,'Tracy':85}
d.get('Thomas')  //查询是否存在
d.pop('Bob') //删除
4.set 集合

循环
1.for
example1:
names = ['Michael','Bob','Tracy']
for name in names 
	print(name)
example2:
sum = 0
for x in [1,2,3,4,5,6,7,8,9,10]:
	sum = sum + x
	print(sum)
example3:
list(range(10)) //生成[0,1,2,3,4,5,6,7,8,9]

条件判断
example1:
age = 20
if age >= 6:
	print('teenager')
elif age >= 18:
	print('adult')
else:
	print('kid')

高阶函数
1.map 接受两个参数，一个是参数，一个是iterable，并把结果作为新的
Iterator返回
example:
def f(x):
	return x * x

r = map(f,[1,2,3,4,5,6,7,8,9])
list(r)
[1,4,9,16,25,36,49,64,81]
2.reduce 把一个函数作用在一个序列[x1,x2,x3,...]上，把结果继续和序列的下一个元素做累计计算。
example:
form functools import reduce
def add(x,y):
	return x + y

reduce(add,[1,3,5,7,9])
>>>25

综合example:str2int
def f2(x,y):
	return x*10 + y
def char2num(s):
	digits = {'0':0,'1':1,'2':2,'3':3,'4':4,'5':5,
	'6':6,'7':7,'8':8,'9':9}
	return digits[s]
def  str2int(s):
	return reduce(f2,map(char2num,s))

3.filter 接受一个函数和一个序列 依次作用于每个元素，然后根据返回值是true还是false决定保留还是丢弃该元素
example:
def is_odd(n):
	return n % 2 ==1
list(fileter(is_odd,[1,2,4,5,6,9,10,15]))

4.sorted()

5.匿名函数
example:
list(map(lambda x: x*x,[1,2,3,4,5,6,7,8,9]))

6.匿名函数
example:
list(map(lambda x: x * x,[1,2,3,4,5,6,7,8,9]))
>>>[1,4,9,16,25,36,49,64,81]
匿名函数：lamba
函数对象有一个__name__属性，可以拿到函数的名字

7.偏函数
int('12345',base=8)
  functools.partial的作用就是把一个函数的某些参数给固定住

8.模块
  一个.py文件就称之为一个模块(Module)
  按目录来组织模块的方法，称为package

private是一种非常有用的代码封装和抽象的方法，即：外部不需要引用的函数全部定义成private，只有外部需要引用的函数才定义为public。

9.安装第三方模块
  通过pip这个包管理工具完成的
type()对类型进行判断
isinstance() 判断是否是一个实例子继承关系
dir() 一个str对象的所有属性和方法

10面向对象
__两个下划线表示私有变量
封装：面向对象就是将一系列的数据结构封装起来
多态：本质上是一种数据结构下的继承。可以允许一种父类下的多种子类的一种机制。
继承：1.可以把父类的所有功能都直接拿过来，这样就不必从零做起，2.子类只需要新增自己特有的方法，也可以把父类不适合的方法重写。

可以通过type()来看类的名称，可以通过查看isinstance()来判断类是否属于父类。dir()获取一个对象的所有方法和属性。

11.面向对象高级编程
可以动态绑定对象的方法
example:def set_score(self,score)
			self.score = score
	    Student.set_score = set_scor
可以根据子类的多重符合的集合，设置多重继承

12.错误调试：
   try
   {

   }except ZeroDivisionError as e:
   		print('except:',e)


  Note:ZeroDivisionError是系统已经定义的一种错误
可以通过print与logging来打印

13.IO编程
你买汉堡，服务员告诉你需要5分钟的制作时间。
同步：你再柜台前等待，直到做好。
异步：你先去逛商场，做好了喊你。
	  回调：做好了，服务员跑去找你。
	  轮询：你不断的看手机，做好了，服务员给你发信息。
example:
f = open(r'D:\test.txt','r',encoding='gbk')
f.read()
f.close()

f = open(w'D:\test.txt','w')
f.write('hello,world!')
f.close()

read() 			//一次性读取
read(size)		//比较保险
readline()		//每次读取一行的内容
readlines()		//一次读取所有内容并按行返回list

write()覆盖写
'w'换成'a'可以追加写

操作文件与目录：
import os
os.path.abspath('.') 	//查看当前目录

os.path.join('D:/','lss')  //表示完整路径
os.mkdir('D:/lss')         //创建文件夹
os.rmdir('D:/lss')		   //删除文件夹

os.path.split()            //拆分最后一个路径
os.path.splitext()		   //可以直接得到扩展名

os.rename('test.txt','test.py')  //重命名
os.remove('test.py')             //删除


example：
[x for x in os.listdir('.') if os.path.isfile(x) and os.path.splitext(x)[1]=='.py' ]
//打印当前目录下所有的py文件

序列化：变量从内存中变成可存储或传输的过程称之为序列化。
jaso与xml就是一种序列化文件格式

14.进程与线程
对于操作系统来说，一个任务就是一个进程，一个任务的子任务就是线程。
Mac系统是基于BSD(Unix的一种)
indent通常因为python对齐的问题
close()之后就不能继续添加新的Process了
进程之间的通信可以通过pipe与queue
任何进程默认会启动一个线程，这个线程称为主线程。
多线程和多进程最大的不同在于，多进程中，同一个变量，各自有一份拷贝在每个进程中，互不影响，而多线程中，所有变量都由所有线程共享。所以线程在更改数据的时候需要加锁互斥。
一个死循环线程会100%占用一个CPU。
线程中ThreadLocal是一个类型全局的变量，在线程中变量传递中比较有用。
多进程的缺点是占用系统资源较多；多线程的缺点是任何一个线程挂掉都可能造成整个进程崩溃，因为所有线程共享进程的内存。
单任务模型或者批处理任务模型
计算密集型任务与IO密集型任务，IO密集型涉及到网络、磁盘的IO
异步IO与事件驱动模型

15.正则表达式
\d 匹配 数字
\w 匹配 字母或者数字
.  匹配 任意字符

+  匹配 至少一个内容
*  匹配 任意个内容
？ 匹配 表示0个或者一个字符
\  转义字符
.+? 匹配任意内容
() 按元组返回
example：\d{3}\s+\d{3,8}  
		 \d{3}  //匹配三个数字
		 \s+    //至少有一个空格
		 \d{3,8}//表示3-8个数字
         \d{3}\-\d{3,8} //010-12345 \转义字符

example：[0-9a-zA-Z\_] //可以匹配一个数字、字母或者下划线
         [0-9a-zA-Z\_]+  //可以匹配至少由一个数字、字母或者下划线组成的字符串，比如'a100','0_Z','py300'
         [0-9a-zA-Z\_][0-9a-zA-Z]* //可以匹配由字母或下划线开头，后接任意个由一个数字、字母或者下划线组成的字符串，也就是python合法的变量
         [a-zA-Z_][0-9a-zA-Z\_]{0,19} //更精确地限制了变量的长度是1-20个字符(前面1个字符+后面最多19个字符)
         A|B 可以匹配A或B，所以(P|p)ython可以匹配'Python'或者'python'
         ^表示行的开头， ^\d 表示必须以数字开头
         $表示行的结束，\d$ 表示必须以数字结束
example:切分字符串
		re.split(r'[\s\,\:]+','a,b:: c  d')
example:分组
		>>> t = '19:05:30'
		>>> m = re.match(r'^(0[0-9]|1[0-9]|2[0-3]|[0-9])\:(0[0-9]|1[0-9]|2[0-9]|3[0-9]|4[0-9]|5[0-9]|[0-9])\:(0[0-9]|1[0-9]|2[0-9]|3[0-9]|4[0-9]|5[0-9]|[0-9])$', t)
		>>> m.groups()
		('19', '05', '30')
		//0[0-9] 表示00 01 02 03 04 ... 09

16.常用的内建模块
1.datetime timestamp是当前时间相对于1970年1月1日 00:00:00的秒数
2.base64 二进制编码法
  1.先找64个字符作为一个数组
  2.对二进制数据进行处理，每3个字节作为一组，3*8=24bit，分为4组，每组6位。(2^6=64)
  3.6位的二进制对应一个数，这个数对应哪个数组中的一个字母，即将一个二进制数据进行base64编码，变成了字符串。
  适用于小段内容的编码
3.hashlib 哈希算法、散列算法，把任意一个长度的数据转换为一个长度固定的数据串；常见的哈希算法：MD5 SHA1等等
这种哈希算法主要存储敏感的用户名或者密码之类的内容
4.urllib
example：from urllib import request

def  testurl():
	 with request.urlopen('https://api.douban.com/v2/book/2129650') as f:
	 	data = f.read()
	 	print('Status:',f.status,f.reason)
	 	for k,v in f.getheaders():
	 		print('%s: %s'% (k,v))
	 	print('Data',data.decode('utf-8'))

User-Agent头就是用来标识浏览器的
17.常用的第三方模块
1.Pillow PIL的3.0版本 python image library
2.request 对于访问网络资源的第三方库
3.chardet 检测编码格式
4.psutil 可以获取系统的情况
	example：
	psutil.cpu_count() //CPu逻辑数量
	psutil.cpu_count(logical = False) //CPU物理核心
	psutil.cpu_times()  //统计CPU用户/系统/空闲时间
	psutil.virtual_memory()  //物理内存
	psutil.swap_memory()     //交换内存
	psutil.disk_partitions()  //磁盘分区信息
	psutil.disk_usages('/')   //磁盘使用情况
	psutil.net_io_counters() // 获取网络读写字节／包的个数
	psutil.net_if_addrs() // 获取网络接口信息

	psutil.pids()    //所有进程ID
	p = psutil.Process(3776) //获取指定进程ID=3776，其实就是当前Python交互环境
	p.name() //进程名称
	p.exe()  //进程exe路径
	p.cwd()  // 进程工作目录
	p.cmdline() // 进程启动的命令行
	p.ppid() //父进程ID
	p.parent() // 父进程
	p.children() //子进程
	p.status() //进程状态
	p.username() //进程用户名
	p.create_time() //进程创建时间
	p.cpu_times() //进程使用的CPU时间
	p.memory_info() // 进程使用的内存
	p.open_files() // 进程打开的文件
	p.connections() // 进程相关网络连接
	p.num_threads() //进程的线程数量
	p.threads() // 所有线程信息
	p.environ() //进程环境变量
	p.terminate() //结束进程
	psutil.test()  //模拟ps命令效果
5.virtualenv可以隔离python运行环境