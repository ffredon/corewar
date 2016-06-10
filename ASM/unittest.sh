#clean all
folder="../resources/champions/"
rm "$folder"**/*.mor
rm "$folder"**/*.cor

#compil all .cor from standard asm
for f in $folder**/*.s
do
	../resources/asm "$f"
done
#compil all .mor from group asm
./asm -u "$folder"**/*.s

#unit test
for f in $folder**/*.mor
do
	echo ${f%.*}.cor
	diff <(xxd $f) <(xxd ${f%.*}.cor) | wc
done
