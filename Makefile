CTESTIE_DIR=../CTestie/src/include

CC=g++
TEST_FLAGS=
TEST_DEST=bin

INCLUDE=include

help:
	@echo Help

test_point:
	$(CC) test/geometry/test_point.cpp -o $(TEST_DEST)/test_point \
	-I$(INCLUDE) -I$(CTESTIE_DIR) $(TEST_FLAGS)	
	$(TEST_DEST)/test_point


test_point_collection:
	$(CC) test/geometry/test_point_collection.cpp src/geometry/point.cpp \
	-o $(TEST_DEST)/test_point_collection \
	-I$(INCLUDE) -I$(CTESTIE_DIR) $(TEST_FLAGS)	
	$(TEST_DEST)/test_point_collection


test_vector:
	$(CC) test/geometry/test_vector.cpp src/geometry/point.cpp \
	-o $(TEST_DEST)/test_vector \
	-I$(INCLUDE) -I$(CTESTIE_DIR) $(TEST_FLAGS)	
	$(TEST_DEST)/test_vector

test_gift_wrapping:
	$(CC) test/algorithm/test_gift_wrapping.cpp src/geometry/point.cpp src/geometry/vector.cpp \
	-o $(TEST_DEST)/test_gift_wrapping \
	-I$(INCLUDE) -I$(CTESTIE_DIR) $(TEST_FLAGS)	
	$(TEST_DEST)/test_gift_wrapping

unit:
	make test_point
	make test_point_collection
	make test_vector
	make test_gift_wrapping
	