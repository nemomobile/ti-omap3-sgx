#!/bin/sh

OSC_API=""
OSC_PROJ=""
OSC_PKG="ti-omap3-sgx-bin"
OSC_REPO="standard"
RPM_NAMES="ti-omap3-sgx-bin"

repack() {
#	RPM_NAMES="$1"

	echo "    RE-PACKAGING $RPM_NAME"

	# Get package version and arch
	PKG_VERSION=$(rpm -q --qf %{VERSION} -p "binaries/$RPM_NAME"*rpm)
	RPM_ARCH=$(rpm -q --qf %{ARCH} -p "binaries/$RPM_NAME"-*rpm)
	echo "Version is $VERSION"

	TMP_DIR="$RPM_NAME-$PKG_VERSION-$RPM_ARCH"
	echo $TMP_DIR
	# Unpacking 
	echo "        unpacking..."
	mkdir $TMP_DIR
	cd $TMP_DIR
	rpm2cpio ../binaries/"$RPM_NAME"-*rpm | cpio -id
	cd ..

	# Re-packing to tar
	echo "        re-packaging to tarball"
	tar cjf "$TMP_DIR".tar.bz2 $TMP_DIR

	# cleaning up
	echo "        cleaning up..."
	rm -rf $TMP_DIR
}

make_bin_tars() {
	OSC_ARCH="$1"

	# OBS repo as an optional argument
	if [ "$#" -ge "1" ]; then
		OSC_REPO="$2"
	fi


	# Get binary packages
	echo "Getting rpms..."
echo	osc -A $OSC_API -q getbinaries $OSC_PROJ $OSC_PKG $OSC_REPO $OSC_ARCH
	osc -A $OSC_API -q getbinaries $OSC_PROJ $OSC_PKG $OSC_REPO $OSC_ARCH

	if [ $? -ne 0 ]; then
		echo "OSC error, exiting"
		exit 1
	fi

	for RPM_NAME in $RPM_NAMES; do
		repack $RPM_NAME
	done

	# cleaning up
	echo "Cleaning up"
	rm binaries/*rpm
}

if [ $# -ne 0 ]; then
	echo "Usage: bin-update.sh"
	echo "       Edit shell script to change list of pkgs"
	exit 1
fi

# Remove all previous tarballs
echo "Cleaning old tarballs"
rm *tar.bz2

#make_bin_tar $1 "armv5el"

#make_bin_tars "armv8el" "standard"
make_bin_tars "armv8el" "standard"
#make_bin_tars "armv8el" "thumb"
