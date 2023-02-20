# Factorial 
read -p "Enter the number to find the factorial of: " number
fact=1
for((i=1;i<=$number;i++))
do
	fact=$((fact*i))
done
echo "The factorial of $number is $fact"

# Fibonacci
read -p "How many terms of Fibonacci Series are needed: " limit
fib=1
last=1
echo $fib
for((i=0;i<=$limit;i++))
do
	temp=$fib
	echo $fib
	fib=$(($fib+$last))
	last=$temp
done

# Basic Calculator
read -p "Enter the two numbers: " a b
read -p 'Enter the operator(1:+ 2:- 3:* 4:/)' op
if [ $op -eq 1 ];then
	echo "The Answer is: `expr $a + $b`"
elif [ $op -eq 2 ];then
        echo "The Answer is: `expr $a - $b`"
elif [ $op -eq 3 ];then
	echo "The Answer is: $(($a * $b))"
elif [ $op -eq 4 ];then
	echo "The Answer is: $(($a / $b))"
else
	echo "Invalid Operator"
fi
