make k k2 genk || exit 1
for ((i=1; ; i++)) do
	./genk $i > in
	./k < in > out
	./k2 < in > out2
	if(! cmp -s out out2) then
		echo "--> entrada:"
		cat in
		echo "--> saida1:"
		cat out
		echo "--> saida2:"
		cat out2
		break;
	fi
	echo $i
done
