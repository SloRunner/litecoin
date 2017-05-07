Release Process
====================

<<<<<<< HEAD
* * *
=======
Before every release candidate:

* Update translations (ping wumpus on IRC) see [translation_process.md](https://github.com/bitcoin/bitcoin/blob/master/doc/translation_process.md#synchronising-translations).
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36

Before every minor and major release:

* Update [bips.md](bips.md) to account for changes since the last release.
* Update version in sources (see below)
* Write release notes (see below)
* Update `src/chainparams.cpp` nMinimumChainWork with information from the getblockchaininfo rpc.

Before every major release:

* Update hardcoded [seeds](/contrib/seeds/README.md), see [this pull request](https://github.com/bitcoin/bitcoin/pull/7415) for an example.

<<<<<<< HEAD
	git tag -s v0.8.7
=======
### First time / New builders
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36

Check out the source code in the following directory hierarchy.

    cd /path/to/your/toplevel/build
    git clone https://github.com/litecoin-project/gitian.sigs.ltc.git
    git clone https://github.com/litecoin-project/litecoin-detached-sigs.git
    git clone https://github.com/devrandom/gitian-builder.git
    git clone https://github.com/litecoin-project/litecoin.git

### Litecoin maintainers/release engineers, update version in sources

Update the following:

<<<<<<< HEAD
 From a directory containing the litecoin source, gitian-builder and gitian.sigs
  
	export SIGNER=(your gitian key, ie bluematt, sipa, etc)
	export VERSION=0.8.7
	cd ./gitian-builder
=======
- `configure.ac`:
    - `_CLIENT_VERSION_MAJOR`
    - `_CLIENT_VERSION_MINOR`
    - `_CLIENT_VERSION_REVISION`
    - Don't forget to set `_CLIENT_VERSION_IS_RELEASE` to `true`
- `src/clientversion.h`: (this mirrors `configure.ac` - see issue #3539)
    - `CLIENT_VERSION_MAJOR`
    - `CLIENT_VERSION_MINOR`
    - `CLIENT_VERSION_REVISION`
    - Don't forget to set `CLIENT_VERSION_IS_RELEASE` to `true`
- `doc/README.md` and `doc/README_windows.txt`
- `doc/Doxyfile`: `PROJECT_NUMBER` contains the full version
- `contrib/gitian-descriptors/*.yml`: usually one'd want to do this on master after branching off the release - but be sure to at least do it before a new major release
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36

Write release notes. git shortlog helps a lot, for example:

<<<<<<< HEAD
	mkdir -p inputs; cd inputs/
	wget 'http://miniupnp.free.fr/files/download.php?file=miniupnpc-1.9.20140401.tar.gz' -O miniupnpc-1.9.20140401.tar.gz'
	wget 'http://www.openssl.org/source/openssl-1.0.1h.tar.gz'
	wget 'http://download.oracle.com/berkeley-db/db-4.8.30.NC.tar.gz'
	wget 'http://zlib.net/zlib-1.2.8.tar.gz'
	wget 'ftp://ftp.simplesystems.org/pub/libpng/png/src/history/libpng16/libpng-1.6.8.tar.gz'
	wget 'http://fukuchi.org/works/qrencode/qrencode-3.4.3.tar.bz2'
	wget 'http://downloads.sourceforge.net/project/boost/boost/1.55.0/boost_1_55_0.tar.bz2'
	wget 'http://download.qt-project.org/official_releases/qt/4.8/4.8.5/qt-everywhere-opensource-src-4.8.5.tar.gz'
	cd ..
	./bin/gbuild ../litecoin/contrib/gitian-descriptors/boost-win32.yml
	mv build/out/boost-*.zip inputs/
	./bin/gbuild ../litecoin/contrib/gitian-descriptors/deps-win32.yml
	mv build/out/bitcoin*.zip inputs/
	./bin/gbuild ../litecoin/contrib/gitian-descriptors/qt-win32.yml
	mv build/out/qt*.zip inputs/

 Build litecoind and litecoin-qt on Linux32, Linux64, and Win32:
  
	./bin/gbuild --commit litecoin=v${VERSION} ../litecoin/contrib/gitian-descriptors/gitian.yml
	./bin/gsign --signer $SIGNER --release ${VERSION} --destination ../gitian.sigs/ ../litecoin/contrib/gitian-descriptors/gitian.yml
	pushd build/out
	zip -r litecoin-${VERSION}-linux.zip *
	mv litecoin-${VERSION}-linux.zip ../../
	popd
	./bin/gbuild --commit litecoin=v${VERSION} ../litecoin/contrib/gitian-descriptors/gitian-win32.yml
	./bin/gsign --signer $SIGNER --release ${VERSION}-win32 --destination ../gitian.sigs/ ../litecoin/contrib/gitian-descriptors/gitian-win32.yml
	pushd build/out
	zip -r litecoin-${VERSION}-win32.zip *
	mv litecoin-${VERSION}-win32.zip ../../
	popd
=======
    git shortlog --no-merges v(current version, e.g. 0.7.2)..v(new version, e.g. 0.8.0)

(or ping @wumpus on IRC, he has specific tooling to generate the list of merged pulls
and sort them into categories based on labels)
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36

Generate list of authors:

<<<<<<< HEAD
  1. linux 32-bit and 64-bit binaries + source (litecoin-${VERSION}-linux-gitian.zip)
  2. windows 32-bit binary, installer + source (litecoin-${VERSION}-win32-gitian.zip)
  3. Gitian signatures (in gitian.sigs/${VERSION}[-win32]/(your gitian key)/
=======
    git log --format='%aN' "$*" | sort -ui | sed -e 's/^/- /'
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36

Tag version (or release candidate) in git

    git tag -s v(new version, e.g. 0.8.0)

<<<<<<< HEAD
	unzip litecoin-${VERSION}-linux-gitian.zip -d litecoin-${VERSION}-linux
	tar czvf litecoin-${VERSION}-linux.tar.gz litecoin-${VERSION}-linux
	rm -rf litecoin-${VERSION}-linux
=======
### Setup and perform Gitian builds
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36

Setup Gitian descriptors:

<<<<<<< HEAD
	unzip litecoin-${VERSION}-win32-gitian.zip -d litecoin-${VERSION}-win32
	mv litecoin-${VERSION}-win32/litecoin-*-setup.exe .
	zip -r litecoin-${VERSION}-win32.zip bitcoin-${VERSION}-win32
	rm -rf litecoin-${VERSION}-win32
=======
    pushd ./litecoin
    export SIGNER=(your Gitian key, ie bluematt, sipa, etc)
    export VERSION=(new version, e.g. 0.8.0)
    git fetch
    git checkout v${VERSION}
    popd
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36

Ensure your gitian.sigs.ltc are up-to-date if you wish to gverify your builds against other Gitian signatures.

<<<<<<< HEAD
  OSX binaries are created on a dedicated 32-bit, OSX 10.6.8 machine.
  Litecoin 0.8.x is built with MacPorts.  0.9.x will be Homebrew only.

	qmake RELEASE=1 USE_UPNP=1 USE_QRCODE=1
	make
	export QTDIR=/opt/local/share/qt4  # needed to find translations/qt_*.qm files
	T=$(contrib/qt_translations.py $QTDIR/translations src/qt/locale)
	python2.7 share/qt/clean_mac_info_plist.py
	python2.7 contrib/macdeploy/macdeployqtplus Litecoin-Qt.app -add-qt-tr $T -dmg -fancy contrib/macdeploy/fancy.plist

 Build output expected: Litecoin-Qt.dmg
=======
    pushd ./gitian.sigs.ltc
    git pull
    popd

Ensure gitian-builder is up-to-date:

    pushd ./gitian-builder
    git pull
    popd
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36

### Fetch and create inputs: (first time, or when dependency versions change)

    pushd ./gitian-builder
    mkdir -p inputs
    wget -P inputs https://bitcoincore.org/cfields/osslsigncode-Backports-to-1.7.1.patch
    wget -P inputs http://downloads.sourceforge.net/project/osslsigncode/osslsigncode/osslsigncode-1.7.1.tar.gz
    popd

<<<<<<< HEAD
* update litecoin.org version
  make sure all OS download links go to the right versions

* update forum version

* update wiki download links

Commit your signature to gitian.sigs:

	pushd gitian.sigs
	git add ${VERSION}/${SIGNER}
	git add ${VERSION}-win32/${SIGNER}
	git commit -a
	git push  # Assuming you can push to the gitian.sigs tree
	popd

=======
Create the OS X SDK tarball, see the [OS X readme](README_osx.md) for details, and copy it into the inputs directory.

### Optional: Seed the Gitian sources cache and offline git repositories

By default, Gitian will fetch source files as needed. To cache them ahead of time:

    pushd ./gitian-builder
    make -C ../litecoin/depends download SOURCES_PATH=`pwd`/cache/common
    popd

Only missing files will be fetched, so this is safe to re-run for each build.

NOTE: Offline builds must use the --url flag to ensure Gitian fetches only from local URLs. For example:

    pushd ./gitian-builder
    ./bin/gbuild --url litecoin=/path/to/litecoin,signature=/path/to/sigs {rest of arguments}
    popd

The gbuild invocations below <b>DO NOT DO THIS</b> by default.

### Build and sign Litecoin Core for Linux, Windows, and OS X:

    pushd ./gitian-builder
    ./bin/gbuild --memory 3000 --commit litecoin=v${VERSION} ../litecoin/contrib/gitian-descriptors/gitian-linux.yml
    ./bin/gsign --signer $SIGNER --release ${VERSION}-linux --destination ../gitian.sigs.ltc/ ../litecoin/contrib/gitian-descriptors/gitian-linux.yml
    mv build/out/litecoin-*.tar.gz build/out/src/litecoin-*.tar.gz ../

    ./bin/gbuild --memory 3000 --commit litecoin=v${VERSION} ../litecoin/contrib/gitian-descriptors/gitian-win.yml
    ./bin/gsign --signer $SIGNER --release ${VERSION}-win-unsigned --destination ../gitian.sigs.ltc/ ../litecoin/contrib/gitian-descriptors/gitian-win.yml
    mv build/out/litecoin-*-win-unsigned.tar.gz inputs/litecoin-win-unsigned.tar.gz
    mv build/out/litecoin-*.zip build/out/litecoin-*.exe ../

    ./bin/gbuild --memory 3000 --commit litecoin=v${VERSION} ../litecoin/contrib/gitian-descriptors/gitian-osx.yml
    ./bin/gsign --signer $SIGNER --release ${VERSION}-osx-unsigned --destination ../gitian.sigs.ltc/ ../litecoin/contrib/gitian-descriptors/gitian-osx.yml
    mv build/out/litecoin-*-osx-unsigned.tar.gz inputs/litecoin-osx-unsigned.tar.gz
    mv build/out/litecoin-*.tar.gz build/out/litecoin-*.dmg ../
    popd

Build output expected:

  1. source tarball (`litecoin-${VERSION}.tar.gz`)
  2. linux 32-bit and 64-bit dist tarballs (`litecoin-${VERSION}-linux[32|64].tar.gz`)
  3. windows 32-bit and 64-bit unsigned installers and dist zips (`litecoin-${VERSION}-win[32|64]-setup-unsigned.exe`, `litecoin-${VERSION}-win[32|64].zip`)
  4. OS X unsigned installer and dist tarball (`litecoin-${VERSION}-osx-unsigned.dmg`, `litecoin-${VERSION}-osx64.tar.gz`)
  5. Gitian signatures (in `gitian.sigs.ltc/${VERSION}-<linux|{win,osx}-unsigned>/(your Gitian key)/`)

### Verify other gitian builders signatures to your own. (Optional)

Add other gitian builders keys to your gpg keyring

    gpg --import litecoin/contrib/gitian-keys/*.pgp

Verify the signatures

    pushd ./gitian-builder
    ./bin/gverify -v -d ../gitian.sigs.ltc/ -r ${VERSION}-linux ../litecoin/contrib/gitian-descriptors/gitian-linux.yml
    ./bin/gverify -v -d ../gitian.sigs.ltc/ -r ${VERSION}-win-unsigned ../litecoin/contrib/gitian-descriptors/gitian-win.yml
    ./bin/gverify -v -d ../gitian.sigs.ltc/ -r ${VERSION}-osx-unsigned ../litecoin/contrib/gitian-descriptors/gitian-osx.yml
    popd

### Next steps:

Commit your signature to gitian.sigs.ltc:

    pushd gitian.sigs.ltc
    git add ${VERSION}-linux/${SIGNER}
    git add ${VERSION}-win-unsigned/${SIGNER}
    git add ${VERSION}-osx-unsigned/${SIGNER}
    git commit -a
    git push  # Assuming you can push to the gitian.sigs.ltc tree
    popd

Wait for Windows/OS X detached signatures:

- Once the Windows/OS X builds each have 3 matching signatures, they will be signed with their respective release keys.
- Detached signatures will then be committed to the [litecoin-detached-sigs](https://github.com/litecoin-project/litecoin-detached-sigs) repository, which can be combined with the unsigned apps to create signed binaries.

Create (and optionally verify) the signed OS X binary:

    pushd ./gitian-builder
    ./bin/gbuild -i --commit signature=v${VERSION} ../litecoin/contrib/gitian-descriptors/gitian-osx-signer.yml
    ./bin/gsign --signer $SIGNER --release ${VERSION}-osx-signed --destination ../gitian.sigs.ltc/ ../litecoin/contrib/gitian-descriptors/gitian-osx-signer.yml
    ./bin/gverify -v -d ../gitian.sigs.ltc/ -r ${VERSION}-osx-signed ../litecoin/contrib/gitian-descriptors/gitian-osx-signer.yml
    mv build/out/litecoin-osx-signed.dmg ../litecoin-${VERSION}-osx.dmg
    popd

Create (and optionally verify) the signed Windows binaries:

    pushd ./gitian-builder
    ./bin/gbuild -i --commit signature=v${VERSION} ../litecoin/contrib/gitian-descriptors/gitian-win-signer.yml
    ./bin/gsign --signer $SIGNER --release ${VERSION}-win-signed --destination ../gitian.sigs.ltc/ ../litecoin/contrib/gitian-descriptors/gitian-win-signer.yml
    ./bin/gverify -v -d ../gitian.sigs.ltc/ -r ${VERSION}-win-signed ../litecoin/contrib/gitian-descriptors/gitian-win-signer.yml
    mv build/out/litecoin-*win64-setup.exe ../litecoin-${VERSION}-win64-setup.exe
    mv build/out/litecoin-*win32-setup.exe ../litecoin-${VERSION}-win32-setup.exe
    popd

Commit your signature for the signed OS X/Windows binaries:

    pushd gitian.sigs.ltc
    git add ${VERSION}-osx-signed/${SIGNER}
    git add ${VERSION}-win-signed/${SIGNER}
    git commit -a
    git push  # Assuming you can push to the gitian.sigs.ltc tree
    popd

### After 3 or more people have gitian-built and their results match:

- Create `SHA256SUMS.asc` for the builds, and GPG-sign it:

```bash
sha256sum * > SHA256SUMS
```

The list of files should be:
```
litecoin-${VERSION}-aarch64-linux-gnu.tar.gz
litecoin-${VERSION}-arm-linux-gnueabihf.tar.gz
litecoin-${VERSION}-i686-pc-linux-gnu.tar.gz
litecoin-${VERSION}-x86_64-linux-gnu.tar.gz
litecoin-${VERSION}-osx64.tar.gz
litecoin-${VERSION}-osx.dmg
litecoin-${VERSION}.tar.gz
litecoin-${VERSION}-win32-setup.exe
litecoin-${VERSION}-win32.zip
litecoin-${VERSION}-win64-setup.exe
litecoin-${VERSION}-win64.zip
```
The `*-debug*` files generated by the gitian build contain debug symbols
for troubleshooting by developers. It is assumed that anyone that is interested
in debugging can run gitian to generate the files for themselves. To avoid
end-user confusion about which file to pick, as well as save storage
space *do not upload these to the litecoin.org server, nor put them in the torrent*.

- GPG-sign it, delete the unsigned file:
```
gpg --digest-algo sha256 --clearsign SHA256SUMS # outputs SHA256SUMS.asc
rm SHA256SUMS
```
(the digest algorithm is forced to sha256 to avoid confusion of the `Hash:` header that GPG adds with the SHA256 used for the files)
Note: check that SHA256SUMS itself doesn't end up in SHA256SUMS, which is a spurious/nonsensical entry.

- Upload zips and installers, as well as `SHA256SUMS.asc` from last step, to the litecoin.org server.

- Update litecoin.org version

- Announce the release:

  - litecoin-dev mailing list

  - Litecoin Core announcements list https://groups.google.com/forum/#!forum/litecoin-dev

  - blog.litecoin.org blog post

  - litecointalk.io forum announcement

  - Update title of #litecoin on Freenode IRC

  - Optionally twitter, reddit /r/Litecoin, ... but this will usually sort out itself

  - Add release notes for the new version to the directory `doc/release-notes` in git master

  - Celebrate
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36
