set terminal png size 1000,1000
set output 'force.png'
set title 'ball force (x,y)'
set grid
plot "force.dat" using 1:2 title "force.x" with line, \
     "force.dat" using 1:3 title "force.y" with lines
