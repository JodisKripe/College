read a b
echo "The sum of the two numbers is $((a+b))"


read rad
echo "The area of the circle is:"
echo "3.141 * $rad * $rad " | bc

read x y
echo "The value of x: $x , and y: $y"
temp=$x
x=$y
y=$temp
echo "The new value of x: $x, and y: $y"

x=$(($x+$y))
y=$(($x-$y))
x=$(($x-$y))
echo "The original values of x: $x, and y: $y"
