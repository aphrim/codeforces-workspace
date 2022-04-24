for file in *.cpp; do
    if [ "$file" != "template.cpp" ]; then
        g++ $file -std=c++20 -fsanitize=address -fsanitize=undefined -Wall -Wextra;
    fi
done
