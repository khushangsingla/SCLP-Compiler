cp ../project/sclp .
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
			if [ $y -eq 0 ]
			then
				echo PARSE ERROR 2
				echo $file
				exit
			fi
		fi
		# continue
		# echo ./sclp --show-ast $file
		./sclp --show-ast $file
		y=$?
		mv $file.ast myout
		./ref-sclp --sa-ast --show-ast $file
		z=$?
		if [ $y -eq $z ]
		then
			if [ $z -eq 0 ]
			then
				result=$(diff -y -W 72 -Bw myout $file.ast)
				if [ $? -ne 0 ]
				then
					echo $file 
					# echo $result
					echo AST ERROR 1
					exit
				fi
			fi
		else
			if [ $y -eq 0 ]
			then
				echo $file
				# echo $result
				echo AST ERROR 2
				exit
			fi
			if [ $z -eq 0 ]
			then
				echo $file
				# echo $result
				echo AST ERROR 2
				exit
			fi
		fi
	done
done
