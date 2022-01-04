#!/bin/bash

./bake.sh

./test.sh

cd parsing
./main "$@"
cd ..