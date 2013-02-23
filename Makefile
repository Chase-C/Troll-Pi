GCC			= g++ -g -O0 -Wall -Wextra
SOURCES		= TrollPi.cpp
EXECS		= TrollPi

${EXECS} : ${SOURCES}
	${GCC} $< -o $@

clean :
	- rm core

spotless : clean
	- rm ${EXECS}.exe
