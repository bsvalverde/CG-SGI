#include "gui/clipping/ClippingNichollLeeNicholl.h"

ClippingNichollLeeNicholl::ClippingNichollLeeNicholl(const double xvMin,
		const double xvMax, const double yvMin, const double yvMax) :
		Clipping(xvMin, xvMax, yvMin, yvMax) {}

ClippingNichollLeeNicholl::~ClippingNichollLeeNicholl() {}

bool ClippingNichollLeeNicholl::clipReta(Reta* const reta) const {
	return false;
}
