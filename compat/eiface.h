// Metamod 2.0 build 1411's ISmmAPI.h includes "eiface.h", which s2sdk no longer ships.
// Provide what ISmmAPI.h needs from it, matching Metamod's own s2sdk fix (d18517e).
#pragma once

#include "convar.h"

class CGlobalVars;
