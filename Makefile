CTESTIE_DIR=../CTestie/src/include

CC=g++
TEST_FLAGS=
TEST_DEST=bin

INCLUDE=include

help:
	@echo Help

%.o : %.cpp
	$(CC) $(TEST_FLAGS) -I$(INCLUDE) -I$(CTESTIE_DIR) -c $< -o $@ 

test_point: test/geometry/test_point.o
	$(CC) test/geometry/test_point.o -o $(TEST_DEST)/test_point \
	$(TEST_FLAGS)	
	$(TEST_DEST)/test_point


test_point_collection: test/geometry/test_point_collection.o src/geometry/point.o
	$(CC) test/geometry/test_point_collection.o src/geometry/point.o \
	-o $(TEST_DEST)/test_point_collection \
	$(TEST_FLAGS)	
	$(TEST_DEST)/test_point_collection

test_vector: test/geometry/test_vector.o src/geometry/point.o
	$(CC) test/geometry/test_vector.o src/geometry/point.o \
	-o $(TEST_DEST)/test_vector \
	$(TEST_FLAGS)	
	$(TEST_DEST)/test_vector

test_gift_wrapping: test/algorithm/test_gift_wrapping.o src/geometry/point.o src/geometry/vector.o src/geometry/point_collection.o
	$(CC) test/algorithm/test_gift_wrapping.o src/geometry/point.o src/geometry/vector.o src/geometry/point_collection.o \
	-o $(TEST_DEST)/test_gift_wrapping \
	$(TEST_FLAGS)	
	$(TEST_DEST)/test_gift_wrapping

test_graham_scan: test/algorithm/test_graham_scan.o src/geometry/point.o src/geometry/vector.o src/geometry/point_collection.o
	$(CC) test/algorithm/test_graham_scan.o src/geometry/point.o src/geometry/vector.o src/geometry/point_collection.o \
	-o $(TEST_DEST)/test_graham_scan \
	$(TEST_FLAGS)
	$(TEST_DEST)/test_graham_scan

unit:
	make test_point
	make test_point_collection
	make test_vector
	make test_gift_wrapping
	
clean:
	rm -f *.o
	rm -f */*.o
	rm -f */*/*.o
