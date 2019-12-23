#arguments amount check
if [ $# -ne 3 ]
then
echo three arguments required
exit
fi
#Addition
if [ $2 = '+' ]
then
res=num=$(($1 + $3))
#Subtraction
elif [ $2 = '-' ]
then
res=num=$(($1 - $3))
#Multiplication
elif [ $2 = 'x' ]
then
res=num=$(($1 * $3))
#Division
elif [ $2 = '/' ]
then
if [ $3 -eq 0 ]
then
echo "you cannot divide any number with 0"
exit
fi
res=num=$(($1 / $3))
#incorrect argument values
else
echo "arguments are incorrect"
exit
fi
#result
echo "Result : $res"