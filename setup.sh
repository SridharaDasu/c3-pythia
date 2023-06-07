#/bin/bash
if [ -d '/cvmfs' ]; then
    if [[ `uname -r` == *"el7"* ]]; then
        source /cvmfs/sft.cern.ch/lcg/views/LCG_101/x86_64-centos7-gcc11-opt/setup.sh
    elif [[ `uname -r` == *"el8"* ]]; then
        source /cvmfs/sft.cern.ch/lcg/views/LCG_101/x86_64-centos8-gcc11-opt/setup.sh
    fi
fi
if [ -d "$ROOTSYS" ]; then
    echo "Using ROOT from $ROOTSYS";
else
    echo "ROOT is needed for this to work";
fi
export PYTHIA8DATA=`pythia8-config --xmldoc`
export workdir=`dirname -- "${BASH_SOURCE[0]}"`
echo "Using workdir=$workdir";
cd $workdir
echo "Current directory set to $PWD";
