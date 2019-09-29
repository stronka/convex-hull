CTESTIE_DIR=../CTestie/src/include

CC=g++
TEST_FLAGS=
TEST_DEST=bin

INCLUDE=include

help:
	@echo Help

unit:
	test_point

test_point:
	$(CC) test/test_point.cpp -o $(TEST_DEST)/test_point \
	-I$(INCLUDE) -I$(CTESTIE_DIR) $(TEST_FLAGS)	
	$(TEST_DEST)/test_point
