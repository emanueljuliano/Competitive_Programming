make machine_works brute_machine gen_machine || exit 1
for ((i = 1; ; i++)) do
	./gen_machine $i > in
	./machine_works < in > out
	./brute_machine < in > out2
	if (! cmp -s out out2) then
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
