for file in *.cpp; do
    if [ "$file" != "template.cpp" ]; then
<<<<<<< HEAD
        g++ $file -fsanitize=address -fsanitize=undefined -Wall -Wextra;
=======
        g++ $file -std=c++17 -fsanitize=address -fsanitize=undefined -Wall -Wextra;
>>>>>>> 2d01dd1e07f98e0b026da86be388c4d1d03bf156
    fi
done
