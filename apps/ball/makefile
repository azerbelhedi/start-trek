compile:
	echo "***************  COMPLING  ***************"
	g++ main.cpp ../../src/*.cpp -I../../headers/*.h -o main.exe

run: compile
	echo "***************  RUNNING  ***************"
	./main.exe

plot:
	gnuplot output.p

clean:
	rm main.exe position.dat position.png || clear
	clear