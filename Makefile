all: exec.exe

exec.exe:
	@g++ src/art.cpp -o exec -std=c++14 -O3 -static -fopenmp

render:
	@./exec descricaoCena.txt
