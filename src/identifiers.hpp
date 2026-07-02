#include "identifiers/input.hpp"
#include "identifiers/output.hpp"
#include "identifiers/set.hpp"
#include "identifiers/if.hpp"
#include "identifiers/end.hpp"
#include "identifiers/loop.hpp"
#include "identifiers/func.hpp"
#include "identifiers/run.hpp"
#include "identifiers/load.hpp"
#include "identifiers/export.hpp"

void load() {
    // Register the built-in commands available to every script.
    identifiers["out"] = output;
    identifiers["line"] = output;
    identifiers["set"] = set;
    identifiers["in"] = input;
    identifiers["if"] = _if;
    identifiers["end"] = end;
    identifiers["loop"] = loop;
    identifiers["func"] = func;
    identifiers["run"] = run;
    identifiers["load"] = load;
    identifiers["export"] = _export;
}
