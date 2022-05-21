compile:
	echo "***************  COMPLING  ***************"
	g++ main.cpp ../../src/*.cpp -I../../headers/*.h -o main.exe

run: compile
	echo "***************  RUNNING  ***************"
	./main.exe

plot:
	gnuplot path.p
	gnuplot position.p
	gnuplot velocity.p  
	gnuplot acceleration.p
	gnuplot force.p
	gthumb position.png velocity.png acceleration.png force.png path.png &

clean:
	rm main.exe position.dat position.png velocity.dat velocity.png acceleration.dat acceleration.png force.dat force.png path.png && clear
	clear