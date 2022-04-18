for file in *.cpp; do
    if [ "$file" != "template.cpp" ]; then
        g++ $file;
    fi
done
