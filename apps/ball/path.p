set terminal png size 1000, 1000
set output "path.png"
set title "ball path(x,y)"
set grid
plot "position.dat" using 2:3 title "path(x,y)" with lines