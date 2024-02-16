for folder in $(ls example-programs)
do
	rm example-programs/$folder/*.toks 2>/dev/null
	rm example-programs/$folder/*.input 2>/dev/null
	rm example-programs/$folder/*.ast 2>/dev/null
	for file in $(ls example-programs/$folder/*)
	do
		# echo $file
		./sclp --sa-scan --show-tokens $file
		y=$?
		cp $file.toks myout
		./ref-sclp --sa-scan --show-tokens $file
		z=$?
		if [ $y -eq $z ]
		then
			if [ $z -eq 0 ]
			then
				result=$(diff -y -W 72 -Bw myout $file.toks)
				if [ $? -ne 0 ]
				then
					echo $file 
					# echo $result
					echo LEX ERROR 1
					exit
				fi
			fi
		else
			echo $file
			# echo $result
			echo LEX ERROR 2
			exit
		fi
		# continue
		./sclp --sa-parse $file
		y=$?
		./ref-sclp --sa-parse $file
		z=$?
		if [ $z -eq 0 ]
		then
			if [ $y -ne 0 ]
			then
				echo PARSE ERROR 1
				echo $file
				exit
			fi
		else
			if [ $y -ne 0 ]
			then
				echo PARSE ERROR 2
				echo $file
				exit
			fi
		fi
		# continue
	done
done
# Tokens
# for x in $(ls example-programs/Level-1-test-cases/*.c)
# do
# 	echo $x
# 	./reference-implementations/sclp --sa-scan --show-tokens $x
# 	cp $x.toks myout
# 	./reference-implementations/A1-sclp --sa-scan --show-tokens $x
# 	diff -Bw myout $x.toks
# done
# for x in $(ls example-programs/Level-2-test-cases/*.c)
# do
# 	echo $x
# 	./reference-implementations/sclp --sa-scan --show-tokens $x
# 	cp $x.toks myout
# 	./reference-implementations/A1-sclp --sa-scan --show-tokens $x
# 	diff -Bw myout $x.toks
# done
# for x in $(ls example-programs/Level-1-invalid-test-cases/*.c)
# do
# 	echo $x
# 	./reference-implementations/sclp --sa-scan --show-tokens $x
# 	y=$?
# 	cp $x.toks myout
# 	./reference-implementations/A1-sclp --sa-scan --show-tokens $x
# 	z=$?
# 	# echo $y $z
# 	if [ $y -eq $z ]
# 	then
# 		if [ $z -eq 0 ]
# 		then
# 			diff -Bw myout $x.toks
# 		fi
# 	else
# 		echo ***ERROR***
# 	fi
# done
# for x in $(ls example-programs/Level-2-invalid-test-cases/*.c)
# do
# 	echo $x
# 	./reference-implementations/sclp --sa-scan --show-tokens $x
# 	y=$?
# 	cp $x.toks myout
# 	./reference-implementations/A1-sclp --sa-scan --show-tokens $x
# 	z=$?
# 	# echo $y $z
# 	if [ $y -eq $z ]
# 	then
# 		if [ $z -eq 0 ]
# 		then
# 			diff -Bw myout $x.toks
# 		fi
# 	else
# 		echo ***ERROR***
# 	fi
# done
# for x in $(ls my_tests/*.c)
# do
# 	echo $x
# 	./reference-implementations/sclp --sa-scan --show-tokens $x
# 	y=$?
# 	cp $x.toks myout
# 	./reference-implementations/A1-sclp --sa-scan --show-tokens $x
# 	z=$?
# 	# echo $y $z
# 	if [ $y -eq $z ]
# 	then
# 		if [ $z -eq 0 ]
# 		then
# 			diff -Bw myout $x.toks
# 		fi
# 	else
# 		echo ***ERROR***
# 	fi
# done
