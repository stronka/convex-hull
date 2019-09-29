CTESTIE_DIR=../CTestie/src/include
CC=g++
TEST_FLAGS=
TEST_DEST=bin

test_point:
	$(CC) test/test_point.cpp -o $(TEST_DEST)/test_point \
	-I$(CTESTIE_DIR) $(TEST_FLAGS)	
	$(TEST_DEST)/test_point
