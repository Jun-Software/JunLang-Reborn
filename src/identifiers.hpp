#include "identifiers/input.hpp"
#include "identifiers/output.hpp"
#include "identifiers/set.hpp"

void load() {
    identifiers["out"] = output;
    identifiers["set"] = set;
    identifiers["in"] = input;
}