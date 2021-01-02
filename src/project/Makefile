file:main.c
	gcc main.c -o file -g -Wall
file_cpp:main.c
	g++ main.c -o file_cpp -g -Wall
file.exe:main.c
	x86_64-w64-mingw32-gcc main.c -o file.exe -g -Wall
file_cpp.exe:main.c
	x86_64-w64-mingw32-g++ main.c -o file_cpp.exe -g -Wall

.PHONY: win
win: file.exe file_cpp.exe

.PHONY:all
all: file file_cpp win

.PHONY:delete
delete:
	rm -f file
	rm -f file_cpp
	rm -f file.exe
	rm -f file_cpp.exe

.PHONY:clean
clean:
	rm -f maleList.txt
	rm -f femaleList.txt
	rm -f byAge.txt
	rm -rf nameList.txt
