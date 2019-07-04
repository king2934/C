# C语言 编译动态dll库

##### 1.编译动态dll库

	gcc -Wall -shared mydll.c -o mydll.dll
	或者
	gcc --share mydll.c -o mydll.dll
	
##### 2.调用dll库生成exe文件

	gcc main.c mydll.dll -o main.exe