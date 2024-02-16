# Tokens
for x in $(ls example-programs/Level-1-test-cases/*.c)
do
	echo $x
	./reference-implementations/sclp $x
	y=$?
	./reference-implementations/A1-sclp $x
	z=$?
	echo $y $z
done
for x in $(ls example-programs/Level-2-test-cases/*.c)
do
	echo $x
	./reference-implementations/sclp $x
	y=$?
	./reference-implementations/A1-sclp $x
	z=$?
	echo $y $z
done
for x in $(ls example-programs/Level-1-invalid-test-cases/*.c)
do
	echo $x
	./reference-implementations/sclp $x
	y=$?
	./reference-implementations/A1-sclp $x
	z=$?
	echo $y $z
done
for x in $(ls example-programs/Level-2-invalid-test-cases/*.c)
do
	echo $x
	./reference-implementations/sclp $x
	y=$?
	./reference-implementations/A1-sclp $x
	z=$?
	echo $y $z
done
