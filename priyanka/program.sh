if test $# -eq 0
	then
		echo "Not enough args"
		echo "program name : $0"
elif test $# -eq 1
	then
		echo "one arg $*"
elif test $# -eq 2
	then
		echo "two args $*"
elif test $# -eq 3
	then
		echo "3 args $*"
else
	 echo "more than 3 $*"
fi

