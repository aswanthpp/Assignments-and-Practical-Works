sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y --force-yes
sudo apt-get update

sudo apt-get install gcc-5 g++-5

sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-5 60 --slave /usr/bin/g++ g++ /usr/bin/g++-5

sudo apt-get install python python-dev mercurial bzr gdb valgrind gsl-bin libgsl0-dev libgsl0ldbl flex bison tcpdump sqlite sqlite3 libsqlite3-dev libxml2 libxml2-dev libgtk2.0-0 libgtk2.0-dev uncrustify doxygen graphviz imagemagick texlive texlive-latex-extra texlive-generic-extra texlive-generic-recommended texinfo dia texlive texlive-latex-extra texlive-extra-utils texlive-generic-recommended texi2html python-pygraphviz python-kiwi python-pygoocanvas libgoocanvas-dev python-pygccxml qt4-dev-tools wireshark --force-yes -y

wget https://www.nsnam.org/release/ns-allinone-3.26.tar.bz2

tar xjf ns-allinone-3.26.tar.bz2

cd ns-allinone-3.26

./build.py --enable-examples --enable-tests
