/* 
 * DPPDiv version 1.1b source code (https://github.com/trayc7/FDPPDIV)
 * Copyright 2009-2013
 * Tracy Heath(1,2,3) 
 * Mark Holder(1)
 * John Huelsenbeck(2)
 *
 * (1) Department of Ecology and Evolutionary Biology, University of Kansas, Lawrence, KS 66045
 * (2) Integrative Biology, University of California, Berkeley, CA 94720-3140
 * (3) email: tracyh@berkeley.edu
 *
 * Also: T Stadler, D Darriba, AJ Aberer, T Flouri, F Izquierdo-Carrasco, and A Stamatakis
 *
 * DPPDiv is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License (the file gpl.txt included with this
 * distribution or http://www.gnu.org/licenses/gpl.txt for more
 * details.
 *
 * Some of this code is from publicly available source by John Huelsenbeck and Fredrik Ronquist
 *
 */

#ifndef PARAMETER_SHAPE_H
#define PARAMETER_SHAPE_H

#include "MbVector.h"


class MbRandom;
class Model;
class Shape : public Parameter {

	public:
								Shape(MbRandom *rp, Model *mp, int nc, double lam, bool fx);
								~Shape(void); 
		Shape					&operator=(const Shape &b);
		void					clone(const Shape &b);
		double					getRate(int i) { return rates[i]; }
		MbVector<double>		&getRate(void) { return rates; }
		double					getAlphaSh(void) { return alpha; }
		double					update(double &oldLnL);
		double					lnPrior(void);
		void					print(std::ostream & o) const;
		void					updateGammaRateCats(double alph);
		std::string				writeParam(void);
							
	private:
		MbVector<double>		rates;
		double					alpha;
		int						numCats;
		double					lambda;
};

#endif
