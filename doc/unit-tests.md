<<<<<<< HEAD
Compiling/running litecoind unit tests
------------------------------------

litecoind unit tests are in the `src/test/` directory; they
use the Boost::Test unit-testing framework.
=======
Compiling/running unit tests
------------------------------------

Unit tests will be automatically compiled if dependencies were met in `./configure`
and tests weren't explicitly disabled.
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36

After configuring, they can be run with `make check`.

<<<<<<< HEAD
	cd src
	make -f makefile.unix test_litecoin  # Replace makefile.unix if you're not on unix
	./test_litecoin   # Runs the unit tests
=======
To run the litecoind tests manually, launch `src/test/test_litecoin`.
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36

To add more litecoind tests, add `BOOST_AUTO_TEST_CASE` functions to the existing
.cpp files in the `test/` directory or add new .cpp files that
implement new BOOST_AUTO_TEST_SUITE sections.

<<<<<<< HEAD
To add more tests, add `BOOST_AUTO_TEST_CASE` functions to the existing
.cpp files in the test/ directory or add new .cpp files that
implement new BOOST_AUTO_TEST_SUITE sections (the makefiles are
set up to add test/*.cpp to test_litecoin automatically).


Compiling/running Litecoin-Qt unit tests
---------------------------------------

Bitcoin-Qt unit tests are in the src/qt/test/ directory; they
use the Qt unit-testing framework.

To compile and run the tests:

	qmake bitcoin-qt.pro BITCOIN_QT_TEST=1
	make
	./litecoin-qt_test

To add more tests, add them to the `src/qt/test/` directory,
the `src/qt/test/test_main.cpp` file, and bitcoin-qt.pro.
=======
To run the litecoin-qt tests manually, launch `src/qt/test/test_litecoin-qt`

To add more litecoin-qt tests, add them to the `src/qt/test/` directory and
the `src/qt/test/test_main.cpp` file.
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36
