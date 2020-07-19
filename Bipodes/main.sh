#!/bin/bash

function usage(){
  printf "Usage:\n"
  printf "\t--input_type (barcode|point-cloud) : specify which is type of the input (default is point_cloud)\n"
  printf "\t-h --help                          : print this message\n"
  printf "\n-------------\n"
  printf "Ripser's option to compute the bacodes :\n\n"
  printf "$(./ripser --help)"
}

if [ $# -eq 0 ]
then
  usage
fi

OPTS=$( getopt -o h -l help,input_type: -- "$@" )
if [ $? != 0 ]
then
  exit 1
fi

eval set -- "$OPTS"

while true ; do
  case "$1" in
    -h|--help) usage; exit 0;;
    --input_type)
        echo "You chose $2"; shift 2;;
    --) shift; break;;
  esac
done

exit 0
