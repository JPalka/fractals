#ifndef ZOOMLIST_H
#define ZOOMLIST_H

#include <utility>
#include <vector>

#include "zoom.h"

class ZoomList {
	private:
		double _xCenter{0.0};
		double _yCenter{0.0};
		double _scale{1.0};
		int _width{0};
		int _height{0};
		std::vector<Zoom> _zooms;
	public:
		ZoomList ( int width = 600, int height = 600 );
		void add ( const Zoom &zoom );
		std::pair<double, double> doZoom ( int x, int y );
};

#endif // ZOOMLIST_H
