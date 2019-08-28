The main folder for storing shell scripts that I have learnt, and the notes, the keywords and philosophy.
_execute shell commands.
_check the environment variables and status,...
_install necessary packages.
_conditional ,... check files,
_source shell variables from files.
_functions
Main program should be placed at the end of .sh file (AMCC’s practice).

---
Check if the necessary tools are installed in the OS.
---
LINUX_PACKAGE_CHECK_ARRAY=(git gcc)
for Index in ${LINUX_PACKAGE_CHECK_ARRAY[*]}
do
	which $Index > /dev/null
	if [ $? -eq 1 ] ; then
		echo "There is no $Index command. Please install it!"
		exit
	fi
done
---
Search file by name in the system, then create a file that stores the dir contains that file, and the content of that dir for each dirs
