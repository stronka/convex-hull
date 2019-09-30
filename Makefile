CTESTIE_DIR=../CTestie/src/include

CC=g++
TEST_FLAGS=
TEST_DEST=bin

INCLUDE=include

help:
	@echo Help

unit:
	test_geometry
	test_gift_wrapping

test_geometry:
	$(CC) test/geometry/test_geometry.cpp -o $(TEST_DEST)/test_geometry \
	-I$(INCLUDE) -I$(CTESTIE_DIR) $(TEST_FLAGS)	
	$(TEST_DEST)/test_geometry

test_vector:
	$(CC) test/geometry/test_vector.cpp src/geometry/geometry.cpp\
	-o $(TEST_DEST)/test_vector \
	-I$(INCLUDE) -I$(CTESTIE_DIR) $(TEST_FLAGS)	
	$(TEST_DEST)/test_vector

test_gift_wrapping:
	$(CC) test/algorithm/test_gift_wrapping.cpp src/geometry/geometry.cpp src/geometry/vector.cpp \
	-o $(TEST_DEST)/test_gift_wrapping \
	-I$(INCLUDE) -I$(CTESTIE_DIR) $(TEST_FLAGS)	
	$(TEST_DEST)/test_gift_wrapping
