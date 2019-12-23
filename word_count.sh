#arguments amount check
if [ $# -ne 2 ]
then
echo "two arguments required"
exit
fi
word_count=`grep -wc '$1' $2`
echo "the word you typed used $word_count times in the text"
