<<<<<<< HEAD
Mac OS X litecoind build instructions
====================================

Authors
-------

* Laszlo Hanyecz <solar@heliacal.net>
* Douglas Huff <dhuff@jrbobdobbs.org>
* Colin Dean <cad@cad.cx>
* Gavin Andresen <gavinandresen@gmail.com>

License
-------

Copyright (c) 2009-2012 Bitcoin Developers

Distributed under the MIT/X11 software license, see the accompanying
file COPYING or http://www.opensource.org/licenses/mit-license.php.

This product includes software developed by the OpenSSL Project for use in
the OpenSSL Toolkit (http://www.openssl.org/).

This product includes cryptographic software written by
Eric Young (eay@cryptsoft.com) and UPnP software written by Thomas Bernard.

Notes
-----

See `doc/readme-qt.rst` for instructions on building Litecoin-Qt, the
graphical user interface.

Tested on OS X 10.5 through 10.8 on Intel processors only. PPC is not
supported because it is big-endian.

All of the commands should be executed in a Terminal application. The
built-in one is located in `/Applications/Utilities`.
=======
Mac OS X Build Instructions and Notes
====================================
The commands in this guide should be executed in a Terminal application.
The built-in one is located in `/Applications/Utilities/Terminal.app`.
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36

Preparation
-----------
Install the OS X command line tools:

<<<<<<< HEAD
You need to install XCode with all the options checked so that the compiler
and everything is available in /usr not just /Developer. XCode should be
available on your OS X installation media, but if not, you can get the
current version from https://developer.apple.com/xcode/. If you install
Xcode 4.3 or later, you'll need to install its command line tools. This can
be done in `Xcode > Preferences > Downloads > Components` and generally must
be re-done or updated every time Xcode is updated.

There's an assumption that you already have `git` installed, as well. If
not, it's the path of least resistance to install [Github for Mac](https://mac.github.com/)
(OS X 10.7+) or
[Git for OS X](https://code.google.com/p/git-osx-installer/). It is also
available via Homebrew or MacPorts.

You will also need to install [Homebrew](http://mxcl.github.io/homebrew/)
or [MacPorts](https://www.macports.org/) in order to install library
dependencies. It's largely a religious decision which to choose, but, as of
December 2012, MacPorts is a little easier because you can just install the
dependencies immediately - no other work required. If you're unsure, read
the instructions through first in order to assess what you want to do.
Homebrew is a little more popular among those newer to OS X.

The installation of the actual dependencies is covered in the Instructions
sections below.

Instructions: MacPorts
----------------------

### Install dependencies

Installing the dependencies using MacPorts is very straightforward.

    sudo port install boost db48@+no_java openssl miniupnpc

### Building `litecoind`

1. Clone the github tree to get the source code and go into the directory.

        git clone git@github.com:litecoin-project/litecoin.git litecoin
        cd litecoin

2.  Build litecoind:
=======
`xcode-select --install`

When the popup appears, click `Install`.
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36

Then install [Homebrew](http://brew.sh).

Dependencies
----------------------

    brew install automake berkeley-db4 libtool boost --c++11 miniupnpc openssl pkg-config homebrew/versions/protobuf260 --c++11 qt5 libevent

NOTE: Building with Qt4 is still supported, however, could result in a broken UI. Building with Qt5 is recommended.

<<<<<<< HEAD
        brew link openssl --force

Rerunning "openssl version" should now return the correct version.

### Building `litecoind`

1. Clone the github tree to get the source code and go into the directory.

        git clone https://github.com/litecoin-project/litecoin.git
        cd litecoin
=======
Build Litecoin Core
------------------------

1. Clone the litecoin source code and cd into `litecoin`
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36

        git clone https://github.com/litecoin-project/litecoin
        cd litecoin

2.  Build litecoin-core:

    Configure and build the headless litecoin binaries as well as the GUI (if Qt is found).

<<<<<<< HEAD
3.  Build litecoind:
=======
    You can disable the GUI build by passing `--without-gui` to configure.
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36

        ./autogen.sh
        ./configure
        make

3.  It is recommended to build and run the unit tests:

        make check

4.  You can also create a .dmg that contains the .app bundle (optional):

<<<<<<< HEAD
A litecoind binary is not included in the Litecoin-Qt.app bundle. You can ignore
this section if you are building `litecoind` for your own use.

If you are building `litecond` for others, your build machine should be set up
as follows for maximum compatibility:

All dependencies should be compiled with these flags:
=======
        make deploy

Running
-------
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36

Litecoin Core is now available at `./src/litecoind`

Before running, it's recommended you create an RPC configuration file.

    echo -e "rpcuser=litecoinrpc\nrpcpassword=$(xxd -l 16 -p /dev/urandom)" > "/Users/${USER}/Library/Application Support/Litecoin/litecoin.conf"

    chmod 600 "/Users/${USER}/Library/Application Support/Litecoin/litecoin.conf"

<<<<<<< HEAD
As of December 2012, the `boost` port does not obey `macosx_deployment_target`.
Download `http://gavinandresen-bitcoin.s3.amazonaws.com/boost_macports_fix.zip`
for a fix. Some ports also seem to obey either `build_arch` or
`macosx_deployment_target`, but not both at the same time. For example, building
on an OS X 10.6 64-bit machine fails. Official release builds of Litecoin-Qt are
compiled on an OS X 10.6 32-bit machine to workaround that problem.

Once dependencies are compiled, creating `Litecoin-Qt.app` is easy:
=======
The first time you run litecoind, it will start downloading the blockchain. This process could take several hours.

You can monitor the download process by looking at the debug.log file:
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36

    tail -f $HOME/Library/Application\ Support/Litecoin/debug.log

Other commands:
-------

<<<<<<< HEAD
It's now available at `./litecoind`, provided that you are still in the `src`
directory. We have to first create the RPC configuration file, though.

Run `./litecoind` to get the filename where it should be put, or just try these
commands:

    echo -e "rpcuser=litecoinrpc\nrpcpassword=$(xxd -l 16 -p /dev/urandom)" > "/Users/${USER}/Library/Application Support/Litecoin/litecoin.conf"
    chmod 600 "/Users/${USER}/Library/Application Support/Litecoin/litecoin.conf"
=======
    ./src/litecoind -daemon # Starts the litecoin daemon.
    ./src/litecoin-cli --help # Outputs a list of command-line options.
    ./src/litecoin-cli help # Outputs a list of RPC commands when the daemon is running.

Using Qt Creator as IDE
------------------------
You can use Qt Creator as an IDE, for litecoin development.
Download and install the community edition of [Qt Creator](https://www.qt.io/download/).
Uncheck everything except Qt Creator during the installation process.

1. Make sure you installed everything through Homebrew mentioned above
2. Do a proper ./configure --enable-debug
3. In Qt Creator do "New Project" -> Import Project -> Import Existing Project
4. Enter "litecoin-qt" as project name, enter src/qt as location
5. Leave the file selection as it is
6. Confirm the "summary page"
7. In the "Projects" tab select "Manage Kits..."
8. Select the default "Desktop" kit and select "Clang (x86 64bit in /usr/bin)" as compiler
9. Select LLDB as debugger (you might need to set the path to your installation)
10. Start debugging with Qt Creator
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36

Notes
-----

* Tested on OS X 10.8 through 10.12 on 64-bit Intel processors only.

<<<<<<< HEAD
    ./litecoind --help  # for a list of command-line options.
    ./litecoind -daemon # to start the litecoin daemon.
    ./litecoind help    # When the daemon is running, to get a list of RPC commands
=======
* Building with downloaded Qt binaries is not officially supported. See the notes in [#7714](https://github.com/bitcoin/bitcoin/issues/7714)
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36
