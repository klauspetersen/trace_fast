#!/bin/sh

function trace_fast_dbg {
    scons
    build/trace_fast |& tee $1 
}
