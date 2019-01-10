#ifndef RGB_H
#define RGB_H

//struct zamiast klasy chuj wie po co. tak w kursie jest. TODO: struct z metodami? czy tak przystoi?
struct RGB {
		double _r;
		double _g;
		double _b;
		RGB ( double r = 0, double g = 0, double b = 0 ) : _r(r), _g(g), _b(b) {

		}
		RGB operator- ( const RGB &rhs ) {
			return RGB ( this->_r - rhs._r, this->_g - rhs._g, this->_b - rhs._b );
		}
};

#endif // RGB_H
