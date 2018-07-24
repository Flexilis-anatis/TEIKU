# Gets all files that end in .h and .cpp
files="$(find . -type f | grep -vE '\./\.git|\.gch' | grep -E '\.cpp|\.h|\.hpp|\.cxx|\.cc|\.hh|\.hxx' | sort -r | sed -n -e 'H;${x;s/\n/ /g;s/^,//;p;}')"

sfml_loc=/usr/include

g++ $files -Werror -Wall -o teiku.out -L$sfml_loc -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
