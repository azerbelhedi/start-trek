all:
	make run && make plot
	
compile: 
	cd apps/ball && make compile

run:
	cd apps/ball && make run

plot:
	cd apps/ball && make plot

clean:
	cd apps/ball && make clean
	clear
