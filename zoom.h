#ifndef ZOOM_H
#define ZOOM_H


struct Zoom
{
		int _x{0};
		int _y{0};
		double _scale{1.0};
		Zoom ( int x, int y, double scale ) : _x(x), _y(y), _scale(scale) {

		}

};

#endif // ZOOM_H
