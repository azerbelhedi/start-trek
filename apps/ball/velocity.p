set terminal png size 1000,1000
set output 'velocity.png'
set title 'ball velocity (x,y)'
set grid
plot "velocity.dat" using 1:2 title "velocity.x" with lines, \
     "velocity.dat" using 1:3 title "velocity.y" with lines
