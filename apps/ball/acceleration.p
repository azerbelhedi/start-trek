set terminal png size 1000,1000
set output 'acceleration.png'
set title 'ball acceleration (x,y)'
set grid
plot "acceleration.dat" using 1:2 title "acceleration.x" with lines, \
     "acceleration.dat" using 1:3 title "acceleration.y" with lines
