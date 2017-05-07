<<<<<<< HEAD
Litecoin 0.8.x BETA
====================

Copyright (c) 2009-2014 Bitcoin Developers
Copyright (c) 2011-2014 Litecoin Developers
=======
Litecoin Core 0.13.2
=====================

Setup
---------------------
[Litecoin Core](http://litecoin.org/en/download) is the original Litecoin client and it builds the backbone of the network. However, it downloads and stores the entire history of Litecoin transactions (which is currently several GBs); depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to a day or more.
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36

Running
---------------------
The following are some helpful notes on how to run Litecoin on your native platform.

### Unix

<<<<<<< HEAD
Intro
---------------------
Litecoin is a free open source peer-to-peer electronic cash system that is
completely decentralized, without the need for a central server or trusted
parties.  Users hold the crypto keys to their own money and transact directly
with each other, with the help of a P2P network to check for double-spending.
=======
Unpack the files into a directory and run:
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36

- `bin/litecoin-qt` (GUI) or
- `bin/litecoind` (headless)

<<<<<<< HEAD
Setup
---------------------
You need the Qt4 run-time libraries to run Litecoin-Qt. On Debian or Ubuntu:
	`sudo apt-get install libqtgui4`
=======
### Windows
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36

Unpack the files into a directory, and then run litecoin-qt.exe.

<<<<<<< HEAD
- bin/32/litecoin-qt (GUI, 32-bit)
- bin/32/litecoind (headless, 32-bit)
- bin/64/litecoin-qt (GUI, 64-bit)
- bin/64/litecoind (headless, 64-bit)

See the documentation at the [Litecoin Wiki](http://litecoin.info)
for help and more information.
=======
### OS X

Drag Litecoin-Core to your applications folder, and then run Litecoin-Core.
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36

### Need Help?

* See the documentation at the [Litecoin Wiki](https://litecoin.info/)
for help and more information.
* Ask for help on [#litecoin](http://webchat.freenode.net?channels=litecoin) on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net?channels=litecoin).
* Ask for help on the [LitecoinTalk](https://litecointalk.io/) forums.

Building
---------------------
The following are developer notes on how to build Litecoin on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [OS X Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-windows.md)
- [OpenBSD Build Notes](build-openbsd.md)
- [Gitian Building Guide](gitian-building.md)

Development
---------------------
The Litecoin repo's [root README](/README.md) contains relevant information on the development process and automated testing.

- [Developer Notes](developer-notes.md)
- [Multiwallet Qt Development](multiwallet-qt.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- [Source Code Documentation (External Link)](https://dev.visucore.com/bitcoin/doxygen/)
- [Translation Process](translation_process.md)
- [Translation Strings Policy](translation_strings_policy.md)
- [Unit Tests](unit-tests.md)
<<<<<<< HEAD
- [Translation Process](translation_process.md)
=======
- [Unauthenticated REST Interface](REST-interface.md)
- [Shared Libraries](shared-libraries.md)
- [BIPS](bips.md)
- [Dnsseed Policy](dnsseed-policy.md)
- [Benchmarking](benchmarking.md)

### Resources
* Discuss on the [LitecoinTalk](https://litecointalk.io/) forums.
* Discuss project-specific development on #litecoin on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net/?channels=litecoin).

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [Files](files.md)
- [Tor Support](tor.md)
- [Init Scripts (systemd/upstart/openrc)](init.md)

License
---------------------
Distributed under the [MIT software license](http://www.opensource.org/licenses/mit-license.php).
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](https://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36
