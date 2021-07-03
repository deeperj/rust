#!/bin/bash

# DIR="$(dirname "$0")"
DIR="."
[ -d "$DIR/target/debug" ] && cp -r "$DIR/assets" "$DIR/target/debug"
[ -d "$DIR/target/release" ] && cp -r "$DIR/assets" "$DIR/target/release"
cargo "$0"