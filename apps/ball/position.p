set terminal png size 1000,1000
set output 'position.png'
set title 'ball(x,y)'
set grid
plot "position.dat" title "xy path" with lines, \
     "position.dat" using 1:2 title "x(t)" with lines, \
     "position.dat" using 1:3 title "x(y)" with lines
