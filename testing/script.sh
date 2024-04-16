cp ../project/sclp .
for folder in $(ls example-programs)
do
	rm example-programs/$folder/*.toks 2>/dev/null
	rm example-programs/$folder/*.input 2>/dev/null
	rm example-programs/$folder/*.ast 2>/dev/null
	rm example-programs/$folder/*.tac 2>/dev/null
	rm example-programs/$folder/*.rtl 2>/dev/null
	rm example-programs/$folder/*.spim 2>/dev/null
	for file in $(ls example-programs/$folder/*.c)
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
		echo $y $z $file
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
		./sclp --sa-ast --show-ast $file
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

		./sclp --sa-tac --show-tac $file
		y=$?
		mv $file.tac myout
		./ref-sclp --sa-tac --show-tac $file
		z=$?
		if [ $y -eq $z ]
		then
			if [ $z -eq 0 ]
			then
				result=$(diff -y -W 72 -Bw myout $file.tac)
				if [ $? -ne 0 ]
				then
					echo $file 
					# echo $result
					echo TAC ERROR 1
					exit
				fi
			fi
		else
			if [ $y -eq 0 ]
			then
				echo $file
				# echo $result
				echo TAC ERROR 2
				exit
			fi
			if [ $z -eq 0 ]
			then
				echo $file
				# echo $result
				echo TAC ERROR 2
				exit
			fi
		fi

		./sclp --show-rtl $file
		y=$?
		mv $file.rtl myout
		./ref-sclp --sa-rtl -s --show-rtl $file
		z=$?
		if [ $y -eq $z ]
		then
			if [ $z -eq 0 ]
			then
				result=$(diff -y -W 72 -Bw myout $file.rtl)
				if [ $? -ne 0 ]
				then
					echo $file 
					# echo $result
					echo RTL ERROR 1
					exit
				fi
			fi
		else
			if [ $y -eq 0 ]
			then
				echo $file
				# echo $result
				echo RTL ERROR 2
				exit
			fi
			if [ $z -eq 0 ]
			then
				echo $file
				# echo $result
				echo RTL ERROR 2
				exit
			fi
		fi

		./sclp $file
		y=$?
		mv $file.spim myout
		./ref-sclp -s $file
		z=$?
		if [ $y -eq $z ]
		then
			if [ $z -eq 0 ]
			then
				result=$(diff -y -W 72 -Bw myout $file.spim)
				if [ $? -ne 0 ]
				then
					echo $file 
					# echo $result
					echo ASM ERROR 1
					exit
				fi
			fi
		else
			if [ $y -eq 0 ]
			then
				echo $file
				# echo $result
				echo ASM ERROR 2
				exit
			fi
			if [ $z -eq 0 ]
			then
				echo $file
				# echo $result
				echo ASM ERROR 2
				exit
			fi
		fi
	done
	rm example-programs/$folder/*.toks 2>/dev/null
	rm example-programs/$folder/*.input 2>/dev/null
	rm example-programs/$folder/*.ast 2>/dev/null
	rm example-programs/$folder/*.tac 2>/dev/null
	rm example-programs/$folder/*.rtl 2>/dev/null
	rm example-programs/$folder/*.spim 2>/dev/null
done
