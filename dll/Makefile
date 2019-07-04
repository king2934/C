#####
RM = rm -rf
all:
	gcc -Wall -shared mydll.c -o mydll.dll
	gcc main.c mydll.dll -o main.exe
clear:
	$(RM) *.exe
	