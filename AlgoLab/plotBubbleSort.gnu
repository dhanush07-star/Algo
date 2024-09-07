set terminal pngcairo size 800,600
set output 'bubble_sort_plot.png'

set title "Bubble Sort Time Complexity"
set xlabel "Input Size"
set ylabel "Time (seconds)"
set grid
set logscale x
set logscale y

plot 'plotBubbledata.txt' using 1:2 with linespoints title 'Bubble Sort'
