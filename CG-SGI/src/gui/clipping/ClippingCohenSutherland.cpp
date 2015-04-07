#include "gui/clipping/ClippingCohenSutherland.h"

ClippingCohenSutherland::ClippingCohenSutherland(const double xvMin,
		const double xvMax, const double yvMin, const double yvMax) :
		Clipping(xvMin, xvMax, yvMin, yvMax) {}

ClippingCohenSutherland::~ClippingCohenSutherland() {
}

bool ClippingCohenSutherland::clipReta(Reta* const reta) const {
	return true;
}
