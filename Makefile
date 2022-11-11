build:
	g++ -std=c++17 -Werror -Wuninitialized -o build_proj Project2.cpp

run: 
	g++ -std=c++17 -Werror -Wuninitialized -o build_proj Project2.cpp && ./build_proj

test:
	g++ -std=c++17 -Werror -Wuninitialized -o test_proj test.cpp -DUNIT_TESTING && ./test_proj

clean:
	rm build_proj
	rm test_proj