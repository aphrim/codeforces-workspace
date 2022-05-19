for file in *.cpp; do
    if [ "$file" != "template.cpp" ]; then
        g++ $file -fsanitize=address -fsanitize=undefined -Wall -Wextra;
    fi
done
