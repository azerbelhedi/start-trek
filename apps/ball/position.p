set terminal png size 1000,1000
set output 'position.png'
set title 'x(t) and y(t)'
set grid
plot "position.dat" using 1:2 title "x(t)" with lines, \
     "position.dat" using 1:3 title "y(t)" with lines
